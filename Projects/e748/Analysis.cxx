/*****************************************************************************
 * Copyright (C) 2009-2014    this file is part of the NPTool Project        *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: Adrien MATTA  contact address: a.matta@surrey.ac.uk      *
 *                                                                           *
 * Creation Date  : march 2025                                               *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Decription:                                                               *
 * Class describing the property of an Analysis object                       *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *
 *                                                                           *
 *****************************************************************************/
#include<iostream>
using namespace std;
#include"Analysis.h"
#include"NPFunction.h"
#include"NPAnalysisFactory.h"
#include"NPDetectorManager.h"
#include"NPOptionManager.h"
#include"RootOutput.h"
#include"RootInput.h"
////////////////////////////////////////////////////////////////////////////////
Analysis::Analysis(){
}
////////////////////////////////////////////////////////////////////////////////
Analysis::~Analysis(){
}

////////////////////////////////////////////////////////////////////////////////
void Analysis::Init(){
  M2 = (TMust2Physics*) m_DetectorManager->GetDetector("M2Telescope");
  CATS = (TCATSPhysics*) m_DetectorManager->GetDetector("CATSDetector");
  ModularLeaf = (TModularLeafPhysics*) m_DetectorManager->GetDetector("ModularLeaf");
  InitOutputBranch();
  InitInputBranch();
  /* Rand = TRandom3(); */
  myReaction= new NPL::Reaction();
  myReaction->ReadConfigurationFile(NPOptionManager::getInstance()->GetReactionFile());
  DetectorNumber = 0 ;
  ThetaNormalTarget = 0 ;
  ThetaM2Surface = 0; 
  X_M2 = 0 ;
  Y_M2 = 0 ;
  Z_M2 = 0 ;
  Si_E_M2 = 0 ;
  CsI_E_M2 = 0 ; 
  Energy = 0;
  E_M2 = 0;
  Si_X_M2 = 0;
  Si_Y_M2 = 0;
  ZTarget = 0;
  TimeCorr=0;
  TargetThickness = m_DetectorManager->GetTargetThickness();
  string TargetMaterial = m_DetectorManager->GetTargetMaterial();
  // energy losses
  string light=NPL::ChangeNameToG4Standard(myReaction->GetNucleus3()->GetName());
  string beam=NPL::ChangeNameToG4Standard(myReaction->GetNucleus1()->GetName());
  LightTarget = NPL::EnergyLoss(light+"_"+TargetMaterial+".G4table","G4Table",10 );
  LightAl = NPL::EnergyLoss(light+"_Al.G4table","G4Table",10);
  LightSi = NPL::EnergyLoss(light+"_Si.G4table","G4Table",10);
  BeamTarget = NPL::EnergyLoss(beam+"_"+TargetMaterial+".G4table","G4Table",10);
  BeamMylar= NPL::EnergyLoss(beam+"_Mylar.G4table","G4Table",10);
  BeamIsobutane = EnergyLoss(beam+"_iC4H10.G4table","G4Table",10); 
}

////////////////////////////////////////////////////////////////////////////////
void Analysis::TreatEvent(){
  // Reinitiate calculated variable
  ReInitValue();

  // Calculate Run Number
  static string filename ;
  filename = RootInput::getInstance()->GetChain()->GetFile()->GetName();
  size_t minor_pos = filename.rfind("_");
  run_minor = atoi(filename.substr(minor_pos+1,1).c_str());
  filename = filename.substr(0,minor_pos);
  size_t major_pos = filename.rfind("_");
  run_major = atoi(filename.substr(major_pos+1,4).c_str());
  // Get the Init information on beam position and energy
  // and apply by hand the experimental resolution
  // This is because the beam diagnosis are not simulated
  // PPAC position resolution on target is assumed to be 1mm
  double XTarget = CATS->GetPositionOnTarget().X();
  double YTarget = CATS->GetPositionOnTarget().Y();

  TVector3 BeamDirection = CATS->GetBeamDirection();
  // Beam energy is measured using F3 and F2 plastic TOF
  //double BeamEnergy= myReaction-> GetBeamEnergy()* MeV;
  //////////////////////////// LOOP on MUST2 Hit //////////////////
  for(unsigned int countMust2 = 0 ; countMust2 < M2->Si_E.size() ; countMust2++){ 
    /*   //Part 0 : Get the usefull Data */
    // MUST2 */
    int X = M2->Si_X[countMust2]; 
    int Y = M2->Si_Y[countMust2]; 
    int TelescopeNumber = M2->TelescopeNumber[countMust2]; 
    Si_X_M2 = X ;
    Si_Y_M2 = Y ;

    if(TelescopeNumber<9){
      DetectorNumber = TelescopeNumber ;

      /* // Part 1 : Impact Angle */
      ThetaM2Surface = 0;
      ThetaNormalTarget = 0;
      if(XTarget>-1000 && YTarget>-1000){
        TVector3 BeamImpact(XTarget,YTarget,0);
        TVector3 HitDirection = M2 -> GetPositionOfInteraction(countMust2) - BeamImpact ;
        ThetaLab = HitDirection.Angle( BeamDirection );

        ThetaM2Surface = HitDirection.Angle(- M2 -> GetTelescopeNormal(countMust2) );
        ThetaNormalTarget = HitDirection.Angle( TVector3(0,0,1) ) ;
        X_M2 = M2 -> GetPositionOfInteraction(countMust2).X() ;
        Y_M2 = M2 -> GetPositionOfInteraction(countMust2).Y() ;
        Z_M2 = M2 -> GetPositionOfInteraction(countMust2).Z() ;

        // Beam Energy from Cav Time of Flight //

        // Beam speed from Beam Energy

        //   double BeamSpeed =  10.8727 + ModularLeaf->GetCalibratedValue("T_CATS1_CAV")*0.276825; // mm/ns
        //double BeamSpeed =  5.17952 + ModularLeaf->GetCalibratedValue("T_CATS1_CAV")*0.305315; // mm/ns
        //double BeamSpeed =  11.0476 + ModularLeaf->GetCalibratedValue("T_CATS1_CAV")*0.278917; // mm/ns
        //double BeamSpeed =  7.20255 + ModularLeaf->GetCalibratedValue("T_CATS1_CAV")*0.293392; // mm/ns

        double BeamSpeed =  20.0747+ ModularLeaf->GetCalibratedValue("T_CATS1_CAV")*0.237811; // mm/ns

        // Beam Energy before CATS1
        static double c2 = 299.792458*299.792458;// mm/ns 
        double gamma = 1./sqrt(1-BeamSpeed*BeamSpeed/c2);
        BeamEnergy= 11200.962140*(gamma-1);
        double BeamAngle= BeamDirection.Angle(TVector3(0,0,1));
        double gammaCav = (BeamEnergy+11200.962140) / 11200.962140 ;
        double BeamSpeedCav = sqrt(c2*(1-1/(gammaCav*gammaCav)));
  
        // Beam Energy and speed after CATS1
        double BeamEnergyC1 = BeamMylar.Slow(BeamEnergy,1.2*micrometer,BeamAngle); 
        BeamEnergyC1 = BeamIsobutane.Slow(BeamEnergyC1,cm/3.,BeamAngle);
        BeamEnergyC1 = BeamMylar.Slow(BeamEnergyC1,0.9*micrometer,BeamAngle); 
        BeamEnergyC1 = BeamIsobutane.Slow(BeamEnergyC1,cm/3,BeamAngle);
        BeamEnergyC1 = BeamMylar.Slow(BeamEnergyC1,0.9*micrometer,BeamAngle); 
        BeamEnergyC1 = BeamIsobutane.Slow(BeamEnergyC1,cm/3.,BeamAngle);
        BeamEnergyC1 = BeamMylar.Slow(BeamEnergyC1,1.2*micrometer,BeamAngle); 
        double gammaC1 = (BeamEnergyC1+11200.962140) / 11200.962140 ;
        double BeamSpeedC1 = sqrt(c2*(1-1/(gammaC1*gammaC1)));
        TVector3 C1toC2 =  TVector3(CATS->PositionX[1],CATS->PositionY[1],CATS->PositionZ[1]) 
          -  TVector3(CATS->PositionX[0],CATS->PositionY[0],CATS->PositionZ[0]) ;
        TimeCorr = C1toC2.Mag()/BeamSpeedC1;

        // Beam Energy and speed after CATS2
        double BeamEnergyC2 = BeamMylar.Slow(BeamEnergyC1,1.2*micrometer,BeamAngle); 
        BeamEnergyC2 = BeamIsobutane.Slow(BeamEnergyC2,cm/3.,BeamAngle);
        BeamEnergyC2 = BeamMylar.Slow(BeamEnergyC2,0.9*micrometer,BeamAngle); 
        BeamEnergyC2 = BeamIsobutane.Slow(BeamEnergyC2,cm/3,BeamAngle);
        BeamEnergyC2 = BeamMylar.Slow(BeamEnergyC2,0.9*micrometer,BeamAngle); 
        BeamEnergyC2 = BeamIsobutane.Slow(BeamEnergyC2,cm/3.,BeamAngle);
        BeamEnergyC2 = BeamMylar.Slow(BeamEnergyC2,1.2*micrometer,BeamAngle); 

        double gammaC2 = (BeamEnergyC2+11200.962140) / 11200.962140; 
        double BeamSpeedC2 = sqrt(c2*(1-1/(gammaC2*gammaC2)));
        TVector3 C2toTarget =  BeamImpact-TVector3(CATS->PositionX[1],CATS->PositionY[1],CATS->PositionZ[1]);
        TimeCorr += C2toTarget.Mag()/BeamSpeedC2;
        // slow down beam inside the target
        BeamEnergy = BeamTarget.Slow(BeamEnergyC2,TargetThickness*0.5,BeamDirection.Angle(TVector3(0,0,1))); 
        myReaction->SetBeamEnergy(BeamEnergy);   


        ParticleLength=HitDirection.Mag();

      }


      else{
        BeamDirection = TVector3(-1000,-1000,-1000);
        ThetaM2Surface    = -1000  ;
        ThetaNormalTarget = -1000  ;
      }

      /*      // Part 2 : Impact Energy */
      Energy = ELab = E_M2 = 0;
      Si_E_M2 = M2->Si_E[countMust2];
      CsI_E_M2= M2->CsI_E[countMust2];

      /*         // if CsI */
      /*         /1* if(CsI_E_M2>0 ){ *1/ */
      /*         /1*   // The energy in CsI is calculate form dE/dx Table because *1/ */ 
      /*         /1*   // 20um resolution is poor *1/ */
      /*         /1*   Energy = *1/ */ 
      /*         /1*     LightSi.EvaluateEnergyFromDeltaE(Si_E_M2,300*micrometer, *1/ */
      /*         /1*         ThetaM2Surface, 0.01*MeV, *1/ */ 
      /*         /1*         450.*MeV,0.001*MeV ,1000); *1/ */
      /*         /1*   E_M2=CsI_E_M2; *1/ */
      /*         /1* } *1/ */

      /*         /1* else *1/ */




      Energy = Si_E_M2;

      E_M2 += Si_E_M2;

      /*         // Evaluate energy using the thickness */ 
      ELab = LightAl.EvaluateInitialEnergy( Energy,0.4*micrometer , ThetaM2Surface);
      /*         // Target Correction */
      ELab   = LightTarget.EvaluateInitialEnergy( ELab ,TargetThickness/2., ThetaNormalTarget);

      /*         // Part 3 : Excitation Energy Calculation */
      Ex = myReaction -> ReconstructRelativistic( ELab , ThetaLab );


      /*         // Part 4 : Theta CM Calculation */
      ThetaCM  = myReaction -> EnergyLabToThetaCM( ELab , ThetaLab)/deg;
      ThetaLab=ThetaLab/deg;

    }
  }//end loop MUST2
}

////////////////////////////////////////////////////////////////////////////////
void Analysis::End(){
}

////////////////////////////////////////////////////////////////////////////////
void Analysis::InitOutputBranch() {
  RootOutput::getInstance()->GetTree()->Branch("X_M2",&X_M2,"X_M2/D");
  RootOutput::getInstance()->GetTree()->Branch("Y_M2",&Y_M2,"Y_M2/D");
  RootOutput::getInstance()->GetTree()->Branch("Ex",&Ex,"Ex/D");
  RootOutput::getInstance()->GetTree()->Branch("ThetaLab",&ThetaLab,"ThetaLab/D");
  RootOutput::getInstance()->GetTree()->Branch("ThetaCM",&ThetaCM,"ThetaCM/D");
  /* RootOutput::getInstance()->GetTree()->Branch("OriginalThetaLab",&OriginalThetaLab,"OriginalThetaLab/D"); */
  RootOutput::getInstance()->GetTree()->Branch("ELab",&ELab,"ELab/D"); 
  RootOutput::getInstance()->GetTree()->Branch("TimeCorr",&TimeCorr,"TimeCorr/D"); 
  RootOutput::getInstance()->GetTree()->Branch("BeamLength",&BeamLength,"BeamLength/D"); 
  RootOutput::getInstance()->GetTree()->Branch("ParticleLength",&ParticleLength,"ParticleLength/D"); 
  RootOutput::getInstance()->GetTree()->Branch("BeamEnergy",&BeamEnergy,"BeamEnergy/D"); 


  RootOutput::getInstance()->GetTree()->Branch("GATCONF",&vGATCONF,"GATCONF/s");
  RootOutput::getInstance()->GetTree()->Branch("RunMajor",&run_major,"RunMajor/I");
  RootOutput::getInstance()->GetTree()->Branch("RunMinor",&run_minor,"RunMinor/I");

  /*  RootOutput::getInstance()->GetTree()->Branch("ADC_CHIO_V15",&vADC_CHIO_V15,"ADC_CHIO_V15/s");
      RootOutput::getInstance()->GetTree()->Branch("ADC_VOIE_29",&vADC_VOIE_29,"ADC_VOIE_29/s");
      RootOutput::getInstance()->GetTree()->Branch("CHIO",&vCHIO,"CHIO/s");
      RootOutput::getInstance()->GetTree()->Branch("CONFDEC",&vCONFDEC,"CONFDEC/s");
      RootOutput::getInstance()->GetTree()->Branch("CONFDEC_AGAVA",&vCONFDEC_AGAVA,"CONFDEC_AGAVA/s");
      RootOutput::getInstance()->GetTree()->Branch("DATATRIG",&vDATATRIG,"DATATRIG/s");
      RootOutput::getInstance()->GetTree()->Branch("DATATRIG_CHIO",&vDATATRIG_CHIO,"DATATRIG_CHIO/s");
      RootOutput::getInstance()->GetTree()->Branch("E1D6",&vE1D6,"E1D6/s");
      RootOutput::getInstance()->GetTree()->Branch("E2D6",&vE2D6,"E2D6/s");
      RootOutput::getInstance()->GetTree()->Branch("ED4",&vED4,"ED4/s");
      RootOutput::getInstance()->GetTree()->Branch("EXL_HF",&vEXL_HF,"EXL_HF/s");
      RootOutput::getInstance()->GetTree()->Branch("GALD4X",&vGALD4X,"GALD4X/s");
      RootOutput::getInstance()->GetTree()->Branch("GALD4Y",&vGALD4Y,"GALD4Y/s");
      RootOutput::getInstance()->GetTree()->Branch("QCaviar",&vQCaviar,"QCaviar/s");
      RootOutput::getInstance()->GetTree()->Branch("QPlast",&vQPlast,"QPlast/s");
      RootOutput::getInstance()->GetTree()->Branch("TCAVHF",&vTCAVHF,"TCAVHF/s");
      RootOutput::getInstance()->GetTree()->Branch("TE1D6CAV",&vTE1D6CAV,"TE1D6CAV/s");
      RootOutput::getInstance()->GetTree()->Branch("TE1D6GAL",&vTE1D6GAL,"TE1D6GAL/s");
      RootOutput::getInstance()->GetTree()->Branch("TE1D6HF",&vTE1D6HF,"TE1D6HF/s");
      RootOutput::getInstance()->GetTree()->Branch("TED4HF",&vTED4HF,"TED4HF/s");
      RootOutput::getInstance()->GetTree()->Branch("TGALD4HF",&vTGALD4HF,"TGALD4HF/s");
      RootOutput::getInstance()->GetTree()->Branch("T_CATS1_2",&vT_CATS1_2,"T_CATS1_2/s");
      RootOutput::getInstance()->GetTree()->Branch("T_CATS1_CAV",&vT_CATS1_CAV,"T_CATS1_CAV/s");
      RootOutput::getInstance()->GetTree()->Branch("T_MUVI_CATS1",&vT_MUVI_CATS1,"T_MUVI_CATS1/s");
      RootOutput::getInstance()->GetTree()->Branch("T_PL_CATS1",&vT_PL_CATS1,"T_PL_CATS1/s");
      RootOutput::getInstance()->GetTree()->Branch("T_PL_CATS2",&vT_PL_CATS2,"T_PL_CATS2/s");
      RootOutput::getInstance()->GetTree()->Branch("T_PL_CHIO",&vT_PL_CHIO,"T_PL_CHIO/s");
      RootOutput::getInstance()->GetTree()->Branch("T_PLchCATS1",&vT_PLchCATS1,"T_PLchCATS1/s");
      */
}

////////////////////////////////////////////////////////////////////////////////
void Analysis::InitInputBranch(){
  /* RootInput:: getInstance()->GetChain()->SetBranchStatus("InitialConditions",true ); */
  /* RootInput:: getInstance()->GetChain()->SetBranchStatus("fIC_*",true ); */
  /* RootInput:: getInstance()->GetChain()->SetBranchStatus("InitialConditions",true ); */

  RootInput:: getInstance()->GetChain()->SetBranchAddress("GATCONF",&vGATCONF);
  /* RootInput:: getInstance()->GetChain()->SetBranchAddress("ADC_CHIO_V15",&vADC_CHIO_V15); 
     RootInput:: getInstance()->GetChain()->SetBranchAddress("ADC_VOIE_29",&vADC_VOIE_29);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("CHIO",&vCHIO);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("CONFDEC",&vCONFDEC);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("CONFDEC_AGAVA",&vCONFDEC_AGAVA);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("DATATRIG",&vDATATRIG);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("DATATRIG_CHIO",&vDATATRIG_CHIO);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("E1D6",&vE1D6);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("E2D6",&vE2D6);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("ED4",&vED4);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("EXL_HF",&vEXL_HF);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("GALD4X",&vGALD4X);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("GALD4Y",&vGALD4Y);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("QCaviar",&vQCaviar);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("QPlast",&vQPlast);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("TCAVHF",&vTCAVHF);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("TE1D6CAV",&vTE1D6CAV);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("TE1D6GAL",&vTE1D6GAL);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("TE1D6HF",&vTE1D6HF);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("TED4HF",&vTED4HF);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("TGALD4HF",&vTGALD4HF);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("T_CATS1_2",&vT_CATS1_2);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("T_CATS1_CAV",&vT_CATS1_CAV);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("T_MUVI_CATS1",&vT_MUVI_CATS1);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("T_PL_CATS1",&vT_PL_CATS1);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("T_PL_CATS2",&vT_PL_CATS2);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("T_PL_CHIO",&vT_PL_CHIO);
     RootInput:: getInstance()->GetChain()->SetBranchAddress("T_PLchCATS1",&vT_PLchCATS1);
     */
}

////////////////////////////////////////////////////////////////////////////////     
void Analysis::ReInitValue(){
  Ex = -1000 ;
  ELab = -1000;
  ThetaLab = -1000;
  ThetaCM = -1000;
  OriginalThetaLab = -1000;
  OriginalELab = -1000;
  TimeCorr=-1000;
  BeamLength=-1000;
  ParticleLength=-1000;
  run_minor=-1000;
  run_major=-1000;
  BeamEnergy=-1000;
}

////////////////////////////////////////////////////////////////////////////////
//            Construct Method to be pass to the DetectorFactory              //
////////////////////////////////////////////////////////////////////////////////
NPL::VAnalysis* Analysis::Construct(){
  return (NPL::VAnalysis*) new Analysis();
}

////////////////////////////////////////////////////////////////////////////////
//            Registering the construct method to the factory                 //
////////////////////////////////////////////////////////////////////////////////
extern "C"{
  class proxy{
    public:
      proxy(){
        NPL::AnalysisFactory::getInstance()->SetConstructor(Analysis::Construct);
      }
  };

  proxy p;
}


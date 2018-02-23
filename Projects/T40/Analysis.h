#ifndef Analysis_h 
#define Analysis_h
/*****************************************************************************
 * Copyright (C) 2009-2014    this file is part of the NPTool Project        *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: Adrien MATTA  contact address: a.matta@surrey.ac.uk      *
 *                                                                           *
 * Creation Date  : march 2015                                               *
 * Last update    : December 2016 [m.moukaddam@surrey.ac.uk]                 *
 *---------------------------------------------------------------------------*
 * Decription:                                                               *
 * Class describing the property of an Analysis object                       *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *
 *                                                                           *
 *****************************************************************************/
//NPTOOL
#include "NPVAnalysis.h"
#include "TTiaraHyballPhysics.h"
#include "TTiaraBarrelPhysics.h"
#include "TFPDTamuPhysics.h"
#include "TGeTAMUPhysics.h"
#include "TMDMPhysics.h"
#include "TInitialConditions.h"
#include "NPEnergyLoss.h"
#include "NPReaction.h"
//ROOT
#include <TVector3.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TObject.h>

namespace NPL { class VDetector; }


class Analysis: public NPL::VAnalysis{
  public:
    Analysis();
    ~Analysis();

  public: 
    void Init();
    void TreatEvent();
    void End();
    void ReInitValue();
    void InitOutputBranch();
    void InitInputBranch();
    static NPL::VAnalysis* Construct();

  private:
  double Ex;
//by Shuya 170703
  double Ex_Hyball;
  double Ex_Barrel;

  double ELab;
//by Shuya 171206
  double ELab_Hyball;
  double ELab_Barrel;

  double ThetaLab;
//by Shuya 171206
  double ThetaLab_Hyball;
  double ThetaLab_Barrel;

  double ThetaCM;
  double TiaraIMX;
  double TiaraIMY;
  double TiaraIMZ;
  TInitialConditions* Initial;
  NPL::Reaction* myReaction;
  bool LightParticleDetected;
//by Shuya 171019
  double PhiLab;
//by Shuya 171206
  double PhiLab_Hyball;
  double PhiLab_Barrel;

// GAC 171020
	double ThetaXLab;
	double ThetaYLab;

 
  //	Energy loss table: the G4Table are generated by the simulation
  NPL::EnergyLoss LightTarget;
  NPL::EnergyLoss LightAl ;
  NPL::EnergyLoss LightSi; 
  NPL::EnergyLoss BeamTarget ; 
//by Shuya 170530
  NPL::EnergyLoss LightCBacking; 

  double OriginalBeamEnergy;
  double FinalBeamEnergy;

  TTiaraHyballPhysics* TH;
  TTiaraBarrelPhysics* TB;  
  TFPDTamuPhysics* TF;
  TGeTAMUPhysics* TG;
	TMDMPhysics* MDM;
	bool MDM_in_file; //!

  TRandom *Rand ;
	double ThetaNormalTarget  ;
	double ThetaTHSurface ;
	double ThetaTBSurface ;
	double Si_E_TH  ;
	double Si_E_InnerTB;
	double Si_E_OuterTB;
	double Si_E_TB  ;
	double Energy ;
	double TargetThickness ;

	double Original_ThetaLab;
	double Original_ELab;

	double XTarget ;
	double YTarget ;
	TVector3 BeamDirection ;
  
  //Gamma
  double GammaSinglesE;
  
  //FPD
	static const Int_t kNumAw = 4; // number of wires
  double Delta_E      ;
  double Micro1_E_row1 ;   
  //by Shuya 170912
  double Micro1_E_col4_sum ; 
  double Micro1_E_row1_2;
  double Micro2_E      ;
	double Micro2_E_row1_2;
  double Plast_E      ;
	double Aw_X[kNumAw] ;
	double Aw_Z[kNumAw] ;
	double Aw_Theta1_2  ; // Theta calculated from wire 1 & wire 2
	double Aw_ThetaFit  ; // Theta calculated from FITTING all wires
	double Aw_ThetaFit_R2; // Goodness of fit value of theta from fitting
  //by Shuya 170516
  //by Shuya 170912
  double Micro1_E_col1_sum ; 
  double Micro1_E_col2_sum ; 
  double Micro1_E_col3_sum ; 
  double Micro1_E_col5_sum ; 
  double Micro1_E_col6_sum ; 
  double Micro1_E_col7_sum ; 
  double Micro2_E_col1_sum ; 
  double Micro2_E_col2_sum ; 
  double Micro2_E_col3_sum ; 
  double Micro2_E_col4_sum ; 
  double Micro2_E_col5_sum ; 
  double Micro2_E_col6_sum ; 
  double Micro2_E_col7_sum ; 
  //by Shuya 170912
  double Micro1_E_col1_mult ; 
  double Micro1_E_col2_mult ; 
  double Micro1_E_col3_mult ; 
  double Micro1_E_col4_mult ; 
  double Micro1_E_col5_mult ; 
  double Micro1_E_col6_mult ; 
  double Micro1_E_col7_mult ; 
  double Micro2_E_col1_mult ; 
  double Micro2_E_col2_mult ; 
  double Micro2_E_col3_mult ; 
  double Micro2_E_col4_mult ; 
  double Micro2_E_col5_mult ; 
  double Micro2_E_col6_mult ; 
  double Micro2_E_col7_mult ; 
	
  //TACS
  double TacSiGeOR ;
  double TacSiMicro ;
	double TacSiMicro_E;
	double TacSiMicro_dE;
  double TacSiPlastLeft ;
  double TacSiPlastRight ;
  
	// Other
	int RunNumber;
	// by Shuya 170524
	Long_t 	EntryNumber;
	Long_t	entry;
	string	currentfilename;

};
#endif

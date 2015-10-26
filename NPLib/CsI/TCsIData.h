#ifndef __CSIDATA__
#define __CSIDATA__
/*****************************************************************************
 * Copyright (C) 2009-2014    this file is part of the NPTool Project        *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author:    contact address:                                      *
 *                                                                           *
 * Creation Date  :                                                          *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Decription:                                                               *
 *                                                                           *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *
 *****************************************************************************/
#include <vector>

#include "TObject.h"
using namespace std ;


class TCsIData : public TObject {
 private:
   // Energy 
   vector<short>   fCsI_E_Number;
   vector<double>  fCsI_E_Energy;   
   // Time
   vector<short>   fCsI_T_Number;
   vector<double>  fCsI_T_Time;
   
 public:
   TCsIData();
   virtual ~TCsIData();

   void   Clear();
   void   Clear(const Option_t*) {};
   void   Dump() const;

   /////////////////////           GETTERS           ////////////////////////
   // Energy
   unsigned int   GetEnergyMult()   {return fCsI_E_Number.size();}
   int            GetENumber(int i) {return fCsI_E_Number[i];}
   double         GetEEnergy(int i) {return fCsI_E_Energy[i];}
   // Time 
   unsigned int   GetTimeMult()     {return fCsI_T_Number.size();}
   int            GetTNumber(int i) {return fCsI_T_Number[i];}
   double         GetTTime(int i)   {return fCsI_T_Time[i];}

   /////////////////////           SETTERS           ////////////////////////
   // Energy
   void     SetENumber(int N)    {fCsI_E_Number.push_back(N);}
   void     SetEEnergy(double E) {fCsI_E_Energy.push_back(E);}
   // time
   void     SetTNumber(int N)    {fCsI_T_Number.push_back(N);}
   void     SetTTime(double T)   {fCsI_T_Time.push_back(T);}

   ClassDef(TCsIData,1)  // CsIData structure
};

#endif
#ifndef NPSPECTRASERVER_H
#define NPSPECTRASERVER_H
/*****************************************************************************
 * Copyright (C) 2009-2016   this file is part of the NPTool Project         *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: Adrien Matta   contact address: matta@lpccaen.in2p3.fr   *
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
 *                                                                           *
 *****************************************************************************/

#include "TSocket.h"
#include "TServerSocket.h"
#include "TMonitor.h"
#include "TMessage.h"
#include "TList.h"
#include "TH1.h"
#include "NPDeltaSpectra.h"
#include <string>
#include <map>

namespace NPL{
  class SpectraServer{
    public:
      static SpectraServer* getInstance();
      void Destroy();
 
    private:
      SpectraServer();
      ~SpectraServer();

    private:
      static SpectraServer* instance;

    public:
      void HandleSocket(TSocket* s);
      void AddSpectra(TH1* h);
      void FillSpectra(std::string name,double valx);
      void FillSpectra(std::string name,double valx, double valy);
      void CheckRequest();

    private:
      bool m_stop;
      TServerSocket* m_Server;     
      TMonitor* m_Monitor;     
      std::map<TSocket*,NPL::DeltaSpectra > m_Delta;
      TList* m_Sockets;
      TList* m_Spectra;
  };
}
#endif

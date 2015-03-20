#include<iostream>
#include<fstream>
#include<dlfcn.h>
#include<dirent.h>
#include"NPDetectorFactory.h"

int main(int argc , char** argv){
  // Generate the Class list with Token for autoloading of the Detector classes
  DIR *dir;
  struct dirent *ent;
  string path = getenv("NPTOOL");
  path += "/NPLib/lib";
  string lib;
  if ((dir = opendir (path.c_str())) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      lib= ent->d_name ;
      if(lib.find("lib")!=std::string::npos)
        dlopen(lib.c_str(),RTLD_LAZY);
    }
    closedir (dir);
  }

  NPA::DetectorFactory::getInstance()->CreateClassList("DetectorClassList.txt");

  // Generate the liblist file for backward compatibility
  std::ofstream liblistfile("liblist");
  liblistfile << "#! /bin/bash " << std::endl;
  liblistfile << "#" << std::endl; 
  liblistfile << "# WARNING:" << std::endl; 
  liblistfile << "#   This file is automatically generated when NPLib libraries are built through the make command." << std::endl; 
  liblistfile << "#   If you modify this file by hand, changes won't persist the next time you compile NPLib." << std::endl; 
  liblistfile << "#" << std::endl; 
  liblistfile << "echo -L" << path << " \\" <<std::endl; 
  string LibName;
  if ((dir = opendir (path.c_str())) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      LibName= ent->d_name ;
      if(LibName.find("lib")!=std::string::npos){
        std::string remword = "lib";
        size_t pos;
        if((pos=LibName.find(remword))!=std::string::npos){
          LibName.swap(LibName.erase(pos,remword.length()));
        }

        remword = ".so";
        if((pos=LibName.find(remword))!=std::string::npos){
          LibName.swap(LibName.erase(pos,remword.length()));
        }

        remword = ".dylib";
        if((pos=LibName.find(remword))!=std::string::npos){
          LibName.swap(LibName.erase(pos,remword.length()));
        }

        liblistfile << "-l" << LibName <<" \\" <<std::endl;
      }
    }
    closedir (dir);
  }

  // Generate the inc dir file for backward compatiblity
  // Create the list of custom detector from argument
  std::string detlist="";
  for(unsigned int i = 1 ; i < argc ; i++){
    detlist+=argv[i];
    detlist+=" ";
  }

  std::ofstream DetectorList("DetectorList.inc"); 
  DetectorList << "// Waring " << std::endl;
  DetectorList << "//    This file is automatically generated by the configure script." << std::endl;
  DetectorList << "//    If you modify this file by hand, changes won't persist the next time you compile NPLib."<<std::endl;
  DetectorList << "//"<<std::endl;

  std::string folderName;
  path = getenv("NPTOOL");
  path+="/NPLib";
    if ((dir = opendir (path.c_str())) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        if(ent->d_type == DT_DIR){
          folderName = ent->d_name ;
          if(std::strncmp(folderName.c_str(),".",1)!=0 && folderName!="Core"  
              && folderName!="Physics"  && folderName!="InitialConditions"
              && folderName!="InteractionCoordinates" && folderName!="scripts"
              && folderName!="lib" && folderName!="include"  
              && folderName!="Utility" && folderName!="bin"
              && folderName!="CMakeFiles"){
            if(detlist.length()==0 || detlist.find(folderName)!=std::string::npos){
            // Set Upper Case
            std::locale loc;
            for (std::string::size_type i=0; i<folderName.length(); ++i)
              folderName[i]=std::toupper(folderName[i],loc);
            DetectorList<<"#define INC_" << folderName << std::endl;
            }
          }
        } 
      } 
    }

  // Generate the target file for backward compatiblity
  std::ofstream TargetList(".detector_libs"); 
    if ((dir = opendir (path.c_str())) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        if(ent->d_type == DT_DIR){
          folderName = ent->d_name ;
          if(std::strncmp(folderName.c_str(),".",1)!=0 && folderName!="Core"  
              && folderName!="Physics"  && folderName!="InitialConditions"
              && folderName!="InteractionCoordinates" && folderName!="scripts"
              && folderName!="lib" && folderName!="include"  
              && folderName!="Utility" && folderName!="bin"
              && folderName!="CMakeFiles"){
            if(detlist.length()==0 || detlist.find(folderName)!=std::string::npos){
            // Set Upper Case
            std::locale loc;
            for (std::string::size_type i=0; i<folderName.length(); ++i)
              folderName[i]=std::tolower(folderName[i],loc);
            TargetList << folderName << " ";
            }
          }
        } 
      } 
    }

  //  Change all the .so to .dylib for Mac Os X in the installed rootmap    
  path = getenv("NPTOOL");
  path += "/NPLib/*/*.rootmap";
  std::string command = "sed -i '' -e 's/.so/.dylib/g' "+path;  
  system(command.c_str());   
    
    return 0;
}

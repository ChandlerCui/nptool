//
// File generated by rootcint at Thu Feb 27 23:14:06 2014

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME TSiLiDataDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "TSiLiDataDict.h"

#include "TCollectionProxyInfo.h"
#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void TSiLiData_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void *new_TSiLiData(void *p = 0);
   static void *newArray_TSiLiData(Long_t size, void *p);
   static void delete_TSiLiData(void *p);
   static void deleteArray_TSiLiData(void *p);
   static void destruct_TSiLiData(void *p);
   static void streamer_TSiLiData(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TSiLiData*)
   {
      ::TSiLiData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TSiLiData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TSiLiData", ::TSiLiData::Class_Version(), "./TSiLiData.h", 29,
                  typeid(::TSiLiData), DefineBehavior(ptr, ptr),
                  &::TSiLiData::Dictionary, isa_proxy, 0,
                  sizeof(::TSiLiData) );
      instance.SetNew(&new_TSiLiData);
      instance.SetNewArray(&newArray_TSiLiData);
      instance.SetDelete(&delete_TSiLiData);
      instance.SetDeleteArray(&deleteArray_TSiLiData);
      instance.SetDestructor(&destruct_TSiLiData);
      instance.SetStreamerFunc(&streamer_TSiLiData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TSiLiData*)
   {
      return GenerateInitInstanceLocal((::TSiLiData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TSiLiData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
TClass *TSiLiData::fgIsA = 0;  // static to hold class pointer

//______________________________________________________________________________
const char *TSiLiData::Class_Name()
{
   return "TSiLiData";
}

//______________________________________________________________________________
const char *TSiLiData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSiLiData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TSiLiData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSiLiData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void TSiLiData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSiLiData*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *TSiLiData::Class()
{
   if (!fgIsA) fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSiLiData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
void TSiLiData::Streamer(TBuffer &R__b)
{
   // Stream an object of class TSiLiData.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      {
         vector<short> &R__stl =  fSiLi_E_Number;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            short R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<double> &R__stl =  fSiLi_E_Energy;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            double R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<short> &R__stl =  fSiLi_T_Number;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            short R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<double> &R__stl =  fSiLi_T_Time;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            double R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b.CheckByteCount(R__s, R__c, TSiLiData::IsA());
   } else {
      R__c = R__b.WriteVersion(TSiLiData::IsA(), kTRUE);
      TObject::Streamer(R__b);
      {
         vector<short> &R__stl =  fSiLi_E_Number;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<short>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<double> &R__stl =  fSiLi_E_Energy;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<double>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<short> &R__stl =  fSiLi_T_Number;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<short>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<double> &R__stl =  fSiLi_T_Time;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<double>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b.SetByteCount(R__c, kTRUE);
   }
}

//______________________________________________________________________________
void TSiLiData::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class TSiLiData.
      TClass *R__cl = ::TSiLiData::IsA();
      if (R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__insp.GetParent(), "fSiLi_E_Number", (void*)&fSiLi_E_Number);
      R__insp.InspectMember("vector<short>", (void*)&fSiLi_E_Number, "fSiLi_E_Number.", false);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "fSiLi_E_Energy", (void*)&fSiLi_E_Energy);
      R__insp.InspectMember("vector<double>", (void*)&fSiLi_E_Energy, "fSiLi_E_Energy.", false);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "fSiLi_T_Number", (void*)&fSiLi_T_Number);
      R__insp.InspectMember("vector<short>", (void*)&fSiLi_T_Number, "fSiLi_T_Number.", false);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "fSiLi_T_Time", (void*)&fSiLi_T_Time);
      R__insp.InspectMember("vector<double>", (void*)&fSiLi_T_Time, "fSiLi_T_Time.", false);
      TObject::ShowMembers(R__insp);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TSiLiData(void *p) {
      return  p ? new(p) ::TSiLiData : new ::TSiLiData;
   }
   static void *newArray_TSiLiData(Long_t nElements, void *p) {
      return p ? new(p) ::TSiLiData[nElements] : new ::TSiLiData[nElements];
   }
   // Wrapper around operator delete
   static void delete_TSiLiData(void *p) {
      delete ((::TSiLiData*)p);
   }
   static void deleteArray_TSiLiData(void *p) {
      delete [] ((::TSiLiData*)p);
   }
   static void destruct_TSiLiData(void *p) {
      typedef ::TSiLiData current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TSiLiData(TBuffer &buf, void *obj) {
      ((::TSiLiData*)obj)->::TSiLiData::Streamer(buf);
   }
} // end of namespace ROOT for class ::TSiLiData

namespace ROOT {
   void vectorlEdoublegR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void vectorlEdoublegR_Dictionary();
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector.dll", 0,
                  typeid(vector<double>), DefineBehavior(ptr, ptr),
                  0, &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void vectorlEdoublegR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   void vectorlEshortgR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void vectorlEshortgR_Dictionary();
   static void *new_vectorlEshortgR(void *p = 0);
   static void *newArray_vectorlEshortgR(Long_t size, void *p);
   static void delete_vectorlEshortgR(void *p);
   static void deleteArray_vectorlEshortgR(void *p);
   static void destruct_vectorlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<short>*)
   {
      vector<short> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<short>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<short>", -2, "vector.dll", 0,
                  typeid(vector<short>), DefineBehavior(ptr, ptr),
                  0, &vectorlEshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<short>) );
      instance.SetNew(&new_vectorlEshortgR);
      instance.SetNewArray(&newArray_vectorlEshortgR);
      instance.SetDelete(&delete_vectorlEshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEshortgR);
      instance.SetDestructor(&destruct_vectorlEshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<short> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<short>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void vectorlEshortgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const vector<short>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEshortgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<short> : new vector<short>;
   }
   static void *newArray_vectorlEshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<short>[nElements] : new vector<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEshortgR(void *p) {
      delete ((vector<short>*)p);
   }
   static void deleteArray_vectorlEshortgR(void *p) {
      delete [] ((vector<short>*)p);
   }
   static void destruct_vectorlEshortgR(void *p) {
      typedef vector<short> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<short>

/********************************************************
* TSiLiDataDict.cxx
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableTSiLiDataDict();

extern "C" void G__set_cpp_environmentTSiLiDataDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("TSiLiData.h");
  G__cpp_reset_tagtableTSiLiDataDict();
}
#include <new>
extern "C" int G__cpp_dllrevTSiLiDataDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* TSiLiData */
static int G__TSiLiDataDict_168_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   TSiLiData* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new TSiLiData[n];
     } else {
       p = new((void*) gvp) TSiLiData[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new TSiLiData;
     } else {
       p = new((void*) gvp) TSiLiData;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TSiLiData*) G__getstructoffset())->Clear();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 104, (long) ((TSiLiData*) G__getstructoffset())->GetEnergyMult());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((TSiLiData*) G__getstructoffset())->GetENumber((int) G__int(libp->para[0])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((TSiLiData*) G__getstructoffset())->GetEEnergy((int) G__int(libp->para[0])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 104, (long) ((TSiLiData*) G__getstructoffset())->GetTimeMult());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((TSiLiData*) G__getstructoffset())->GetTNumber((int) G__int(libp->para[0])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((TSiLiData*) G__getstructoffset())->GetTTime((int) G__int(libp->para[0])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TSiLiData*) G__getstructoffset())->SetENumber((int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TSiLiData*) G__getstructoffset())->SetEEnergy((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TSiLiData*) G__getstructoffset())->SetTNumber((int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TSiLiData*) G__getstructoffset())->SetTTime((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) TSiLiData::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) TSiLiData::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) TSiLiData::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      TSiLiData::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_22(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((TSiLiData*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_23(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) TSiLiData::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_24(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) TSiLiData::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_25(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) TSiLiData::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__TSiLiDataDict_168_0_26(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) TSiLiData::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__TSiLiDataDict_168_0_27(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   TSiLiData* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new TSiLiData(*(TSiLiData*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef TSiLiData G__TTSiLiData;
static int G__TSiLiDataDict_168_0_28(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (TSiLiData*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((TSiLiData*) (soff+(sizeof(TSiLiData)*i)))->~G__TTSiLiData();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (TSiLiData*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((TSiLiData*) (soff))->~G__TTSiLiData();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__TSiLiDataDict_168_0_29(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   TSiLiData* dest = (TSiLiData*) G__getstructoffset();
   *dest = *(TSiLiData*) libp->para[0].ref;
   const TSiLiData& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* TSiLiData */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncTSiLiDataDict {
 public:
  G__Sizep2memfuncTSiLiDataDict(): p(&G__Sizep2memfuncTSiLiDataDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncTSiLiDataDict::*p)();
};

size_t G__get_sizep2memfuncTSiLiDataDict()
{
  G__Sizep2memfuncTSiLiDataDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceTSiLiDataDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData))) {
     TSiLiData *G__Lderived;
     G__Lderived=(TSiLiData*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData),G__get_linked_tagnum(&G__TSiLiDataDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableTSiLiDataDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__TSiLiDataDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__TSiLiDataDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__TSiLiDataDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__TSiLiDataDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* TSiLiData */
static void G__setup_memvarTSiLiData(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData));
   { TSiLiData *p; p=(TSiLiData*)0x1000; if (p) { }
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlEshortcOallocatorlEshortgRsPgR),G__defined_typename("vector<short>"),-1,4,"fSiLi_E_Number=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlEdoublecOallocatorlEdoublegRsPgR),G__defined_typename("vector<double>"),-1,4,"fSiLi_E_Energy=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlEshortcOallocatorlEshortgRsPgR),G__defined_typename("vector<short>"),-1,4,"fSiLi_T_Number=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__TSiLiDataDictLN_vectorlEdoublecOallocatorlEdoublegRsPgR),G__defined_typename("vector<double>"),-1,4,"fSiLi_T_Time=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__TSiLiDataDictLN_TClass),-1,-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarTSiLiDataDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncTSiLiData(void) {
   /* TSiLiData */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData));
   G__memfunc_setup("TSiLiData",831,G__TSiLiDataDict_168_0_1, 105, G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Clear",487,G__TSiLiDataDict_168_0_2, 121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Clear",487,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "C - 'Option_t' 10 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Dump",406,(G__InterfaceMethod) NULL,121, -1, -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("GetEnergyMult",1324,G__TSiLiDataDict_168_0_5, 104, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetENumber",974,G__TSiLiDataDict_168_0_6, 105, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - i", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetEEnergy",975,G__TSiLiDataDict_168_0_7, 100, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - i", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTimeMult",1105,G__TSiLiDataDict_168_0_8, 104, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTNumber",989,G__TSiLiDataDict_168_0_9, 105, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - i", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTTime",771,G__TSiLiDataDict_168_0_10, 100, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - i", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetENumber",986,G__TSiLiDataDict_168_0_11, 121, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - N", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetEEnergy",987,G__TSiLiDataDict_168_0_12, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - E", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetTNumber",1001,G__TSiLiDataDict_168_0_13, 121, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - N", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetTTime",783,G__TSiLiDataDict_168_0_14, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - T", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__TSiLiDataDict_168_0_15, 85, G__get_linked_tagnum(&G__TSiLiDataDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&TSiLiData::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__TSiLiDataDict_168_0_16, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&TSiLiData::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__TSiLiDataDict_168_0_17, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&TSiLiData::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__TSiLiDataDict_168_0_18, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&TSiLiData::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__TSiLiDataDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__TSiLiDataDict_168_0_22, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__TSiLiDataDict_168_0_23, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&TSiLiData::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__TSiLiDataDict_168_0_24, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&TSiLiData::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__TSiLiDataDict_168_0_25, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&TSiLiData::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__TSiLiDataDict_168_0_26, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&TSiLiData::DeclFileLine) ), 0);
   // automatic copy constructor
   G__memfunc_setup("TSiLiData", 831, G__TSiLiDataDict_168_0_27, (int) ('i'), G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData), -1, 0, 1, 1, 1, 0, "u 'TSiLiData' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~TSiLiData", 957, G__TSiLiDataDict_168_0_28, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__TSiLiDataDict_168_0_29, (int) ('u'), G__get_linked_tagnum(&G__TSiLiDataDictLN_TSiLiData), -1, 1, 1, 1, 1, 0, "u 'TSiLiData' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncTSiLiDataDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalTSiLiDataDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcTSiLiDataDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__TSiLiDataDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_vectorlEshortcOallocatorlEshortgRsPgR = { "vector<short,allocator<short> >" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_vectorlEdoublecOallocatorlEdoublegRsPgR = { "vector<double,allocator<double> >" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__TSiLiDataDictLN_TSiLiData = { "TSiLiData" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableTSiLiDataDict() {
  G__TSiLiDataDictLN_TClass.tagnum = -1 ;
  G__TSiLiDataDictLN_TBuffer.tagnum = -1 ;
  G__TSiLiDataDictLN_TMemberInspector.tagnum = -1 ;
  G__TSiLiDataDictLN_TObject.tagnum = -1 ;
  G__TSiLiDataDictLN_vectorlEshortcOallocatorlEshortgRsPgR.tagnum = -1 ;
  G__TSiLiDataDictLN_vectorlEdoublecOallocatorlEdoublegRsPgR.tagnum = -1 ;
  G__TSiLiDataDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__TSiLiDataDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__TSiLiDataDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__TSiLiDataDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__TSiLiDataDictLN_TSiLiData.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableTSiLiDataDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_TObject);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_vectorlEshortcOallocatorlEshortgRsPgR);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_vectorlEdoublecOallocatorlEdoublegRsPgR);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__TSiLiDataDictLN_TSiLiData),sizeof(TSiLiData),-1,29952,"SiLiData structure",G__setup_memvarTSiLiData,G__setup_memfuncTSiLiData);
}
extern "C" void G__cpp_setupTSiLiDataDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupTSiLiDataDict()");
  G__set_cpp_environmentTSiLiDataDict();
  G__cpp_setup_tagtableTSiLiDataDict();

  G__cpp_setup_inheritanceTSiLiDataDict();

  G__cpp_setup_typetableTSiLiDataDict();

  G__cpp_setup_memvarTSiLiDataDict();

  G__cpp_setup_memfuncTSiLiDataDict();
  G__cpp_setup_globalTSiLiDataDict();
  G__cpp_setup_funcTSiLiDataDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncTSiLiDataDict();
  return;
}
class G__cpp_setup_initTSiLiDataDict {
  public:
    G__cpp_setup_initTSiLiDataDict() { G__add_setup_func("TSiLiDataDict",(G__incsetup)(&G__cpp_setupTSiLiDataDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initTSiLiDataDict() { G__remove_setup_func("TSiLiDataDict"); }
};
G__cpp_setup_initTSiLiDataDict G__cpp_setup_initializerTSiLiDataDict;


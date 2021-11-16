
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLLMAIN_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLLMAIN_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLMAIN_EXPORTS
#define DLLMAIN_API __declspec(dllexport)
#else
#define DLLMAIN_API __declspec(dllimport)
#endif

// This class is exported from the dllmain.dll
class DLLMAIN_API CDllmain {
public:
	CDllmain(void);
	// TODO: add your methods here.
};

extern DLLMAIN_API int nDllmain;

DLLMAIN_API int fnDllmain(void);


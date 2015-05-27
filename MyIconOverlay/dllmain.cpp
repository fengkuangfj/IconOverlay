// dllmain.cpp : DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "MyIconOverlay_i.h"
#include "dllmain.h"

CMyIconOverlayModule _AtlModule;

HINSTANCE			g_hInstance = NULL;

// DLL 入口点
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	g_hInstance = hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}

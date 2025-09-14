#include "pch.h"
#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <ShObjIdl.h>

ITaskbarList3* m_pTaskbarList = NULL;

LONG WINAPI About()
{
	MessageBox(
		GetDesktopWindow(),
		L"Taskbar Enhancement Pack by Farhan Ali Qureshi. All rights reserved.",
		L"Taskbar Enhancement Pack v1.0",
		MB_ICONINFORMATION);
	return TRUE;
}

LONG WINAPI TaskbarInitialize()
{
	if (m_pTaskbarList != NULL) return FALSE;		// It's already initialized

	HRESULT result = CoCreateInstance(
		CLSID_TaskbarList, 
		NULL, 
		CLSCTX_ALL, 
		IID_ITaskbarList3, 
		(LPVOID*)&m_pTaskbarList
	);

	return (result == S_OK ? TRUE : FALSE);
}

LONG WINAPI TaskbarRelease()
{
	if (m_pTaskbarList != NULL) m_pTaskbarList->Release();
	
	m_pTaskbarList = NULL;
	return TRUE;
}
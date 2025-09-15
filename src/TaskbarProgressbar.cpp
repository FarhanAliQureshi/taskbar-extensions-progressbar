#include "pch.h"
#include <SDKDDKVer.h>
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

LONG WINAPI TaskbarNoProgressbar(HWND hWindow)
{
	if (m_pTaskbarList == NULL) return FALSE;
	HRESULT result = m_pTaskbarList->SetProgressState(hWindow, TBPF_NOPROGRESS);

	return (result == S_OK ? TRUE : FALSE);
}

LONG WINAPI TaskbarIndeterminateProgressbar(HWND hWindow)
{
	if (m_pTaskbarList == NULL) return FALSE;
	HRESULT result = m_pTaskbarList->SetProgressState(hWindow, TBPF_INDETERMINATE);

	return (result == S_OK ? TRUE : FALSE);
}

LONG WINAPI TaskbarNormalProgressbar(HWND hWindow)
{
	if (m_pTaskbarList == NULL) return FALSE;
	HRESULT result = m_pTaskbarList->SetProgressState(hWindow, TBPF_NORMAL);

	return (result == S_OK ? TRUE : FALSE);
}

LONG WINAPI TaskbarErrorProgressbar(HWND hWindow)
{
	if (m_pTaskbarList == NULL) return FALSE;
	HRESULT result = m_pTaskbarList->SetProgressState(hWindow, TBPF_ERROR);

	return (result == S_OK ? TRUE : FALSE);
}

LONG WINAPI TaskbarPauseProgressbar(HWND hWindow)
{
	if (m_pTaskbarList == NULL) return FALSE;
	HRESULT result = m_pTaskbarList->SetProgressState(hWindow, TBPF_PAUSED);

	return (result == S_OK ? TRUE : FALSE);
}

LONG WINAPI TaskbarSetProgressValue(HWND hWindow, LONG lCompleted, LONG lTotal)
{
	if (m_pTaskbarList == NULL) return FALSE;
	HRESULT result = m_pTaskbarList->SetProgressValue(hWindow, lCompleted, lTotal);

	return (result == S_OK ? TRUE : FALSE);
}
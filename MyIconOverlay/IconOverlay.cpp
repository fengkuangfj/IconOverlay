// IconOverlay.cpp : CIconOverlay µÄÊµÏÖ

#include "stdafx.h"
#include "IconOverlay.h"


// CIconOverlay

extern HINSTANCE g_hInstance;


HRESULT
	STDMETHODCALLTYPE
	CIconOverlay::IsMemberOf(
	THIS_ LPCWSTR	pwszPath,
	DWORD			dwAttrib
	)
{
	HRESULT hRet				= E_FAIL;

	TCHAR	tchPath[MAX_PATH]	= {0};


	__try
	{
		if (!pwszPath)
			__leave;

		_tcscat_s(tchPath, _countof(tchPath), pwszPath);
		_tcslwr_s(tchPath, _countof(tchPath));

		if (!_tcsstr(tchPath, _T("myiconoverlay")))
			__leave;

		hRet = S_OK;
	}
	__finally
	{
		;
	}

	return hRet;
}

HRESULT
	STDMETHODCALLTYPE
	CIconOverlay::GetOverlayInfo(
	THIS_ __out_ecount(cchMax)	LPWSTR	pwszIconFile,
	int									cchMax,
	__out						int *	pIndex,
	__out						DWORD *	pdwFlags
	)
{
	HRESULT		hRet		= E_FAIL;

	HINSTANCE	hInstance	= NULL;


	__try
	{
		if (!pwszIconFile || (0 >= cchMax) || !pIndex || !pdwFlags)
			__leave;

		hInstance = _AtlBaseModule.GetModuleInstance();
		if (hInstance != g_hInstance)
			MessageBox(NULL, _T("instance not equal"), _T("instance not equal"), MB_OK | MB_ICONWARNING);

		if (0 == GetModuleFileName(hInstance, pwszIconFile, cchMax))
			__leave;

		*pIndex = 0;
		*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;

		hRet = S_OK;
	}
	__finally
	{
		;
	}

	return hRet;
}

HRESULT
	STDMETHODCALLTYPE
	CIconOverlay::GetPriority(
	THIS_ __out int * pIPriority
	)
{
	HRESULT hRet = E_FAIL;


	__try
	{
		if (!pIPriority)
			__leave;

		*pIPriority = 0;

		hRet = S_OK;
	}
	__finally
	{
		;
	}

	return hRet;
}
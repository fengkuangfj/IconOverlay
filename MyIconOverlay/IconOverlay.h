// IconOverlay.h : CIconOverlay 的声明

#pragma once
#include "resource.h"       // 主符号



#include "MyIconOverlay_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CIconOverlay

class ATL_NO_VTABLE CIconOverlay :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIconOverlay, &CLSID_IconOverlay>,
	public IDispatchImpl<IIconOverlay, &IID_IIconOverlay, &LIBID_MyIconOverlayLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellIconOverlayIdentifier
{
public:
	CIconOverlay()
	{
	}

	STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath, DWORD dwAttrib);
	STDMETHOD (GetOverlayInfo)(THIS_ __out_ecount(cchMax) LPWSTR pwszIconFile, int cchMax, __out int * pIndex, __out DWORD * pdwFlags);
	STDMETHOD (GetPriority)(THIS_ __out int * pIPriority);

DECLARE_REGISTRY_RESOURCEID(IDR_ICONOVERLAY)


BEGIN_COM_MAP(CIconOverlay)
	COM_INTERFACE_ENTRY(IIconOverlay)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



};

OBJECT_ENTRY_AUTO(__uuidof(IconOverlay), CIconOverlay)

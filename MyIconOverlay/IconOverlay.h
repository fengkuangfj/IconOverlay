// IconOverlay.h : CIconOverlay ������

#pragma once
#include "resource.h"       // ������



#include "MyIconOverlay_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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

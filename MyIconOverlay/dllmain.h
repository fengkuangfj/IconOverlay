// dllmain.h : 模块类的声明。

class CMyIconOverlayModule : public ATL::CAtlDllModuleT< CMyIconOverlayModule >
{
public :
	DECLARE_LIBID(LIBID_MyIconOverlayLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MYICONOVERLAY, "{7BCB52BB-2E80-4456-A7C8-47DECE8471AD}")
};

extern class CMyIconOverlayModule _AtlModule;

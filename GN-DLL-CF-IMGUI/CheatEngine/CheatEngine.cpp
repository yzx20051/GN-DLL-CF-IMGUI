#include "CheatEngine.h"
#include "../DllMain/DllMain.h"
#include "../NetVerification/������֤.h"


CheatEngine::CheatEngine(HINSTANCE hinstance)
{
	OutputDebugStringA_1Param("[GN]:%s", __FUNCTION__);

	//Save Modulehandle
	this->self_module_handle = hinstance;
	ce = this;

	//Find game windowhandle and set game windowhandle
	while (this->Draw::GetGameWindowHandle() == NULL)
	{
		this->Draw::SetGameWindowHandle(this->CheatEngineApi::FindWindowA("CrossFire", "��Խ����"));
	}

	DWORD game_pid = 0;
	this->CheatEngineApi::GetWindowThreadProcessId(this->CheatEngine::GetGameWindowHandle(), &game_pid);
	this->CheatEngine::SetGameProcessId(game_pid);

	//Set my driver class
	this->CheatEngine::driver = new Driver;
	this->CheatEngine::driver->SetProcessID(this->CheatEngineApi::GetCurrentProcessId());

	//Get game baseaddress
	this->Game::BaseAddressInit();

	//Set Exception Handler
	if (!gn_exception->InstallException("TKD604E537253H51289E138A1BE4588D", CheatEngine::NewExceptionHandler))
		exit(-1);
	int ret = gn_exception->GN_Exception::SetHardWareBreakPoint(L"crossfire.exe", 0x455,
		/*0*/this->Game::GameBase.ACE_BASE64 + GlobalBaseFuncOffset,
		/*0*/Hitchaddress,
		/*0*/RedNameTrackAddress,
		/*0*/SilentTrackAddress);
	this->CheatEngine::SetSoftWareBreakPoint();

	//////Clear Modulehandle Header
	////ce->CheatEngine::MemoryTools::WriteBytes((DWORD64)hinstance, temp_data, sizeof(temp_data));
	////Hide Dll Memory
	//if (!this->CheatEngine::driver->HideMemoryByVAD((ULONG64)this->self_module_handle, 0/*ģ���С*/))
	//{
	//	OutputDebugStringA("[GN]:HideMemoryByVAD() error!");
	//	exit(0);
	//}
	////BYTE temp_data[1024] = { NULL };
	////for (int i = 0; i < 1024; i++)
	////	temp_data[i] = 0x05;
	////ce->CheatEngine::driver->WriteBytesByMDL((PVOID)hinstance, temp_data, sizeof(temp_data));

}

CheatEngine::~CheatEngine()
{

}

bool CheatEngine::ByPassCheck(PCONTEXT context)
{
	DWORD64 caller_address = this->MemoryTools::ReadLong(context->Rsi);
	////���Ƽ��
	if ((caller_address > this->Game::GameBase.Win32U) && (caller_address < this->Game::GameBase.Win32UEnd))
		return true;
	if ((caller_address > this->Game::GameBase.Gdi32) && (caller_address < this->Game::GameBase.Gdi32End))
		return true;
	if ((caller_address > this->Game::GameBase.D3D9) && (caller_address < this->Game::GameBase.D3D9End))
		return true;

	//////////���ܼ��
	////////DWORD64 callto_address = ce->MemoryTools::ReadLong(context->Rbx + 0x20);
	////////if (caller_address == ce->CheatEngine::Game::GameBase.Cshell + 0x12C6890)
	////////	return false;
	////////if ((caller_address > ce->Game::GameBase.Cshell) && (caller_address < ce->Game::GameBase.CshellEndAddress))
	////////{
	////////	////�ж��Ƿ��ɱ����
	////////	//if (caller_address != ce->CheatEngine::Game::GameBase.Cshell + 0x13004E0)
	////////	//	return true;
	////////	return true;
	////////}
	//////if ((caller_address > ce->Game::GameBase.Cross) && (caller_address < ce->Game::GameBase.CrossEndAddress))
	//////	return true;
	//if (caller_address == this->Game::GameBase.Cshell + 0x12F34C0)
	//{
	//	DWORD64 callto_address = this->MemoryTools::ReadLong(context->Rbx + 0x20);
	//	if (callto_address == this->GameBase.ACE_PBC_GAME64 + 0x4DFE0)
	//	{
	//		OutputDebugStringA_1Param("[GN]:��ַ:%p", callto_address);
	//		return true;
	//	}
	//	if (callto_address == this->GameBase.ACE_PBC_GAME64 + 0x52820)
	//	{
	//		OutputDebugStringA_1Param("[GN]:��ַ:%p", callto_address);
	//		return true;
	//	}
	//	if (callto_address < 0x700000000000)
	//	{
	//		OutputDebugStringA_1Param("[GN]:��ַ:%p", callto_address);
	//		return true;
	//	}
	//	return false;
	//}
	//if (caller_address == this->Game::GameBase.Cshell + 0xACA640)
	//	return true;

	//if (caller_address == this->Game::GameBase.Cshell + 0x12F34C0)
	//	return false;
	//DWORD64 callto_address = this->MemoryTools::ReadLong(context->Rbx + 0x20);
	//if ((callto_address > this->GameBase.ACE_GDP64) && (callto_address < this->GameBase.ACE_GDP64End))
	//	return false;
	//else if ((callto_address > this->GameBase.ACE_PBC_GAME64) && (callto_address < this->GameBase.ACE_PBC_GAME64End))
	//	return false;
	//else
	//	return true;

	return false;
}

void CheatEngine::InitHook()
{
	__int64* direct3ddevice9_table = (__int64*)*(__int64*)this->CheatEngine::Draw::GetD3D9Device();
	//this->CheatEngine::Draw::setviewport_hook = new inline_hook(direct3ddevice9_table[47], (__int64)&Draw::Self_SetViewport, FALSE);
	//this->CheatEngine::Draw::setviewport_hook->motify_address();
	//this->CheatEngine::Draw::reset_hook = new inline_hook(direct3ddevice9_table[16], (__int64)&Draw::Self_Reset, FALSE);
	//this->CheatEngine::Draw::reset_hook->motify_address();
	//this->CheatEngine::Draw::drawindexedprimitive_hook = new inline_hook(direct3ddevice9_table[82], (__int64)&Draw::Self_DrawIndexedPrimitive, FALSE);
	//this->CheatEngine::Draw::drawindexedprimitive_hook->motify_address();

	if (this->CheatEngine::Draw::CreateDeviceD3D11(this->GetGameWindowHandle()))
	{
		__int64* SwapChainTable = (__int64*)*(__int64*)this->CheatEngine::Draw::GetD3D11SwapChain();
		OutputDebugStringA_1Param("[GN]:GetBuffer��ַ��%p", SwapChainTable[1]);
		this->CheatEngine::Draw::m_OriginalGetBufferPoint = (OriginalGetBufferStruct)SwapChainTable[1];
		this->CheatEngine::Draw::getbuffer_hook = new inline_hook(SwapChainTable[1], (__int64)&Draw::Self_GetBuffer, FALSE);
		this->CheatEngine::Draw::getbuffer_hook->motify_address();
	}

}

void CheatEngine::SetSoftWareBreakPoint()
{
	gn_exception->software_breakpoint1 = this->CheatEngine::Game::GameBase.Cshell + BulletWithoutBackSeatHookOffset;

}


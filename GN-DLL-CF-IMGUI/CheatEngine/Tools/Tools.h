#pragma once
#include "../../pch.h"
#include <winternl.h>
#include <DbgHelp.h>
#pragma comment(lib, "dbghelp.lib")

struct systime
{
	int year; int month; int day; int hour; int min; int sec;
};

struct STACK_FRAME_INFO {
	PVOID returnAddress;
	PVOID functionAddress;
	PVOID callAddress;
	PVOID callTargetAddress;
};

struct CALL_STACK_INFO {
	PVOID stackBottom;
	PVOID stackTop;
	DWORD dwFrameCount;
	STACK_FRAME_INFO* pFrameList;
};


class Tools
{
private:
	time_t rawtime;
	struct tm* timeinfo;

public:
	systime GetSystemtime();
	std::string string_to_utf8(const std::string& str);
	WCHAR* charToWchar(char* s);
	void BrokenModuleLink(HANDLE modulehandle);
	DWORD RVA_2_RAW(char* buf, DWORD RVA, DWORD RAW, BOOL flag);
	DWORD64 GetImportTableIndexOffset(HANDLE modulehandle, PDWORD import_table_size);
	PVOID64 GetModuleEndAddress(HMODULE module_handle);
	void StackTrace64();
	PVOID GetReturnAddress();
	void GetCallStackInfo(CALL_STACK_INFO& callStack, DWORD dwMaxFrame);
	void GetStack(void);
	bool SuspendThreadByNoModulehandle(DWORD pid);
	bool SuspendThreadByModulehandle(DWORD pid, DWORD64 module_handle, DWORD64 module_handle_end_address);
	bool SuspendThreadByTag(DWORD pid, const char* judgment_tag);
	bool ResumeThreadByTag(DWORD pid, const char* judgment_tag);
	bool TerminateThreadByModulehandle(DWORD pid, DWORD64 module_handle, DWORD64 module_handle_end_address);
	bool UnloadDll(HMODULE module_handle, HMODULE module_handle_end_address);
	void EnumPEHeader(HMODULE module_handle);

};


#define WIN32_LEAN_AND_MEAN  
#pragma once
#include <windows.h>
#include "tlhelp32.h"


struct READWRITE
{
	DWORD Pid;
	ULONG64 Address;
	DWORD Size;
	ULONG64 Buffer;
};
typedef struct _MEMORY_BASIC_INFORMATIONA
{
	ULONG64  BaseAddress;
	ULONG64  AllocationBase;
	ULONG  AllocationProtect;
	SIZE_T RegionSize;
	ULONG  State;
	ULONG  Protect;
	ULONG  Type;

} MEMORY_BASIC_INFORMATIONA, *PMEMORY_BASIC_INFORMATIONA;
typedef struct _MyMEMORY_BASIC_INFORMATION {
	ULONG64 BaseAddress;
	ULONG64 AllocationBase;
	ULONG64 AllocationProtect;
	ULONG64 RegionSize;
	ULONG64 State;
	ULONG64 Protect;
	ULONG64 Type;
} MyMEMORY_BASIC_INFORMATION, *PMyMEMORY_BASIC_INFORMATION;
typedef struct _MMEMORY_BASIC_INFORMATION {
	ULONG64 BaseAddress;
	ULONG64 AllocationBase;
	ULONG64 AllocationProtect;
	ULONG64 RegionSize;
	ULONG64 State;
	ULONG64 Protect;
	ULONG64 Type;
} MMEMORY_BASIC_INFORMATION, *PMMEMORY_BASIC_INFORMATION;
typedef struct _QueryMemoryInfo
{
	ULONG64 pid;
	ULONG64 BaseAddress;
	MyMEMORY_BASIC_INFORMATION memoryInfo;
}QueryMemoryInfo, *PQueryMemoryInfo;
class Sandy64
{
public:
	BOOL SetPid(DWORD ProcessName);
	template<typename DataType> DataType Read(ULONG64 Address)
	{
		DataType Buffer;
		ReadPtr(Address, &Buffer, sizeof(DataType));
		return Buffer;
	}
	ULONG64 GetModuleBase(ULONG ProcessPid, LPCSTR ModuleName);
	ULONG64 ApplyMemory(ULONG ProcessPid, DWORD Size);
	BOOL ReadPtr(ULONG ProcessPid, ULONG64 Address, PVOID pBuffer, DWORD Size);
	BOOL WritePtr(ULONG ProcessPid, ULONG64 Address, PVOID pBuffer, DWORD Size);
	BOOL QueryMemory(ULONG ProcessPid, ULONG64 BaseAddress, MEMORY_BASIC_INFORMATIONA &pinfo);
};
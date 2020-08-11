#pragma once
#include "hook_functions.h"

struct Hook
{
	DWORD64 address;	//Function address we're hooking.
	int length;			//Function length
	DWORD64 function;	//Hook function address
};

volatile DWORD64 isFunctionActive = 0;
volatile DWORD64 activeFunction = 0;

volatile DWORD64* isFunctionActiveP = &isFunctionActive;
volatile DWORD64* activeFunctionP = &activeFunction;

Hook sellFunc = {
	(DWORD64)GetModuleHandle(NULL) + 0x632C80,		//Function address we're hooking.
	27,												//Function length.
	(DWORD64)sellHookThread
};

Hook damageFunc = {
	(DWORD64)GetModuleHandle(NULL) + 0x500B10,
	15,
	(DWORD64)damageHookThread
};

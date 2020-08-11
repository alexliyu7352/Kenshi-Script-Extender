// dllmain.cpp : Defines the entry point for the DLL application.
#include <iostream>
#include <string>
#include "hook.h"

HMODULE GetCurrentModule()
{
	HMODULE hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		(LPCTSTR)GetCurrentModule,
		&hModule);

	return hModule;
}

void StartKSE()
{
	CreateHook(&sellFunc);
	CreateHook(&damageFunc);
	DisableThreadLibraryCalls(GetCurrentModule());
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)startKSEThread, nullptr, 0, nullptr);
}

//Ogre plugin entrypoint
extern "C" _declspec(dllexport) void dllStartPlugin()
{
	StartKSE();
}

//Ogre plugin exit
extern "C" _declspec(dllexport) void dllStopPlugin()
{

}



#pragma once
#include "function_address.h"

typedef void Func(void);

//Hook handling thread.
void startKSEThread()
{

	//Console set up stuff...
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("KSE Console");

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "KSE console loaded..." << std::endl;
	SetConsoleTextAttribute(hConsole, 7);

	//Wait for isFunctionActive, once set it then casts the activeFunction to Func, runs it, then resets isFunctionActive.
	while (true) 
	{
		if (isFunctionActive == 1) 
		{
			Func* runFunction = (Func*)activeFunction;
			runFunction();
			isFunctionActive = 0;
		}
	
	}
}
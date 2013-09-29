// Test_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Valera3D.h"

using namespace v3d;
using namespace platform;



int _tmain(int argc, _TCHAR* argv[])
{

	CPlatform* plt = CPlatformMgr::createWindow(WindowSize(800,600),false);
	plt->mainLoop();

	return 0;
	
}


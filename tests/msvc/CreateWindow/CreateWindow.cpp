// CreateWindow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyApplication.h"

int _tmain(int argc, _TCHAR* argv[])
{
	BaseApplication* app = new MyApplication(argc, argv);
	return app->exec();
}


#include "MyApplication.h"
#include <iostream>

#include "GL/glew.h"
#if defined (_PLATFORM_WIN_)
#	include <windows.h>
#endif

MyApplication::MyApplication(int& argc, char** argv)
	: BaseApplication(argc, argv)
{
}

MyApplication::~MyApplication()
{
}

void MyApplication::init()
{
	glViewport( 0, 0, 800, 600 );
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MyApplication::run()
{
	//Temporary
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	int a = 0;
	glFlush();
}

#include "MyApplication.h"

#include "..\libs\glew\include\GL\glew.h"
#include <windows.h>

MyApplication::MyApplication(int& argc, wchar_t** argv)
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
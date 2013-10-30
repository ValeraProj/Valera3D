#ifndef _MY_APPLICATION_H_
#define _MY_APPLICATION_H_

#include "BaseApplication.h"

class MyApplication : public BaseApplication
{
public:
	MyApplication(int& argc, char** argv);
	virtual ~MyApplication();

	virtual void init();
	virtual void run();
};

#endif
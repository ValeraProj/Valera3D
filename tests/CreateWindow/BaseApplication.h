#ifndef _BASE_APPLICATION_H_
#define _BASE_APPLICATION_H_

#include "Valera3D.h"

class BaseApplication
{
public:
	BaseApplication(int& argc, char** argv);
	virtual ~BaseApplication();

	virtual void init() = 0;
	virtual void run()  = 0;
	
	int exec();

protected:
	v3d::CValeraEngine* m_engine;
};

#endif
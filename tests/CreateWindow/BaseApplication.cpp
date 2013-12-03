#include "BaseApplication.h"

using namespace v3d;
using namespace platform;

BaseApplication::BaseApplication(int& argc, char** argv)
{
	m_engine = CValeraEngine::getInstance();
	m_engine->getPlatform()->createWindowWithContext(core::Dimension2D(800, 600));
}

BaseApplication::~BaseApplication()
{
	CValeraEngine::freeInstance();
}

int BaseApplication::exec()
{
	this->init();

	while (m_engine->begin())
	{
		this->run();

		m_engine->end();
	}

	return 0;
}
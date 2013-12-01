#include "BaseApplication.h"

using namespace v3d;
using namespace platform;

BaseApplication::BaseApplication(int& argc, char** argv)
{
	m_engine = CValeraEngine::getInstance();
	m_engine->setWindow(CPlatform::createWindowWithContext(core::Dimension2D(800, 600), false));
}

BaseApplication::~BaseApplication()
{
	CValeraEngine::freeInstance();
}

int BaseApplication::exec()
{
	this->init();

	while (m_engine->getWindow()->begin())
	{
		this->run();

		m_engine->getWindow()->end();
	}

	return 0;
}
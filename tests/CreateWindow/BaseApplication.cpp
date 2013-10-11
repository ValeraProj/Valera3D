#include "BaseApplication.h"

using namespace v3d;
using namespace platform;

BaseApplication::BaseApplication(int& argc, wchar_t** argv)
{
	m_engine = CValeraEngine::getInstance();
	m_engine->setPlatform(CPlatformMgr::createWindow(core::Dimension2D(800,600),false));
}

BaseApplication::~BaseApplication()
{
	CValeraEngine::freeInstance();
}

int BaseApplication::exec()
{
	this->init();

	while (m_engine->getPlatform()->begin())
	{
		this->run();

		m_engine->getPlatform()->end();
	}

	return 0;
}
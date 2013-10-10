#include "ValeraEngine.h"
#include "platform\PlatformMgr.h"

using namespace v3d;
using namespace platform;

CValeraEngine::CValeraEngine()
{
	CPlatform* plt = CPlatformMgr::createWindow(core::Dimension2D(800,600), false);
}

CValeraEngine::~CValeraEngine()
{
}

CPlatform* CValeraEngine::getPlatform() const
{
	return m_platform;
}

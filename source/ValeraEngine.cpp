#include "ValeraEngine.h"
#include "platform/Platform.h"

using namespace v3d;
using namespace platform;

CValeraEngine::CValeraEngine()
{
}

CValeraEngine::~CValeraEngine()
{
}

CWindow* CValeraEngine::getWindow() const
{
	return m_platform;
}

void CValeraEngine::setWindow(platform::CWindow* platform)
{
	m_platform = platform;
}

#include "ValeraEngine.h"
#include "platform/PlatformManager.h"

using namespace v3d;
using namespace platform;

CValeraEngine::CValeraEngine()
{
}

CValeraEngine::~CValeraEngine()
{
}

CPlatform* CValeraEngine::getPlatform() const
{
	return m_platform;
}

void CValeraEngine::setPlatform( platform::CPlatform* platform )
{
	m_platform = platform;
}

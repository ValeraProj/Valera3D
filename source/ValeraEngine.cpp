#include "ValeraEngine.h"
#include "platform/Platform.h"

using namespace v3d;
using namespace platform;

CValeraEngine::CValeraEngine()
: m_platform( nullptr )
{
	CValeraEngine::init();
}

CValeraEngine::~CValeraEngine()
{
	
	m_platform = nullptr;
}

void CValeraEngine::init()
{
	m_platform = std::make_shared<CPlatform>(CPlatform());
}

CPlatformPtr CValeraEngine::getPlatform() const
{
	return m_platform;
}

bool CValeraEngine::begin()
{
	return m_platform->begin();
}

bool CValeraEngine::end()
{
	return m_platform->end();
}

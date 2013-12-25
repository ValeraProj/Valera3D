#include "ValeraEngine.h"
#include "platform/Platform.h"
#include "event/InputEventHandler.h"

using namespace v3d;
using namespace platform;
using namespace event;

CValeraEngine::CValeraEngine()
: m_platform( nullptr )
, m_inputEventHandler(nullptr)
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
	m_inputEventHandler = std::make_shared<CInputEventHandler>(CInputEventHandler());
}

CPlatformPtr CValeraEngine::getPlatform() const
{
	return m_platform;
}

event::CInputEventHandlerPtr CValeraEngine::getInputEventHandler() const
{
	return m_inputEventHandler;
}

bool CValeraEngine::begin()
{
	m_inputEventHandler->update();

	return m_platform->begin();
}

bool CValeraEngine::end()
{
	return m_platform->end();
}

#include "Platform.h"

using namespace v3d;
using namespace platform;

CPlatform::CPlatform( const PlatformParam& param )
	: m_param( param )
	, m_platformType( EPlatformType::ePlatformNull )
{
}

CPlatform::~CPlatform()
{
}

bool CPlatform::isFullscreen() const
{
	return m_param.isFullscreen;
}

bool CPlatform::isResizeble() const
{
	return m_param.isResizeble;
}

const core::Dimension2D& CPlatform::getWindowsSize() const
{
	return m_param.windowSize;
}

EPlatformType CPlatform::getPlatformType() const
{
	return m_platformType;
}

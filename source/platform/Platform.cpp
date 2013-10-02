#include "Platform.h"

using namespace v3d;
using namespace platform;

CPlatform::CPlatform( const PlatformParam& param )
	: m_param(param)
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

const WindowSize& CPlatform::getWindowsSize() const
{
	return m_param.windowSize;
}
#include "PlatformLinux.h"

using namespace v3d;
using namespace platform;

CPlatformLinux::CPlatformLinux( const PlatformParam& param )
    : CPlatform(param)
{
}

CPlatformLinux::~CPlatformLinux()
{
}

void CPlatformLinux::minimizeWindow()
{
}

void CPlatformLinux::maximizeWindow()
{
}

void CPlatformLinux::restoreWindow()
{
}

void CPlatformLinux::setFullScreen( bool value )
{
}

void CPlatformLinux::setResizeble ( bool value )
{
}

void CPlatformLinux::setWindowCaption( const std::string& text )
{
}

void CPlatformLinux::setWindowCaption( const std::wstring& text )
{
}

bool CPlatformLinux::isWindowMaximized() const
{
	return false;
}

bool CPlatformLinux::isWindowMinimized() const
{
	return false;
}

bool CPlatformLinux::isWindowActive() const
{
	return false;
}

bool CPlatformLinux::isWindowFocused() const
{
	return false;
}

void CPlatformLinux::createWindows()
{

}

void CPlatformLinux::closeWindow()
{

}

bool CPlatformLinux::begin()
{
	return false;
}

bool CPlatformLinux::end()
{
	return false;
}

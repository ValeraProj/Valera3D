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
}

bool CPlatformLinux::isWindowMinimized() const
{
}

bool CPlatformLinux::isWindowActive() const
{
}

bool CPlatformLinux::isWindowFocused() const
{
}

void CPlatformLinux::createWindows()
{
}

void CPlatformLinux::closeWindow()
{
}

bool CPlatformLinux::begin()
{
}

bool CPlatformLinux::end()
{
}

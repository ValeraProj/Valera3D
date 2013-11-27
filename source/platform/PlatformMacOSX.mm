#include "PlatformMacOSX.h"

using namespace v3d;
using namespace v3d::platform;

CPlatformMacOSX::CPlatformMacOSX( const PlatformParam& param )
    : CPlatform(param)
{
    m_platformType = EPlatformType::ePlatformMacOSX;
    
    CPlatformMacOSX::createWindows();
    
}

CPlatformMacOSX::~CPlatformMacOSX()
{
}

void CPlatformMacOSX::minimizeWindow()
{
}

void CPlatformMacOSX::maximizeWindow()
{
}

void CPlatformMacOSX::restoreWindow()
{
}

void CPlatformMacOSX::setFullScreen( bool value )
{
}

void CPlatformMacOSX::setResizeble( bool value )
{
}

void CPlatformMacOSX::setWindowCaption( const std::string& text )
{
}

bool CPlatformMacOSX::isWindowMaximized() const
{
}

bool CPlatformMacOSX::isWindowMinimized() const
{
}

bool CPlatformMacOSX::isWindowActive() const
{
}

bool CPlatformMacOSX::isWindowFocused() const
{
    
}

bool CPlatformMacOSX::begin()
{
}

bool CPlatformMacOSX::end()
{
}

void CPlatformMacOSX::createWindows()
{
}

void CPlatformMacOSX::closeWindow()
{
}
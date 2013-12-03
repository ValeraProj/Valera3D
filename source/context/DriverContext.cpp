#include "DriverContext.h"

using namespace v3d;
using namespace v3d::renderer;

CDriverContext::CDriverContext(const platform::CWindowPtr& window)
	: m_window(window)
{
}

CDriverContext::~CDriverContext()
{
}
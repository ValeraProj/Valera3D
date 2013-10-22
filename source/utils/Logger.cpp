#include "Logger.h"

#include <iostream>

using namespace v3d;
using namespace utils;

const std::string k_loggerType[ELoggerType::eLoggerCount] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};


	CLogger::CLogger()
	: m_logFile("logfile.log")
{
}

CLogger::~CLogger()
{
}

void CLogger::createLogFile ( const std::string& fileName )
{
	m_logFile = fileName;


}

void CLogger::log( const std::string& format, ELoggerType type, ELogOut out, ... )
{

}

void CLogger::log( const std::string& message, ELoggerType type, ELogOut out )
{
	switch(out)
	{
	case ELogOut::eConsoleLog:
		{
			logToConsole(message, type);
		}
		break;
	case ELogOut::eFileLog:
		{
			logToConsole(message, type);
		}
		break;
	case ELogOut::eBothLog:
		{
			logToConsole(message, type);
			logToConsole(message, type);
		}
		break;
	default:
		{
		}
		break;
	}
}

void CLogger::destroyLogFile()
{
}

void CLogger::logToConsole( const std::string& message, ELoggerType type )
{
	if (type == ELoggerType::eLoggerDebug)
	{
#if defined (_DEBUG) || defined(DEBUG)
		std::cout << k_loggerType[eLoggerDebug] << ": " << message << std::endl;
#endif
	}
	else
	{
		std::cout << k_loggerType[type] << ": " << message << std::endl;
	}
}

void CLogger::logToFile( const std::string& message, ELoggerType type )
{
}
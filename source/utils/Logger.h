#ifndef _V3D_LOGGER_H_
#define _V3D_LOGGER_H_

#include "common.h"
#include "Singleton.h"

namespace v3d
{
namespace utils
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum ELoggerType
	{
		eLoggerDebug,
		eLoggerInfo,
		eLoggerWarning,
		eLoggerError,

		eLoggerCount
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class ELogOut
	{
		eConsoleLog,
		eFileLog,
		eBothLog
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CLogger : public Singleton<CLogger>
	{
	public:
							CLogger();
		virtual				~CLogger();

		void				createLogFile ( const std::string& filename );
		
		void				log( const std::string& message, ELoggerType type = ELoggerType::eLoggerInfo, ELogOut out = ELogOut::eConsoleLog );
		void				log( ELoggerType type, ELogOut out, const char* format, ... );

		void				destroyLogFile();
		
	protected:

		void				logToConsole( const std::string& message, ELoggerType type );
		void				logToFile( const std::string& message, ELoggerType type );

		std::string			m_logFilename;
		std::ofstream		m_file;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}
#endif
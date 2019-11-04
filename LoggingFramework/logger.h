#pragma once

#include <ostream>
#include <string>
#include <stdint.h>

#include "logger_colour.h"

#if __has_include("logger_output.h")
#include "logger_output.h"
#define HAS_INCLUDE
#endif

#define SETUP_LOGGER_MODULE(module) \
inline void fatal(std::string &msg) { logger_mod_fatal(module, msg); }\
inline void error(std::string &msg) { logger_mod_error(module, msg); }\
inline void warning(std::string &msg) { logger_mod_warning(module, msg); }\
inline void info(std::string &msg) { logger_mod_info(module, msg); }\
inline void debug(std::string &msg) { logger_mod_debug(module, msg); }\
inline void verbose(std::string &msg) { logger_mod_verbose(module, msg); }

namespace linv {
	enum LogLevel
	{
		FATAL,
		ERROR,
		WARNING,
		INFO,
		DEBUG,
		VERBOSE
	};


		void init_logger();
		void destroy_logger();

		void logger_mod_fatal(std::string& module, std::string& msg);
		void logger_mod_error(std::string& module, std::string& msg);
		void logger_mod_warning(std::string& module, std::string& msg);
		void logger_mod_info(std::string& module, std::string& msg);
		void logger_mod_debug(std::string& module, std::string& msg);
		void logger_mod_verbose(std::string& module, std::string& msg);

		std::uint8_t addLoggerOutput(std::ostream* stream, LoggerColour cFatal, LoggerColour cError, LoggerColour cWarn, LoggerColour cInfo, LoggerColour cDebug, LoggerColour cVerbose);
		void removeLoggerOutput(uint8_t &id);

}

#pragma once

#include <stdint.h>
#include <ostream>

#include "linvogel_colour_framework.h"

#define lvGetLogLevelName		linv::log::getName
#define lvAddLoggerOutput		linv::log::addLoggerOutput
#define lvRemoveLoggerOutput	linv::log::removeOutput
#define lvSetStreamLevel		linv::log::setStreamLevel
#define lvFATAL					linv::log::FATAL
#define lvERROR					linv::log::ERROR
#define lvWARNING				linv::log::WARNING
#define lvINFO					linv::log::INFO
#define lvDEBUG					linv::log::DEBUG
#define lvVERBOSE				linv::log::VERBOSE

#define lvSetupLoggerModule(module) \
			inline void fatal(const char* msg) { linv::log::fatal(module, msg); } \
			inline void error(const char* msg) { linv::log::error(module, msg); } \
			inline void warning(const char* msg) { linv::log::warning(module, msg); } \
			inline void info(const char* msg) { linv::log::info(module, msg); } \
			inline void debug(const char* msg) { linv::log::debug(module, msg); } \
			inline void verbose(const char* msg) { linv::log::verbose(module, msg); }

namespace linv {
	namespace log {

		enum LogLevel {
			FATAL = 0,
			ERROR = 1,
			WARNING = 2,
			INFO = 3,
			DEBUG = 4,
			VERBOSE = 5
		};

		const char* getName(LogLevel level);

		void fatal(const char* module, const char* msg);
		void error(const char* module, const char* msg);
		void warning(const char* module, const char* msg);
		void info(const char* module, const char* msg);
		void debug(const char* module, const char* msg);
		void verbose(const char* module, const char* msg);

		void setStreamLevel(uint8_t id, LogLevel level);
		void removeOutput(uint8_t id);
		uint8_t addLoggerOutput(std::ostream* stream, LogLevel level, linv::colours::ConsoleColour cFatal, linv::colours::ConsoleColour cError, linv::colours::ConsoleColour cWarn, linv::colours::ConsoleColour cInfo, linv::colours::ConsoleColour cDebug, linv::colours::ConsoleColour cVerbose);

	}
}
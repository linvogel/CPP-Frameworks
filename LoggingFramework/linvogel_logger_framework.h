#pragma once

#include <stdint.h>
#include <ostream>

#include "linvogel_colour_framework.h"


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
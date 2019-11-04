#pragma once

#include <ostream>
#include <stdint.h>

#include "logger_colour.h"

namespace linv {

	struct LoggerOutputTuple {
		std::ostream* stream;
		uint8_t level;
		LoggerColour* colour[6];
	};

}
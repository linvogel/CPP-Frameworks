#pragma once

#include <ostream>
#include <stdint.h>

namespace linv {

	struct LoggerOutputTuple {
		std::ostream* stream;
		uint8_t* level;
	};

}
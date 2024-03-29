#pragma once

#include <iostream>

namespace linv {

	enum LoggerColour
	{
		black = 0,
		dark_blue = 1,
		dark_green = 2,
		dark_aqua = 3,
		dark_cyan = 3,
		dark_red = 4,
		dark_purple = 5,
		dark_pink = 5,
		dark_magenta = 5,
		dark_yellow = 6,
		dark_white = 7,
		gray = 8,
		blue = 9,
		green = 10,
		aqua = 11, cyan = 11,
		red = 12,
		purple = 13,
		pink = 13,
		magenta = 13,
		yellow = 14,
		white = 15
	};

}

template<class elem, class traits>
std::basic_ostream<elem, traits>& operator<<(std::basic_ostream<elem, traits>& os, linv::LoggerColour col);
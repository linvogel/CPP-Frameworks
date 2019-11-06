#pragma once

#define lvInitColour		linv::colours::init
#define lvDestroyColour		linv::colours::destroy
#define lvColourSet			linv::colours::set_colour
#define lvColourSetBG		linv::colours::set_bg
#define lvColourSetFG		linv::colours::set_fg
#define lvColourUpdate		linv::colours::update
#define lvConsoleColour		linv::colours::ConsoleColour


namespace linv {
	namespace colours {

		enum ConsoleColour {
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
			aqua = 11,
			cyan = 11,
			red = 12,
			purple = 13,
			pink = 13,
			magenta = 13,
			yellow = 14,
			white = 15
		};

		void init();
		bool is_init();
		void destroy();
		void set_colour(ConsoleColour fg, ConsoleColour bg);
		void set_fg(ConsoleColour fg);
		void set_bg(ConsoleColour bg);
		void update();
	}
}
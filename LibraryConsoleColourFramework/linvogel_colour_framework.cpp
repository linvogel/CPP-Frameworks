#include "linvogel_colour_framework.h"

#include <Windows.h>
#include <iosfwd>

#include <iostream>

namespace linv {
	namespace colours {
		HANDLE hConsole = 0;
		linv::colours::ConsoleColour colour_back, colour_front, colour_back_orig, colour_front_orig;
		bool bInit = false;
	}
}

void linv::colours::init()
{
	if (bInit) return;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	update();
	colour_front_orig = colour_front;
	colour_back_orig = colour_back;
	if (colour_front_orig == colour_back_orig) {
		colour_front_orig = ConsoleColour::dark_white;
		colour_back_orig = ConsoleColour::black;
	}
	std::cout << (unsigned int)colour_back_orig << ", " << (unsigned int)colour_front_orig << std::endl;
	bInit = true;
}

bool linv::colours::is_init()
{
	return bInit;
}

void linv::colours::destroy()
{
	if (!bInit) return;
	set_colour(colour_front_orig, colour_back_orig);
	hConsole = 0;
	bInit = false;
}

void linv::colours::set_colour(ConsoleColour fg, ConsoleColour bg)
{
	if (!bInit) return;
	if (fg == bg)return;
	colour_front = fg; colour_back = bg;
	unsigned short wAttributes = ((unsigned int)colour_back << 4) | (unsigned int)colour_front;
	SetConsoleTextAttribute(hConsole, wAttributes);
}

void linv::colours::set_fg(ConsoleColour fg)
{
	if (!bInit) return;
	if (fg == colour_back) return;
	colour_front = fg;
	unsigned short wAttributes = ((unsigned int)colour_back << 4) | (unsigned int)colour_front;
	SetConsoleTextAttribute(hConsole, wAttributes);
}

void linv::colours::set_bg(ConsoleColour bg)
{
	if (!bInit) return;
	if (colour_front == bg) return;
	colour_back = bg;
	unsigned short wAttributes = ((unsigned int)colour_back << 4) | (unsigned int)colour_front;
	SetConsoleTextAttribute(hConsole, wAttributes);
}

void linv::colours::update()
{
	if (!bInit) return;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	colour_front = ConsoleColour(csbi.wAttributes & 15);
	colour_back = ConsoleColour((csbi.wAttributes & 0xf0) >> 4);
}

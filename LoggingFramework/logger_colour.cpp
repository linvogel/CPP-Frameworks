#include "logger_colour.h"

#include <Windows.h>
#include <iosfwd>

#include <iostream>

HANDLE hOut;
linv::LoggerColour col_FG, col_FG_orig, col_BG, col_BG_orig;
bool working;

inline void logger_update_colors()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hOut, &csbi);
	col_FG = linv::LoggerColour(csbi.wAttributes & 15);
	col_BG = linv::LoggerColour((csbi.wAttributes & 0xf0) >> 4);
}

inline void setc(linv::LoggerColour fg, linv::LoggerColour bg)
{
	if (fg == bg)return;
	col_FG = fg; col_BG = bg;
	unsigned short wAttributes = ((unsigned int)col_BG << 4) | (unsigned int)col_FG;
	SetConsoleTextAttribute(hOut, wAttributes);
}

inline void setfg(linv::LoggerColour fg)
{
	if (fg == col_BG)return;
	col_FG = fg;
	unsigned short wAttributes = ((unsigned int)col_BG << 4) | (unsigned int)col_FG;
	SetConsoleTextAttribute(hOut, wAttributes);
}

inline void setbg(linv::LoggerColour bg)
{
	if (col_FG == bg)return;
	col_BG = bg;
	unsigned short wAttributes = ((unsigned int)col_BG << 4) | (unsigned int)col_FG;
	SetConsoleTextAttribute(hOut, wAttributes);
}

inline void logger_colour_init()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	logger_update_colors();
	col_FG_orig = col_FG;
	col_BG_orig = col_BG;
}

template<class elem, class traits>
std::basic_ostream<elem, traits>& operator<<(std::basic_ostream<elem, traits>& os, linv::LoggerColour col)
{
	if (&std::cout != &os) return os;
	os.flush(); setfg(col); return os;
}
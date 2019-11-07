
#include "linvogel_colour_framework.h"
#include "linvogel_logger_framework.h"

#include <iostream>

lvSetupLoggerModule("UnitTestMain")

int main(void)
{
	lvInitColour();
	lvAddLoggerOutput(&std::cout, lvVERBOSE, lvConsoleColour::red, lvConsoleColour::dark_red, lvConsoleColour::dark_yellow, lvConsoleColour::white, lvConsoleColour::cyan, lvConsoleColour::blue);
	
	fatal("This is a fatal error!");
	error("This error was recoverable.");
	warning("This might lead to an error...");
	info("This is an ordinary message");
	debug("This should aid debugging");
	verbose("This is probably too verbose for anyone except for me right now");



	lvDestroyColour();
}
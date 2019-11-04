#include "logger.h"

#include "logger_output.h"

#include <mutex>

uint8_t count;
struct LoggerOutputTuple* outputs[255] = { 0 };
std::mutex mtx;


/**
Attaches a new ostream to the logging framework with the specified colours to be used for the coresponding levels
 */
std::uint8_t linv::addLoggerOutput(std::ostream* stream, linv::LoggerColour cFatal = linv::LoggerColour::white, linv::LoggerColour cError = linv::LoggerColour::white, linv::LoggerColour cWarn = linv::LoggerColour::white, linv::LoggerColour cInfo = linv::LoggerColour::white, linv::LoggerColour cDebug = linv::LoggerColour::white, linv::LoggerColour cVerbose = linv::LoggerColour::white)
{
	mtx.lock();
	uint8_t index = 0;
	if (count >= 255) goto exit;
	for (; index != 0; index++);
	if (index == 0) goto exit;
	count++;

	index++;
exit:
	mtx.unlock();
	return index;
}

void linv::init_logger()
{
	mtx.lock();
	count = 0;
	mtx.unlock();
}

void linv::destroy_logger()
{
	mtx.lock();
	mtx.unlock();
}

void linv::logger_mod_fatal(std::string& module, std::string& msg)
{
	mtx.lock();
	mtx.unlock();
}

void linv::logger_mod_error(std::string& module, std::string& msg)
{
	mtx.lock();
	mtx.unlock();
}

void linv::logger_mod_warning(std::string& module, std::string& msg)
{
	mtx.lock();
	mtx.unlock();
}

void linv::logger_mod_info(std::string& module, std::string& msg)
{
	mtx.lock();
	mtx.unlock();
}

void linv::logger_mod_debug(std::string& module, std::string& msg)
{
	mtx.lock();
	mtx.unlock();
}

void linv::logger_mod_verbose(std::string& module, std::string& msg)
{
	mtx.lock();
	mtx.unlock();
}

void linv::removeLoggerOutput(uint8_t& id)
{
	mtx.lock();
	free(outputs[id - 1]);
	outputs[id - 1] = 0;
	id = 0;
	mtx.unlock();
}

#include "linvogel_logger_framework.h"

#include <mutex>

struct OTuple {
	std::ostream* stream;
	linv::log::LogLevel level;
	linv::colours::ConsoleColour colours[6];
};

namespace linv { namespace log {
	void log(LogLevel level, const char* module, const char* msg);
} }

struct OTuple* outs[255];
uint8_t count = 0;
std::mutex mtx;

void linv::log::log(linv::log::LogLevel level, const char* module, const char* msg)
{
	for (uint8_t i = 0; i < 255; i++) {
		if (outs[i] != 0) {
			if (level <= outs[i]->level) {
				*(outs[i]->stream) << outs[i]->colours[level];
				*(outs[i]->stream) << "[" << linv::log::getName(level) << "][" << module << "] " << msg << std::endl;
			}
		}
	}
}

void linv::log::fatal(const char* module, const char* msg)
{
	mtx.lock();
	log(FATAL, module, msg);
	mtx.unlock();
}

void linv::log::error(const char* module, const char* msg)
{
	mtx.lock();
	log(ERROR, module, msg);
	mtx.unlock();
}

void linv::log::warning(const char* module, const char* msg)
{
	mtx.lock();
	log(WARNING, module, msg);
	mtx.unlock();
}

void linv::log::info(const char* module, const char* msg)
{
	mtx.lock();
	log(INFO, module, msg);
	mtx.unlock();
}

void linv::log::debug(const char* module, const char* msg)
{
	mtx.lock();
	log(DEBUG, module, msg);
	mtx.unlock();
}

void linv::log::verbose(const char* module, const char* msg)
{
	mtx.lock();
	log(VERBOSE, module, msg);
	mtx.unlock();
}

void linv::log::setStreamLevel(uint8_t id, LogLevel level)
{
	mtx.lock();
	if (outs[id] == 0) goto exit;
	outs[id]->level = level;
exit:
	mtx.unlock();
}

void linv::log::removeOutput(uint8_t id)
{
}

uint8_t linv::log::addLoggerOutput(std::ostream* stream, LogLevel level, linv::colours::ConsoleColour cFatal = linv::colours::dark_red, linv::colours::ConsoleColour cError = linv::colours::red , linv::colours::ConsoleColour cWarn = linv::colours::dark_yellow, linv::colours::ConsoleColour cInfo = linv::colours::white, linv::colours::ConsoleColour cDebug = linv::colours::white, linv::colours::ConsoleColour cVerbose = linv::colours::cyan)
{
	mtx.lock();
	uint8_t i = 0;
	if (count >= 255) goto err;

	for (; i < 255 && outs[i] != 0; i++);
	if (i == 255) goto err;

	outs[i] = (struct OTuple*)malloc(sizeof(OTuple));
	if (!outs[i]) goto err;
	outs[i]->stream = stream;
	outs[i]->level = level;
	outs[i]->colours[FATAL] = cFatal;
	outs[i]->colours[ERROR] = cError;
	outs[i]->colours[WARNING] = cWarn;
	outs[i]->colours[INFO] = cInfo;
	outs[i]->colours[DEBUG] = cDebug;
	outs[i]->colours[VERBOSE] = cVerbose;

	mtx.unlock();
	return i + 1;
err:
	mtx.unlock();
	return 0;
}

const char* linv::log::getName(LogLevel level)
{
	if (level == FATAL) return "FATAL";
	if (level == ERROR) return "ERROR";
	if (level == WARNING) return "WARNING";
	if (level == INFO) return "INFO";
	if (level == DEBUG) return "DEBUG";
	if (level == VERBOSE) return "VERBOSE";
	return "UNKNOWN";
}

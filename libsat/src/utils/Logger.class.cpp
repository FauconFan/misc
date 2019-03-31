#include "libsat.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <ctime>

Logger::Logger() {
	this->_is_ok = Logger::create_log_dir();

	if (this->_is_ok) {
		std::string name_file;
		std::ofstream * out_log;

		name_file = LOG_FOLDER + Logger::build_date() + ".log";
		out_log   = new std::ofstream();
		out_log->open(name_file);
		if (out_log->is_open() == false) {
			std::cerr << "LOGGER FAILS : fail to create a log file\n";
			this->_is_ok = false;
			delete out_log;
		}
		else {
			this->log_file = out_log;
		}
	}

	if (this->_is_ok == false) {
		this->log_file = &cnull;
	}

	*this->log_file << Logger::build_header() << std::endl;
}

Logger::~Logger() {
	if (this->_is_ok)
		dynamic_cast<std::ofstream *>(this->log_file)->close();
}

Logger Logger::logger;

std::ostream &Logger::info() {
	*(logger.log_file) << Logger::build_header_line("INFO");
	return *(logger.log_file);
}

std::ostream &Logger::warn() {
	*(logger.log_file) << Logger::build_header_line("WARN");
	return *(logger.log_file);
}

void Logger::disable() {
	*(logger.log_file) << "  Logger disabled\n";
	logger._is_ok = false;
	dynamic_cast<std::ofstream *>(logger.log_file)->close();
	logger.log_file = &cnull;
}

bool Logger::create_log_dir() {
	struct stat statbuff {};

	if (stat(LOG_FOLDER, &statbuff) == 0) {
		if (S_ISDIR(statbuff.st_mode) == 0) {
			std::cerr << "LOGGER FAILS : .logs exists and is not a folder\n";
			return (false);
		}
	}
	else {
		char * error_stat = strerror(errno);

		if (mkdir(LOG_FOLDER, 0775) == -1) {
			char * error_mkdir = strerror(errno);

			std::cerr << "LOGGER FAILS : fail to create .logs file\n";
			std::cerr << "stat error : " << error_stat << "\n";
			std::cerr << "mkdir error : " << error_mkdir << "\n";
			return (false);
		}
	}
	return (true);
}

std::string Logger::build_date() {
	std::stringstream ss;
	time_t t;
	struct tm now {};

	t = time(nullptr);
	localtime_r(&t, &now);

	// Year
	ss << (now.tm_year + 1900) << "_";

	// Month
	ss << std::setfill('0') << std::setw(2)
	   << (now.tm_mon + 1) << "_";

	// Day
	ss << std::setfill('0') << std::setw(2)
	   << now.tm_mday << " ";

	// Hour
	ss << std::setfill('0') << std::setw(2)
	   << now.tm_hour << ":";

	// Min
	ss << std::setfill('0') << std::setw(2)
	   << now.tm_min << ":";

	// Sec
	ss << std::setfill('0') << std::setw(2)
	   << now.tm_sec;

	return (ss.str());
} // Logger::build_date

std::string Logger::build_header() {
	std::string res;

	for (size_t i = 0; i < 80; i++)
		res += "#";
	res += "\n";
	for (size_t i = 0; i < 5; i++)
		res += "#";
	for (size_t i = 5; i < 75; i++)
		res += " ";
	for (size_t i = 75; i < 80; i++)
		res += "#";
	res += "\n";
	for (size_t i = 0; i < 5; i++)
		res += "#";
	for (size_t i = 5; i < 35; i++)
		res += " ";
	res += "LIBSAT LOG";
	for (size_t i = 45; i < 75; i++)
		res += " ";
	for (size_t i = 75; i < 80; i++)
		res += "#";
	res += "\n";
	for (size_t i = 0; i < 5; i++)
		res += "#";
	for (size_t i = 5; i < 75; i++)
		res += " ";
	for (size_t i = 75; i < 80; i++)
		res += "#";
	res += "\n";
	for (size_t i = 0; i < 80; i++)
		res += "#";
	res += "\n\n";
	res += "[" + Logger::build_date() + "]\n";
	res += "  Libsat initialised\n";
	res += "  Logger ok\n";
	return (res);
} // Logger::build_header

std::string Logger::build_header_line(const std::string & tag) {
	std::string res;

	res += "\n";
	res += "[" + Logger::build_date() + "]";
	res += " ==================== " + tag + " ====================\n";
	return (res);
}

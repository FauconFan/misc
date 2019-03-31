#ifndef LOGGER_CLASS_HPP
#define	LOGGER_CLASS_HPP

#include <fstream>

#define	LOG_FOLDER ".logs/"

class Logger
{
	public:
		Logger(const Logger &) = delete;
		Logger &operator=(const Logger &) = delete;

		static std::ostream &info();
		static std::ostream &warn();

	private:
		Logger();
		virtual~Logger();

		// static private functions
		static bool create_log_dir();
		static std::string build_date();
		static std::string build_header();
		static std::string build_header_line(const std::string & tag);

		bool _is_ok {true};
		std::ostream * log_file {nullptr};

		static Logger logger;
};


#endif // ifndef LOGGER_CLASS_HPP

#pragma once

#include <string>

namespace world_base {
namespace debug {
    class Logger {
    public:
        static void info(const std::string& message, const char* file_name, int code_line, const char* function_name);
        static void warning(const std::string& message, const char* file_name, int code_line, const char* function_name);
        static void error(const std::string& message, const char* file_name, int code_line, const char* function_name);
        static void config(const std::string& message, const char* file_name, int code_line, const char* function_name);

        static void info(const char* message, const char* file_name, int code_line, const char* function_name);
        static void warning(const char* message, const char* file_name, int code_line, const char* function_name);
        static void error(const char* message, const char* file_name, int code_line, const char* function_name);
        static void config(const char* message, const char* file_name, int code_line, const char* function_name);
    };

#ifdef _DEBUG
    #define LOGINFO(message) Logger::info(message, __FILE__, __LINE__, __FUNCTION__)
    #define LOGWARN(message) Logger::warning(message, __FILE__, __LINE__, __FUNCTION__)
    #define LOGERROR(message) Logger::error(message, __FILE__, __LINE__, __FUNCTION__)
    #define LOGCONFIG(message) Logger::config(message, __FILE__, __LINE__, __FUNCTION__)
#else
    #define LOGINFO(message)
#endif

}
}
#include "log.h"

#include "../helper/define.h"

#ifdef WINDOWS_OS
#include <iostream>
#include "Windows.h"
#else
#include <third_party/sdl2/SDL_log.h>
#endif

namespace world_base {
namespace debug {
#ifdef WINDOWS_OS
    void logger_print_message(const char* message, const char* file_name, int code_line, const char* function_name, int color) {
        HANDLE console_handler = GetStdHandle(STD_OUTPUT_HANDLE);

        std::string file_name_str = file_name;
        file_name_str = file_name_str.substr(file_name_str.find_last_of("\\") + 1);

        // grey white
        SetConsoleTextAttribute(console_handler, color);
        std::cout << file_name_str << "::" << function_name << "::" << code_line << ": " << message << std::endl;

        // set default color
        SetConsoleTextAttribute(console_handler, 7);
    }

    void Logger::info(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 15);
    }

    void Logger::warning(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 14);
    }

    void Logger::error(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 12);
    }

    void Logger::config(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 10);
    }

    void Logger::info(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 15);
    }

    void Logger::warning(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 14);
    }

    void Logger::error(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 12);
    }

    void Logger::config(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 10);
    }
#else
    enum MessageLevel {
        INFO_MSG, WARNING_MSG, ERROR_MSG, CONFIG_MSG
    };

    void logger_print_message(const char* message, const char* file_name, int code_line, const char* function_name, MessageLevel level) {
        std::string file_name_str = file_name;
        file_name_str = file_name_str.substr(file_name_str.find_last_of("\\") + 1);

        std::string message_str = file_name_str;
        message_str.append("::").append(function_name).append("::").append(std::to_string(code_line)).append(": ").append(message);

        switch (level) {
            case INFO_MSG:
                SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, message_str.c_str());
                break;
            case WARNING_MSG:
                SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, message_str.c_str());
                break;
            case ERROR_MSG:
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, message_str.c_str());
                break;
            case CONFIG_MSG:
                SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, message_str.c_str());
                break;
        }
    }

    void Logger::info(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, INFO_MSG);
    }

    void Logger::warning(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, WARNING_MSG);
    }

    void Logger::error(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, ERROR_MSG);
    }

    void Logger::config(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, CONFIG_MSG);
    }

    void Logger::info(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, INFO_MSG);
    }

    void Logger::warning(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, WARNING_MSG);
    }

    void Logger::error(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, ERROR_MSG);
    }

    void Logger::config(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, CONFIG_MSG);
    }
#endif
    
}
}
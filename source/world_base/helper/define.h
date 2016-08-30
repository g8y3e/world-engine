#pragma once

#if defined(WIN32) || defined(_WIN32) || (defined(_WIN32) && !defined(__CYGWIN__))
	#define WINDOWS_OS
	#if defined(_WIN64)
		#define WINDOWS_OS_64
	#endif
#elif defined(__APPLE__)
	#define APPLE_OS
	#if defined(TARGET_IPHONE_SIMULATOR)
		#define IPHONE_SIMULATOR
	#elif defined(TARGET_OS_IPHONE)
		#define IPHONE_OS
	#elif defined(TARGET_OS_MAC)
		#define MAC_OS
	#endif
#elif defined(__linux__)
	#define LINUX_OS
#elif defined(__unix__)
	#define UNIX_OS
#else
	#define UNKNOWN_OS
#endif
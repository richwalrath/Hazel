#pragma once

#include <memory>

// Platform Detection using predifined macros
#ifdef _WIN32 // Windows x86

	#ifdef _WIN64
		#define HZ_PLATFORM_WINDOWS
	#else
		#error "Hazel does not support x86!"
	#endif

#elif defined(__APPLE__) || defined(__MACH__) // Apple/Mac

	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms so we must check all of them (in this order) to ensure
	 * that we are running on MAC and not some other Apple platform
	 */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define HZ_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define HZ_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif

#elif defined(__ANDROID__) // Andriod

	/* We also have to check __ANDROID__ before __linux__ since android is based on the linux kernel it
	 * has __linux__ defined.
	 */
	#define HZ_PLATFORM_ANDROID
	#error "Android is not supported!"

#elif defined(__linux__) // Linux

	#define HZ_PLATFORM_LINUX
	#error "Linux is not supported!"

#else

	#error "Unknown platform!"

#endif // End Platform Detection

// Bit Shifting
#define BIT(x) (1 << x) // Left

// Event Binding
#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// Aliases
namespace Hazel {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
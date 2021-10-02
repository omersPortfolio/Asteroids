#pragma once

#ifdef T_ENABLE_ASSERTS
	#define T_ASSERT(x, ...) { if(!x) { LOG(ERROR, "Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define T_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
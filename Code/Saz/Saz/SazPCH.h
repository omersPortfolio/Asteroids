#pragma once

#ifndef NOMINMAX
# define NOMINMAX
#endif

#ifdef SAZ_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <windowsx.h>
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>
#include <fstream>  
#include <iostream>
#include <filesystem>

#include <map>
#include <vector>
#include <queue>
#include <string>
#include <set>

#include <Core/DynamicArray.h>
#include <Core/Map.h>
#include <Core/Math.h>
#include <Core/String.h>
#include <Core/Vector.h>
#include <Core/Random.h>

#include "Saz/Core.h"
#include "Saz/Input.h"
#include "Saz/KeyCodes.h"
#include "Saz/MouseButtonCodes.h"
#include "Saz/Entity.h"
#include "Saz/TypeId.h"
#include "Saz/SpdLog.h"
#include "Saz/ImGui/ImGuiLog.h"
#include <Saz/ImGui/ImGuiLayer.h>
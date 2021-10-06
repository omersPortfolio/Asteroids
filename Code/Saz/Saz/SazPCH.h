#pragma once

#ifndef NOMINMAX
# define NOMINMAX
#endif

#ifdef SAZ_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <windowsx.h>
#endif


#include <assert.h>
#include <filesystem>
#include <fstream>  
#include <iostream>
#include <malloc.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <Core/DynamicArray.h>
#include <Core/Map.h>
#include <Core/Input.h>
#include <Core/Math.h>
#include <Core/FilePath.h>
#include <Core/Random.h>
#include <Core/Set.h>
#include <Core/String.h>
#include <Core/Vector.h>

#include "Saz/Core.h"
#include "Saz/Entity.h"
#include "Saz/TypeId.h"
#include "Saz/SpdLog.h"
#include "Saz/ImGui/ImGuiLog.h"
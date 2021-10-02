#pragma once

#ifndef NOMINMAX
# define NOMINMAX
#endif

#include <Windows.h>
#include <windowsx.h>

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
#include <Core/StringView.h>
#include <Core/Vector.h>
#include <Core/Random.h>

#include "Framework/Core.h"
#include "Framework/Entity.h"
#include "Framework/TypeId.h"
#include "Framework/ImGuiLog.h"
#include "Framework/SpdLog.h"
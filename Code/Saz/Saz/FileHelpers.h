#pragma once

#include <Core/Vector.h>

namespace Saz::file
{
	char* LoadCompleteFile(const char* filename, long* length);

	typedef rapidjson::PrettyWriter<rapidjson::StringBuffer> WriterType;

	void JSONSaveCharArray(WriterType& writer, const char* key, const char* type);
	void JSONSaveInt(WriterType& writer, const char* key, int value);
	void JSONSaveVec2(WriterType& writer, const char* key, vec2 value);

	void JSONLoadInt(rapidjson::Value& object, const char* key, int* value);
	void JSONLoadVec2(rapidjson::Value& object, const char* key, vec2* value);
}
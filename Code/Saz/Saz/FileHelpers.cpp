#include "SazPCH.h"
#include "FileHelpers.h"

namespace Saz
{
	char* LoadCompleteFile(const char* filename, long* length)
	{
		char* filecontents = 0;

		FILE* filehandle;
		errno_t error = fopen_s(&filehandle, filename, "rb");

		if (filehandle)
		{
			fseek(filehandle, 0, SEEK_END);
			long size = ftell(filehandle);
			rewind(filehandle);

			filecontents = new char[size + 1];
			fread(filecontents, size, 1, filehandle);
			filecontents[size] = 0;

			if (length)
				*length = size;

			fclose(filehandle);
		}

		return filecontents;
	}
}
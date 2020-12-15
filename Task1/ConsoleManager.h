#pragma once
#include "..\AdditionalClasses\Console.h"
#include "Field.h"
using ISXConsole::Console;

namespace ISXManager
{
	class ConsoleManager : public Console
	{
	public:
		static void DrawField(const ISXField::Field* field);
	};

}


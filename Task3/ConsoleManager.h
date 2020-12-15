#pragma once
#include "..\AdditionalClasses\Console.h"

using ISXConsole::Console;

namespace ISXConsole
{
	class ConsoleManager : public Console
	{
	public:
		static bool WantContinue();
		static string GetTriangleParameters();

	};
}


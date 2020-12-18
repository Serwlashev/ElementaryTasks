#pragma once

#include "..\AdditionalClasses\Console.h"

using ISXConsole::Console;

namespace ISXManagerConsole
{
	class ConsoleMngr : public Console
	{
	public:
		static void PrintInstruction();
		static bool WantContinue();
		static string EnterNumber(string text);
	};

}

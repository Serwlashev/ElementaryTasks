#pragma once
#include "..\AdditionalClasses\Console.h"

using ISXConsole::Console;

namespace ISXConsoleMngr
{
	class ConsoleManager : public Console
	{
	public:
		static bool WantContinue();
		static string GetEnvelopeSide(const string& side_name);

	private:
		
	};
}


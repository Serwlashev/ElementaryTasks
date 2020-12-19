#pragma once
#include "..\AdditionalClasses\Console.h"
#include "Field.h"
using ISXConsole::Console;
using ISXField::Field;

namespace ISXManager
{
	class ConsoleManager : public Console
	{
	public:
		static void DrawField(const std::unique_ptr<Field>& field);
	};

}


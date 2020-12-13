#pragma once
#include <iostream>
#include <string>

#include "Field.h"

namespace Console
{
	class ConsoleManager
	{
	public:
		static void PrintErrorMessage(const std::string& message);
		static void DrawField(const ISXField::Field* field);
	};

}


#pragma once
#include <iostream>
#include <string>
#include "Field.h"

using ISXField::Field;

namespace ISXManager
{
	class ConsoleManager
	{
	public:
		static void DrawField(const std::unique_ptr<Field>& field);
		static void PrintMessage(const std::string& message);
	};

}


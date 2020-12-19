#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

namespace ISXConsole
{
	class Console
	{
	public:
		static bool WantContinue();
		static void PrintMessage(const string& message);
		static string GetStringValue(const string& message);
	};
}


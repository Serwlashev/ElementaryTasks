#pragma once
#include <iostream>
#include <string>
using std::string;

namespace ISXEnvConsole
{
	class EnvelopeView
	{
	public:
		static bool WantContinue();
		static void PrintMessage(const string& message);
		static string GetStringValue(const string& message);
	};

}

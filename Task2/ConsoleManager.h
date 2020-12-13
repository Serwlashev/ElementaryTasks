#pragma once
#include <iostream>
#include <string>

namespace ISXConsole
{
	class ConsoleManager
	{
	public:
		static bool WantContinue();
		static void GetEnvelopeSize(const std::string& name, double& height, double&  width);
		static void PrintMessage(const std::string& msg);
		static void PrintInstruction();

	private:
		static double ConvertToDouble(const std::string& str);
		static bool HasStringOnlyDigitsPoint(const std::string& str);
	};
}


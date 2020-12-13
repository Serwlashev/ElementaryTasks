#pragma once
#include <iostream>
#include <string>

namespace ISXConsole
{
	class ConsoleManager
	{
	public:
		static bool WantContinue();
		static void GetTriangleValues(std::string& name, double& first_side, double& second_side, double& thirs_side);
		static void PrintMessage(const std::string& msg);
		static void PrintInstruction();

	private:
		static void ExtractParamsFromString(std::string params, std::string& name, double& first_side, double& second_side, double& thirs_side);
		static double ConvertToDouble(const std::string& str);
		static bool HasStringOnlyDigitsPoint(const std::string& str);
	};
}


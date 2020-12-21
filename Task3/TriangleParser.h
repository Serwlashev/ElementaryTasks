#pragma once
#include <string>
namespace ISXTriangleParser
{
	class TriangleParser
	{
	public:
		static double ParseToDouble(const std::string& number);
		static bool IsValid(const std::string& number);
	};
}


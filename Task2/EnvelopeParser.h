#pragma once
#include <string>
namespace ISXEnvelopeParser
{
	class EnvelopeParser
	{
	public:
		static double ParseToDouble(const std::string& number);
	private:
		static bool IsValid(const std::string& number);
	};

}
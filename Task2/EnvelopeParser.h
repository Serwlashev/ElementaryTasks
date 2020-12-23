#pragma once
#include <string>
namespace ISXEnvelopeParser
{
	class EnvelopeParser
	{
	public:
		static double ParseToDouble(const std::string& number);
	private:
		static const int max_allowed_length = 15;

		static bool IsValid(const std::string& number);
	};

}
#pragma once
#include <string>
#include <map>

namespace ISXConverter
{

	class NumberToTextConverter
	{
	public:
		NumberToTextConverter();

		std::string Convert(int number);
	private:
		enum NumericDigits {
			BILLION = 1000000000,
			MILLION = 1000000,
			THOUSAND = 1000,
			HUNDRED = 100,
			TEN = 10
		};

		void InitLibrary();
		std::string ConvertFromThreeDigits(int number);

		std::map<int, std::string> library;
	};


}


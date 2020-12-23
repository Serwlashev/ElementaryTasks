#pragma once
#include <iostream>
#include <string>
#include <map>
#include <list>

namespace ISXNumberConverter
{
	class NumberToTextConverter
	{
	public:
		NumberToTextConverter();

		std::string Convert(int number);

	private:
		enum NumericDigitsDelimiters {
			THOUSAND_DELIMITER = 1000,
			HUNDRED_DELIMITER = 100,
			LIBRARY_DELIMITER = 20,		// Bigger dozens are not included in the library
			DOZENS_DELIMITER = 10,
			MIN_DELIMITER = 1
		};

		void InitLibrary();
		std::string ConvertFromThreeDigits(int number);
		std::list<int> PushToList(int number) const;
		std::string MakeStringFromList(std::list<int> number_parts);
		std::string GetNumberRank(int number_rank) const;

		std::map<int, std::string> m_library;
	};


}


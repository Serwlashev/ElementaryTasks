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
		enum NumericDigits {
			BILLION = 1000000000,
			MILLION = 1000000,
			THOUSAND = 1000,
			HUNDRED = 100,
		};

		void InitLibrary();
		std::string ConvertFromThreeDigits(int number);
		std::list<int> PushToList(int number) const;
		std::string MakeStringFromList(std::list<int> number_parts);
		std::string GetNumberRank(int number_rank) const;

		std::map<int, std::string> m_library;
	};


}


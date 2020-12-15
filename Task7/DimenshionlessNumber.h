#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
namespace ISXNumber
{
	class LoongNumber
	{
	public:
		void EnterString(const std::string& value);
		void ShowSqrt() const;
	private:
		std::vector<short> GetSqrt() const;
		std::vector<short> MakeReverseNumber(const std::vector<short>& numbers) const;

		std::vector<short> m_number;
	};
}


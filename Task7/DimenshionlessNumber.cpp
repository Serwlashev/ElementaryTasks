#include "DimenshionlessNumber.h"

void ISXNumber::LoongNumber::EnterString(const std::string& value)
{
	for (int i = value.length() - 1; i >= 0; i--) {		// Fill number in the reverse order
		int n = value[i];
		m_number.push_back(value[i] - '0');
	}

	m_number = GetSqrt();							
}

void ISXNumber::LoongNumber::ShowSqrt() const
{
	for (auto it = m_number.begin(); it != m_number.end(); it++) {
		std::cout << *it;
	}
}

std::vector<short> ISXNumber::LoongNumber::GetSqrt() const
{
	std::vector<short> tmp_res;
	tmp_res.resize(m_number.size() * 2);

	for (int i = 0; i < m_number.size(); i++) {								// Get square of the number using simple multiplication
		int carry = 0;														// Part of the number which we should carry to the next number
		for (int j = 0; j < m_number.size(); j++) {
			tmp_res.at(i+j) += m_number.at(i) * m_number.at(j) + carry;		// Get current number with carry part
			carry = tmp_res.at(i + j) / 10;									// Identify carry part
			tmp_res.at(i + j) -= carry * 10;								// Get right number on the its position
		}
	}

	 return MakeReverseNumber(tmp_res);
}

std::vector<short> ISXNumber::LoongNumber::MakeReverseNumber(const std::vector<short>& numbers) const
{
	std::vector<short> result;

	bool was_num = false;
	for (auto it = numbers.rbegin(); it != numbers.rend(); it++) {			// Return number to the its normal order
		if (!was_num && *it == 0) {
			was_num = true;
			continue;
		}
		std::cout << *it;
		result.push_back(*it);
	}
	return result;
}


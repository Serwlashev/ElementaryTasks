
#include "ChessboardParser.h"

namespace ISXChessParser {

	unsigned int ChessboardParser::ParseToUI(const std::string& number)
	{
	
		unsigned int res = 0U;
	
		if (!number.empty() && number != " " && number.size() < max_allowed_length && HasOnlyDigits(number)) {
	
			res = std::stoi(number);
		}
	
		return res;
	}
	
	bool ChessboardParser::HasOnlyDigits(const std::string& number)
	{
	
		for (size_t i = 0; i < number.length(); i++) {
			if (!isdigit(number[i])) {
				return false;
			}
		}
		return true;
	}
	
} // namespace ISXChessParser

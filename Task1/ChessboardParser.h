#pragma once
#include <string>

namespace ISXChessParser {

    class ChessboardParser {
    public:
        static unsigned int ParseToUI(const std::string& number);
    
    private:
        static const int max_allowed_length = 9;
        static bool HasOnlyDigits(const std::string& number);
    };

}

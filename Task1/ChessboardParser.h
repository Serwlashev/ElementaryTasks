#pragma once
#include <string>

namespace ISXChessParser {

    class ChessboardParser {
    public:
        static unsigned int ParseToUI(const std::string& number);
    
    private:
        static bool HasOnlyDigits(const std::string& number);
    };

}

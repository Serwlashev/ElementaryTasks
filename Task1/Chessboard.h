#pragma once
#include <vector>

#include "Field.h"

namespace ISXChessboard {

    class ChessBoard : public ISXField::Field
    {
    public:
        ChessBoard(unsigned int height, unsigned int width);
    
        unsigned int get_height() const override ;
        unsigned int get_width() const override;
        char operator ()(const size_t height, const size_t width) const override;
    
    private:
        std::vector<std::vector<ISXCell::Cell>> FillField();
    };

}

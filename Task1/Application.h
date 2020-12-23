#pragma once
#include <string>
#include <memory>

#include "Field.h"
#include "ConsoleManager.h"
#include "ChessboardFactory.h"

namespace ISXApplication {

    class Application {
    public:
        // The method prints the chess field according to entered parameters - height and width
        void Start(const int argc, char ** argv);
        std::vector<std::vector<ISXCell::Cell>> GetField() const;
        
    private:
        const int num_required_params = 3;

        void PrintField() const;
    
        std::unique_ptr<ISXField::Field> m_field;
        ISXBoardFactory::ChessboardFactory m_board_creator;
    };

}

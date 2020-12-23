#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Cell.h"

namespace ISXManager {

    class ConsoleManager {
      public:
        static void DrawField(const std::vector<std::vector<ISXCell::Cell>>& field);
    
        static void PrintMessage(const std::string & message);
    };

}

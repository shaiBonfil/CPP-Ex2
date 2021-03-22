// #pragma once
#include <iostream>
#include "Direction.hpp"

using namespace std;

namespace ariel{

    class Board{
        public:

            void post(unsigned int row, unsigned int column, Direction d, string message);
            string read(unsigned int row, unsigned int column, Direction d, unsigned int length);
            string show();
    };
};
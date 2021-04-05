#include <string>
#include "Direction.hpp"
#include <map>
#include <iostream>
#include <stdexcept>
#include <limits.h>

using namespace std;

namespace ariel
{

    class Board
    {

    private:
        //define object holds the raw and the col on the borad
        map<pair<uint, uint>, char> board;
        uint max_row;
        uint min_row;
        uint max_col;
        uint min_col;

    public:
        Board()
        { // constructor
            max_row = max_col = 0;
            min_row = min_col = UINT_MAX;
        }
        ~Board() {} // destructor

        void post(uint row, uint col, Direction d, string message);
        string read(uint row, uint col, Direction d, uint len);
        void show();
    };
}
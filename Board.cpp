#include <iostream>
#include "Board.hpp"
using namespace std;
using namespace ariel;

namespace ariel{

    void Board::post(unsigned int row, unsigned int column, Direction d, string message) {
        cout << "post() function" << endl;
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {
        cout << "read() function" << endl;
        return "";
    }

    string Board::show() {
        return "";
    }
    
};
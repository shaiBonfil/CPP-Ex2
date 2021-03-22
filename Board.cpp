#include "Board.hpp"
// #include <iostream>
// using namespace std;


namespace ariel{

    string Board::show() {
        cout << "show()" << endl;
        return "";
    }

    void Board::post(unsigned int row, unsigned int column, Direction d, string message) {
        cout << "post()" << endl;
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {
        cout << "read()" << endl;
        return "";
    }



    
};
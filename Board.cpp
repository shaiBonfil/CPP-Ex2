#include <stdexcept>
#include "Board.hpp"
#include <iostream>
#include <map>
using namespace std;
using namespace ariel;

const char DEFAULT = '_';

//make_pair(row, col)  // make_pair(inner, message.at(i))

namespace ariel
{

    void Board::post(uint row, uint col, Direction d, string message)
    {
        for (int i = 0; i < message.length(); i++)
        {
            this->max_row = max(this->max_row, row);
            this->max_col = max(this->max_col, col);
            this->min_row = min(this->min_row, row);
            this->min_col = min(this->min_col, col);
            
            inner.insert({row, col});
            board.insert({inner, message.at(i)});
            if (d == Direction::Vertical)
            { //if the direction is Vertical than move row +1
                row++;
            }
            else
            { // if the direction is Horizontal than move col +1 for next char
                col++;
            }
        }
    }

    string Board::read(uint row, uint col, Direction d, uint len)
    {
        char c = DEFAULT;
        string res;
        inner.insert({row, col});

        for (int i = 0; i < len; i++)
        {
            if (board.count(inner))
            {
                c = board.at(inner);
                res += c;
            }
            else
            {
                c = DEFAULT;
                res += c;
            }
            if (d == Direction::Vertical)
            { //if the direction is Vertical than move row +1
                row++;
            }
            else
            { // if the direction is Horizontal than move col +1 for next char
                col++;
            }
        }
        return res;
    }
    void Board::show()
    {
        for (uint i = (this->min_row)-1; i <= (this->max_row); i++)
        {
            cout << i << ": ";
            for (uint j = (this->min_col); j <= (this->max_col + 1); j++)
            {
                inner.insert({i, j});
                if (board.count(inner))
                {
                    cout << board.at(inner) << endl;
                }
                else
                {
                    cout << DEFAULT << endl;
                }
            }
        }
    }
}
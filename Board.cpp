#include <stdexcept>
#include "Board.hpp"
#include <iostream>
#include <map>
using namespace std;
using namespace ariel;

const char DEFAULT = '_';

namespace ariel
{

    void Board::post(uint row, uint col, Direction d, string message)
    {
        this->min_row = min(this->min_row, row);
        this->max_row = max(this->max_row, row);
        this->min_col = min(this->min_col, col);
        this->max_col = max(this->max_col, col);

        pair<uint, uint> inner;
        
        if (d == Direction::Vertical)
        {
            for (ulong i = 0; i < message.length(); i++)
            {
                inner.first = row;
                inner.second = col;
                board.insert({inner, message.at(i)});
                row++;
            }
        }
        else
        {
            for (ulong i = 0; i < message.length(); i++)
            {
                inner.first = row;
                inner.second = col;
                board.insert({inner, message.at(i)});
                col++;
            }
        }
    }

    string Board::read(uint row, uint col, Direction d, uint len)
    {
        pair<uint, uint> inner;
        char c = DEFAULT;
        string res;

        if (d == Direction::Vertical)
        {
            for (ulong i = 0; i < len; i++)
            {
                inner.first = row;
                inner.second = col;
                if (board.count(inner) != 0)
                {
                    c = board.at(inner);
                    res += c;
                }
                else
                {
                    c = DEFAULT;
                    res += c;
                }
                row++;
            }
        }
        else
        {
            for (ulong i = 0; i < len; i++)
            {
                inner.first = row;
                inner.second = col;
                if (board.count(inner) != 0)
                {
                    c = board.at(inner);
                    res += c;
                }
                else
                {
                    c = DEFAULT;
                    res += c;
                }
                col++;
            }
        }
        return res;
    }

    void Board::show()
    {
        pair<uint, uint> inner;
        char c = DEFAULT;
        for (uint i = (this->min_row); i < (this->max_row); i++)
        {
            cout << i << ": ";
            for (uint j = (this->min_col); j < (this->max_col); j++)
            {
                inner.first = i;
                inner.second = j;
                c = board.at(inner);
                cout << c << endl;
            }
        }
    }
}
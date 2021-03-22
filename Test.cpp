/**
 * 
 * AUTHOR: <Shai Bonfil>
 * 
 */

#include <iostream>
#include <string>

#include "doctest.h"
#include "Board.hpp"
using namespace std;
using namespace ariel;

Board b;

TEST_CASE("read from empty board")
{
    CHECK(b.read(0, 0, Direction::Horizontal, 3) == string("___"));
    CHECK(b.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(b.read(23, 74, Direction::Horizontal, 2) == string("__"));
    CHECK(b.read(110, 42, Direction::Vertical, 2) == string("__"));
    CHECK_FALSE(b.read(2, 3, Direction::Horizontal, 3) == string("abc"));
}

TEST_CASE("post message to the board, and read it")
{
    CHECK_NOTHROW(b.post(100, 150, Direction::Horizontal, "shai"));
    CHECK((b.read(100, 150, Direction::Horizontal, 4)) == string("shai"));
    CHECK_NOTHROW(b.post(130, 170, Direction::Vertical, "bonfil"));
    CHECK(b.read(130, 170, Direction::Vertical, 6) == string("bonfil"));
    CHECK_NOTHROW(b.post(200, 200, Direction::Vertical, "cpp"));
    CHECK_NOTHROW(b.post(203, 200, Direction::Vertical, "ex2"));
    CHECK(b.read(200, 200, Direction::Vertical, 6) == string("cppex2"));
    CHECK(b.read(199, 200, Direction::Vertical, 8) == string("_cppex2_"));
    CHECK_NOTHROW(b.post(80, 76, Direction::Horizontal, "board"));
    CHECK_NOTHROW(b.post(80, 79, Direction::Horizontal, "message"));
    CHECK(b.read(80, 76, Direction::Horizontal, 10) == string("boamessage"));
    CHECK_NOTHROW(b.post(53, 20, Direction::Horizontal, "null"));
    CHECK_NOTHROW(b.post(53, 20, Direction::Horizontal, "override"));
    CHECK(b.read(53, 20, Direction::Horizontal, 10) == string("override__"));
}

TEST_CASE("read a zero characters")
{
    CHECK(b.read(0, 0, Direction::Vertical, 0) == "");
    CHECK(b.read(0, 0, Direction::Horizontal, 0) == "");
}


#ifndef _COORDINATE_H
#define _COORDINATE_H

#include <iostream>

class Coordinate {
public:
    int m_row;
    int m_col;

    Coordinate(int, int);

    bool operator!=(Coordinate coordinate);
};

std::ostream& operator<<(std::ostream& output, Coordinate coordinate);

#endif
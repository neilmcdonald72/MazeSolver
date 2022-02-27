#include "coordinate.h"

Coordinate::Coordinate(int row, int col)
        : m_row(row)
        , m_col(col) {
}

bool Coordinate::operator!=(Coordinate coordinate) {
    return (this->m_row != coordinate.m_row) || (this->m_col != coordinate.m_col);
}


std::ostream& operator<<(std::ostream& output, Coordinate coordinate) {
    output << "Coordinate: " << coordinate.m_row << "/" << coordinate.m_col;
    return output;
}
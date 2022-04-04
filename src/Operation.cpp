#include <iostream>
#include "Operation.hh"

/**
 * @brief Construct a new Operation object.
 * 
 * @param row Row number.
 * @param col Column number.
 * @param state New cell state.
 */
Operation::Operation(const int row, const int col, const CellState state)
    : row(row),
        col(col),
        state(state) {
    // do nothing
}

std::ostream& operator <<(std::ostream& os, const Operation& op) {
    os << "Operation["
        << "row=" << op.row
        << ", col=" << op.col
        << ", state=";

    switch (op.state) {
        case CellState::ALIVE: os << "ALIVE"; break;
        case CellState::DEAD:  os << "DEAD";  break;
    }

    os << "]";

    return os;
}

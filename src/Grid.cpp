#include <iostream>
#include <string>
#include "Grid.hh"

/**
 * @brief Construct a new Grid object. Initializes grid to CellState::DEAD.
 * 
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
Grid::Grid(const int rows, const int cols)
    : numRows(rows),
        numCols(cols),
        vec(rows*cols, CellState::DEAD) {
    // do nothing
}

/**
 * @brief Construct a new Grid object. Initializes grid to initGrid.
 * 
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param initGrid Initializer grid.
 */
Grid::Grid(const int rows, const int cols, const std::vector<bool> initGrid)
    : numRows(rows),
        numCols(cols),
        vec(rows * cols, CellState::DEAD) {
    // initialize the live cells in the game grid based on the init grid
    for (int i {0}; i < initGrid.size(); i++) {
        if (initGrid[i]) {
            vec[i] = CellState::ALIVE;
        }
    }
}

/**
 * @brief Convert a row/column index to an array index.
 * 
 * @param row Row number.
 * @param col Column number.
 * @return int Array index.
 */
int Grid::cellToIndex(const int row, const int col) const {
    return (row * numCols) + col;
}

/**
 * @brief Get the state of the specified cell.
 * 
 * @param row Row number.
 * @param col Column number.
 * @return CellState State of the specified cell.
 */
CellState Grid::get(const int row, const int col) const {
    return vec[cellToIndex(row, col)];
}

/**
 * @brief Get the state of the specified cell (as a std::string).
 * 
 * @param row Row number.
 * @param col Column number.
 * @return CellState State of the specified cell (as a std::string).
 */
std::string Grid::getString(const int row, const int col) const {
    switch (get(row, col)) {
        case CellState::ALIVE: return "ALIVE"; break;
        case CellState::DEAD:  return "DEAD";  break;
        default: return "ERROR"; break;
    }
}

/**
 * @brief Set the state of the specified cell.
 * 
 * @param row Row number.
 * @param col Column number.
 * @param value State of the specified cell.
 */
void Grid::set(const int row, const int col, const CellState value) {
    vec[cellToIndex(row, col)] = value;
}

std::ostream& operator <<(std::ostream &os, const Grid &grid) {
    const std::string divider ((grid.numCols * 2) + 2, '-');

    os << divider << std::endl;
    for (int row {0}; row < grid.numRows; row++) {
        os << "|";
        for (int col {0}; col < grid.numCols; col++) {
            if (grid.get(row, col) == CellState::ALIVE) {
                os << "◼ ";
            } else {
                os << "  ";
            }
        }
        os << "|" << std::endl;
    }
    os << divider;

    return os;
}

/*************************************************************************
PURPOSE: (Contains the current state of the sim world)
**************************************************************************/

#include <string>
#include <vector>
#include "CellState.hh"

/**
 * @brief Contains the current state of the sim world.
 */
class Grid {

    public:

        /**
         * @brief Construct a new Grid object. Initializes grid to CellState::DEAD.
         * 
         * @param rows Number of rows.
         * @param cols Number of columns.
         */
        Grid(const int rows, const int cols);

        /**
         * @brief Construct a new Grid object. Initializes grid to initGrid.
         * 
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param initGrid Initializer grid.
         */
        Grid(const int rows, const int cols, const std::vector<bool> initGrid);

        /**
         * @brief Number of rows.
         */
        const int numRows;

        /**
         * @brief Number of columns.
         */
        const int numCols;

        /**
         * @brief Get the state of the specified cell (as a std::string).
         * 
         * @param row Row number.
         * @param col Column number.
         * @return CellState State of the specified cell.
         */
        CellState get(const int row, const int col) const;

        /**
         * @brief Get the state of the specified cell (as a std::string).
         * 
         * @param row Row number.
         * @param col Column number.
         * @return CellState State of the specified cell (as a std::string).
         */
        std::string getString(const int row, const int col) const;

        /**
         * @brief Set the state of the specified cell.
         * 
         * @param row Row number.
         * @param col Column number.
         * @param value State of the specified cell.
         */
        void set(const int row, const int col, const CellState value);

        friend std::ostream& operator <<(std::ostream& os, const Grid& grid);

    private:

        std::vector<CellState> vec;

        /**
         * @brief Convert a row/column index to an array index.
         * 
         * @param row Row number.
         * @param col Column number.
         * @return int Array index.
         */
        int cellToIndex(const int row, const int col) const;

};

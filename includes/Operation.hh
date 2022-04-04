/*************************************************************************
PURPOSE: (Represents a change in state of the sim grid)
**************************************************************************/

#include <iostream>
#include "CellState.hh"

/**
 * @brief Represents a change in state of the sim grid.
 */
class Operation {

    public:

        /**
         * @brief Construct a new Operation object.
         * 
         * @param row Row number.
         * @param col Column number.
         * @param state New cell state.
         */
        Operation(const int row, const int col, const CellState state);

        /**
         * @brief Row number.
         */
        const int row;

        /**
         * @brief Column number.
         */
        const int col;

        /**
         * @brief New cell state.
         */
        const CellState state;

        friend std::ostream& operator <<(std::ostream& os, const Operation& op);

};

/*************************************************************************
PURPOSE: (Represents the current state of a single cell)
**************************************************************************/

#ifndef _cellstate_hh_
#define _cellstate_hh_

/**
 * @brief Represents the current state of a single cell.
 */
enum class CellState {
    /**
     * @brief Cell is dead.
     */
    DEAD,

    /**
     * @brief Cell is alive.
     */
    ALIVE
};

#endif

/*************************************************************************
PURPOSE: (Represents the current state of the sim world)
**************************************************************************/

#include <vector>
#include "Grid.hh"
#include "Operation.hh"

/**
 * @brief Represents the current state of the sim world.
 */
class Sim {

    public:

        /**
         * @brief Construct a new Sim object. Initializes grid to CellState::DEAD.
         * 
         * @param rows Number of rows.
         * @param cols Number of columns.
         */
        Sim(const int rows, const int cols);

        /**
         * @brief Construct a new Sim object. Initializes grid to initGrid.
         * 
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param initGrid Initializer grid.
         */
        Sim(const int rows, const int cols, const std::vector<bool> initGrid);

        /**
         * @brief Get the current generation count.
         * 
         * @return int Current generation count.
         */
        int getGeneration() const;

        /**
         * @brief Determine if the specified cell is alive.
         * 
         * @param row Row number.
         * @param col Column number.
         * @return If the specified cell is alive.
         */
        bool isCellAlive(const int row, const int col) const;

        /**
         * @brief Determine if there are any live cells.
         * 
         * @return If there are live cells.
         */
        bool isAnyCellAlive() const;

        /**
         * @brief Get the live neighbor count for the specified row and column.
         * @param row Row number.
         * @param col Column number.
         * @return Live neighbor count (returns 0-7).
         */
        short getNeighborCount(const int row, const int col) const;

        /**
         * @brief Step the simulation to the next generation.
         */
        void step();

        /**
         * @brief Print out the current simulation state.
         */
        void print() const;

    private:

        Grid grid;
        
        int generation;

        /**
         * @brief Apply the rules to the specified row and column.
         * 
         * @param row Row number.
         * @param col Column number.
         * @return std::vector<Operation> Results of applying the rules.
         */
        std::vector<Operation> applyRules(const int row, const int col);

};
#include <iostream>
#include "Sim.hh"

/**
 * @brief Construct a new Sim object. Initializes grid to CellState::DEAD.
 * 
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
Sim::Sim(const int rows, const int cols)
    : grid(rows, cols),
        generation(0) {
    // do nothing
}

/**
 * @brief Construct a new Sim object. Initializes grid to initGrid.
 * 
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param initGrid Initializer grid.
 */
Sim::Sim(const int rows, const int cols, const std::vector<bool> initGrid)
    : grid(rows, cols, initGrid),
        generation(0) {
    // do nothing
}

/**
 * @brief Get the current generation count.
 * 
 * @return int Current generation count.
 */
int Sim::getGeneration() const {
    return generation;
}

/**
 * @brief Determine if the specified cell is alive.
 * 
 * @param row Row number.
 * @param col Column number.
 * @return If the specified cell is alive.
 */
bool Sim::isCellAlive(const int row, const int col) const {
    return grid.get(row, col) == CellState::ALIVE;
}

/**
 * @brief Determine if there are any live cells.
 * 
 * @return If there are live cells.
 */
bool Sim::isAnyCellAlive() const {
    bool anyCellAlive {false};

    for (int row {0}; row < grid.numRows; row++) {
        for (int col {0}; col < grid.numCols; col++) {
            if (isCellAlive(row, col)) {
                anyCellAlive = true;
                break;
            }
        }
    }

    return anyCellAlive;
}

/**
 * @brief Get the live neighbor count for the specified row and column.
 * 
 * @param row Row number.
 * @param col Column number.
 * @return Live neighbor count (returns 0-7).
 */
short Sim::getNeighborCount(const int row, const int col) const {
    short count {0};

    int newRow {0};
    int newCol {0};

    // 0 1 2
    // 3 X 4
    // 5 6 7

    // check the top left neighbor
    if ((row > 0) && (col > 0)) {
        newRow = row - 1;
        newCol = col - 1;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    // check the top center neighbor
    if (row > 0) {
        newRow = row - 1;
        newCol = col;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    // check the top right neighbor
    if ((row > 0) && ((col + 1) < grid.numCols)) {
        newRow = row - 1;
        newCol = col + 1;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    // check left neighbor
    if (col > 0) {
        newRow = row;
        newCol = col - 1;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    // check right neighbor
    if ((col + 1) < grid.numCols) {
        newRow = row;
        newCol = col + 1;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    // check bottom left neighbor
    if (((row + 1) < grid.numRows) && (col > 0)) {
        newRow = row + 1;
        newCol = col - 1;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    // check bottom center neighbor
    if ((row + 1) < grid.numRows) {
        newRow = row + 1;
        newCol = col;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    // check bottom left neighbor
    if (((row + 1) < grid.numRows) && ((col + 1) < grid.numCols)) {
        newRow = row + 1;
        newCol = col + 1;

        if (isCellAlive(newRow, newCol)) { count += 1; }
    }

    return count;
}

/**
 * @brief Apply the rules to the specified row and column.
 * 
 * @param row Row number.
 * @param col Column number.
 * @return std::vector<Operation> Results of applying the rules.
 */
std::vector<Operation> Sim::applyRules(const int row, const int col) {
    std::vector<Operation> operations;

    // determine the number of live neighbors to the current cell
    const short neighborCount = getNeighborCount(row, col);

    // determine if the current cell is alive
    const bool alive = isCellAlive(row, col);

    // RULES FOR LIVE CELLS ///////////////////////////////////////////////
    if (alive) {
        // rule 1: any live cell with fewer than two live neighbors dies,
        //          as if caused by under-population.
        if (neighborCount < 2) {
            operations.push_back(Operation(row, col, CellState::DEAD));
        }

        // rule 2: any live cell with two or three live neigbors lives on
        //          to the next generation.
        else if (neighborCount <= 3) {
            // do nothing, cell lives
        }

        // rule 3: any live cell with more than three neigborns dies, as if
        //          caused by overcrowding.
        else {
            operations.push_back(Operation(row, col, CellState::DEAD));
        }
    }

    // RULES FOR DEAD CELLS ///////////////////////////////////////////////
    else {
        // rule 4: any dead cell with exactly three live neighbors becomes
        //          a live cell, as if by reproduction.
        if (neighborCount == 3) {
            operations.push_back(Operation(row, col, CellState::ALIVE));
        }
    }

    return operations;
}

/**
 * @brief Step the simulation to the next generation.
 */
void Sim::step() {
    std::vector<Operation> operations;

    // increment the sim's generation
    generation += 1;

    // loop over each cell in the grid
    for (int row {0}; row < grid.numRows; row++) {
        for (int col {0}; col < grid.numCols; col++) {
            // apply rules to the cell
            std::vector<Operation> results = applyRules(row, col);

            // for (Operation op : results) {
            //     std::cout << "C: " << op << std::endl;
            // }

            // add any resultant operations to this step's operations list
            std::copy(results.begin(), results.end(), std::back_inserter(operations));
            // operations.insert(operations.end(), results.begin(), results.end());
        }
    }

    // for (Operation op : operations) {
    //     std::cout << "F: " << op << std::endl;
    // }

    // apply any operations for the step to the grid
    for (Operation operation : operations) {
        grid.set(operation.row, operation.col, operation.state);
        // std::cout << "set grid(" << operation.row << ", " << operation.col << ") to " << grid.getString(operation.row, operation.col) << std::endl;
    }
}

/**
 * @brief Print out the current simulation state.
 */
void Sim::print() const {
    std::cout << "Generation: " << getGeneration() << std::endl
              << grid << std::endl
              << "Any cell alive? " << std::boolalpha << isAnyCellAlive() << std::endl
              << std::endl;
}

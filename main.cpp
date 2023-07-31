#include <iostream>
#include <vector>
#include "node.h"
#include "solver.h"

int main() {

    // Generate a Node object with a random initial state
    Node initial_node = Node::generateRandomInitialState();

    // Create a Solver object with the initial node state
    Solver solver(initial_node);

    // Solve the puzzle using BFS and get the solution
    std::vector<Node> solution = solver.solvePuzzle();

    if (!solution.empty()) {
        std::cout << "Steps to solve the puzzle:\n";
        // Print the steps to reach the goal state
        Solver::printSteps(solution);
    } else {
        std::cout << "Puzzle is unsolvable.\n";
    }

    return 0;
}

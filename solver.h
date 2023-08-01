#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <queue>
#include <map>
#include "node.h"

class Solver {
public:
    typedef std::vector<Node> Path;

    explicit Solver(Node  initialState);

    std::vector<Node> solvePuzzle();
    static void printSteps(const std::vector<Node>& solution);

private:
    Node _initialState;

};

#endif // SOLVER_H

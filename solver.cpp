#include "solver.h"
#include <iostream>

Solver::Solver(Node  initialState) : _initialState(std::move(initialState)) {}

std::vector<Node> Solver::solvePuzzle() {
    typedef std::vector<Node> Path;

    Path solution;
    std::queue<Path> q;
    std::map<Node::Grid, bool> visited;
    Path initialPath;
    initialPath.push_back(_initialState);
    q.push(initialPath);

    while (!q.empty()) {
        Path currentPath = q.front();
        q.pop();
        Node currentNode = currentPath.back();

        if (currentNode.isEndState()) {
            solution = currentPath;
            break;
        }

        std::vector<Node> moves = currentNode.getMoves();
        for (const auto & move : moves) {
            if (visited.find(move.getState()) == visited.end()) {
                Path newPath = currentPath;
                newPath.push_back(move);
                q.push(newPath);
                visited[move.getState()] = true;
            }
        }
    }

    return solution;
}

 void  Solver::printSteps(const std::vector<Node>& solution) {
    for (size_t step = 0; step < solution.size(); ++step) {
        const Node::Grid& state = solution[step].getState();
        std::cout << "Step " << step << ":\n";
        for (size_t i = 0; i < state.size(); ++i) {
            for (size_t j = 0; j < state[i].size(); ++j) {
                if (state[i][j] == 0) {
                    std::cout << "    ";
                } else {
                    if (state[i][j] < 10) {
                        std::cout << " ";
                    }
                    std::cout << ' ' << state[i][j] << ' ';
                }
                if (j < state[i].size() - 1) {
                    std::cout << '|';
                }
            }
            std::cout << '\n';
            if (i < state.size() - 1) {
                std::cout << "----+----+----\n";
            }
        }
        std::cout << '\n';
    }
}

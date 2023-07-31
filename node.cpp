#include "node.h"
#include <algorithm>
#include <random>
#include <chrono>

const Node::Grid Node::_goalState = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
};

Node::Node(const std::vector<std::vector<int>>& _state) : _state(_state) {}

const std::vector<std::vector<int>>& Node::getState() const {
    return _state;
}

bool Node::isEndState() const {
    return _state == _goalState;
}

Coordinate Node::getZero() const {
    Coordinate pos{};
    for (size_t i = 0; i < _state.size(); ++i) {
        for (size_t j = 0; j < _state[i].size(); ++j) {
            if (_state[i][j] == 0) {
                pos.x = i;
                pos.y = j;
            }
        }
    }
    return pos;
}

Node Node::switchNode(const int& x1, const int& y1, const int& x2, const int& y2) const {
    Grid newState = _state;
    int temp = newState[x1][y1];
    newState[x1][y1] = newState[x2][y2];
    newState[x2][y2] = temp;
    return Node(newState);
}

std::vector<Node> Node::getMoves() const {
    std::vector<Node> moves;
    Coordinate zeroPos = getZero();
    int x = zeroPos.x;
    int y = zeroPos.y;

    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    const int gridSize = 3;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize) {
            Node newNode = switchNode(x, y, nx, ny);
            moves.push_back(newNode);
        }
    }
    return moves;
}

Node Node::generateRandomInitialState() {
    Grid initialState(3, std::vector<int>(3));
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8};

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    int index = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            initialState[i][j] = numbers[index++];
        }
    }

    return Node(initialState);
}

#ifndef NODE_H
#define NODE_H

#include <vector>

struct Coordinate {
    int x;
    int y;
};

class Node {
public:
    typedef std::vector<std::vector<int>> Grid;

    explicit Node(const Grid& _state);

    const Grid& getState() const;

    bool isEndState() const;

    Coordinate getZero() const;

    Node switchNode(const int& x1, const int& y1, const int& x2, const int& y2) const;

    std::vector<Node> getMoves() const;

    static Node generateRandomInitialState();

private:
    static const Grid _goalState;
    Grid _state;
};

#endif // NODE_H

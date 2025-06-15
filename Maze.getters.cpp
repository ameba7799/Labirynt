#include "Maze.h"


int Maze::getHeight() const {
    return height;
}

int Maze::getWidth() const {
    return width;
}

bool Maze::isRightOpen(int row, int col) const {
    if (!isValid(row, col)) {return false;}
    return maze[row][col].right;
}

bool Maze::isDownOpen(int row, int col) const {
    if (!isValid(row, col)) {return false;}
    return maze[row][col].down;
}

bool Maze::isLeftOpen(int row, int col) const {
    if (!isValid(row, col)) {return false;}
    return maze[row][col].left;
}

bool Maze::isUpOpen(int row, int col) const {
    if (!isValid(row, col)) {return false;}
    return maze[row][col].up;
}

Position Maze::getStartPosition() const {
    return start;
}

Position Maze::getEndPosition() const {
    return end;
}

Position Maze::getCurrentPosition() const {
    return currentPos;
}
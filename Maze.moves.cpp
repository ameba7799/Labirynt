#include "Maze.h"


int Maze::moveRight() {
    if (currentPos.row == end.row && currentPos.col == end.col) {return 0;}
    int moveCount = 0;

    while (true) {
        if (!maze[currentPos.row][currentPos.col].right) {break;}
        ++currentPos.col;
        ++moveCount;
        if (maze[currentPos.row][currentPos.col].up) {break;}
        if (maze[currentPos.row][currentPos.col].down) {break;}
    }

    return moveCount;
}

int Maze::moveDown() {
    if (currentPos.row == end.row && currentPos.col == end.col) {return 0;}
    int moveCount = 0;

    while (true) {
        if (!maze[currentPos.row][currentPos.col].down) {break;}
        ++currentPos.row;
        ++moveCount;
        if (maze[currentPos.row][currentPos.col].left) {break;}
        if (maze[currentPos.row][currentPos.col].right) {break;}
    }

    return moveCount;
}

int Maze::moveLeft() {
    if (currentPos.row == end.row && currentPos.col == end.col) {return 0;}
    int moveCount = 0;

    while (true) {
        if (!maze[currentPos.row][currentPos.col].left) {break;}
        --currentPos.col;
        ++moveCount;
        if (maze[currentPos.row][currentPos.col].down) {break;}
        if (maze[currentPos.row][currentPos.col].up) {break;}
    }

    return moveCount;
}

int Maze::moveUp() {
    if (currentPos.row == end.row && currentPos.col == end.col) {return 0;}
    int moveCount = 0;

    while (true) {
        if (!maze[currentPos.row][currentPos.col].up) {break;}
        --currentPos.row;
        ++moveCount;
        if (maze[currentPos.row][currentPos.col].right) {break;}
        if (maze[currentPos.row][currentPos.col].left) {break;}
    }

    return moveCount;
}
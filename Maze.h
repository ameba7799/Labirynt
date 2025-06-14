#ifndef MAZE_H
#define MAZE_H

#include "Array2D.h"

enum Direction {Right, Down, Left, Up};


struct MazePart { //Prawda oznacza że jest przejście
    bool right = false;
    bool down = false;
    bool left = false;
    bool up = false;

    bool isConnected() const;
};

struct Position {
    int row;
    int col;
};


class Maze {
private:
    Array2D<MazePart> maze{0,0};
    int width;
    int height;
    Position start = {0,0};
    Position end = {0,0};

    bool isValid(int row, int col) const;
    bool isUnconnected(int row, int col) const;
    void clearMaze();
    void setStart();
    void setEnd();
    Position connect(int row, int col, Direction dir);

public:
    Maze();
    Maze(int width, int height);
    void create();
    int getWidth() const;
    int getHeight() const;
    bool isRightOpen(int row, int col) const;
    bool isDownOpen(int row, int col) const;
    bool isLeftOpen(int row, int col) const;
    bool isUpOpen(int row, int col) const;
};



#endif //MAZE_H

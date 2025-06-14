#ifndef MAZE_H
#define MAZE_H

#include "Array2D.h"


struct MazePart {
    bool right = false;
    bool down = false;
    bool left = false;
    bool up = false;
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
    Position start;
    Position end;

public:
    Maze(int width, int height);
    void create(Position &start);
    int getWidth();
    int getHeight();
};



#endif //MAZE_H

#ifndef MAZE_H
#define MAZE_H

#include "Array2D.h"
#include "Parameters.h"


struct MazePart { //Prawda oznacza że jest przejście
    bool right = false;
    bool down = false;
    bool left = false;
    bool up = false;

    int distans;

    bool isConnected() const;
};

struct Position {
    int row;
    int col;
};


class Maze {
private:
    Array2D<MazePart> maze{0,0};
    int height;
    int width;
    Position start;
    Position end;
    Position currentPos;

    bool isValid(int row, int col) const;
    bool isUnconnected(int row, int col) const;
    void clearMaze();
    void setStart();
    void setEnd();
    Position connect(int row, int col, Direction dir);

public:
    Maze(int width, int height);
    void create();

    int getHeight() const;
    int getWidth() const;
    bool isRightOpen(int row, int col) const;
    bool isDownOpen(int row, int col) const;
    bool isLeftOpen(int row, int col) const;
    bool isUpOpen(int row, int col) const;
    Position getStartPosition() const;
    Position getEndPosition() const;
    Position getCurrentPosition() const;

    int moveRight();
    int moveDown();
    int moveLeft();
    int moveUp();
};



#endif //MAZE_H

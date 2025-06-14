#ifndef MAZE_H
#define MAZE_H

#include "Array2D.h"


struct MazePart { //Prawda oznacza że jest przejście
    bool right = false;
    bool down = false;
    bool left = false;
    bool up = false;

    bool isConected() {
        return (right || down || left || up);
    }
    bool isAllConnected() {
        return (right && down && left && up);
    }
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

    bool isValid(int row, int col) const;
    void clear();

public:
    Maze();
    Maze(int width, int height);
    bool create(int startRow, int startCol);
    int getWidth() const;
    int getHeight() const;
    bool isRightOpen(int row, int col) const;
    bool isDownOpen(int row, int col) const;
    bool isLeftOpen(int row, int col) const;
    bool isUpOpen(int row, int col) const;
};



#endif //MAZE_H

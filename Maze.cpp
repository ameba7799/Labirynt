#include "Maze.h"
#include <iostream>



Maze::Maze() {
    width = 3;
    height = 3;
    maze.resize(3, 3);

    maze[0][0] = {true, false, false, false};
    maze[0][1] = {false, true, true, false};
    maze[0][2] = {false, true, false, false};
    maze[1][0] = {true, true, false, false};
    maze[1][1] = {false, true, true, true};
    maze[1][2] = {false, true, false, true};
    maze[2][0] = {false, false, false, true};
    maze[2][1] = {true, false, false, true};
    maze[2][2] = {false, false, true, true};
}


Maze::Maze(int width, int height) {
    this->width = width;
    this->height = height;

    maze.resize(width, height);

    create (0,0);
}


enum DIR {Right, Down, Left, Up};

bool Maze::create(int startRow, int startCol) { //już za trzecim razem coś działa
    if (!isValid(startRow, startCol)) {return false;}
    start = {startRow, startCol};

    clear();

    int help1 = 0, help2 = 0;
    std::vector<Position> toConnect;
    toConnect.reserve(width * height);
    std::vector<DIR> options;
    options.reserve(4);

    toConnect.push_back({startRow, startCol});

    while (!toConnect.empty()) {
        help1 = rand() % toConnect.size();
        if (isValid(toConnect[help1].row,toConnect[help1].col+1)&&!maze[toConnect[help1].row][toConnect[help1].col+1].isConected()) {options.push_back(Right);}
        if (isValid(toConnect[help1].row+1,toConnect[help1].col)&&!maze[toConnect[help1].row+1][toConnect[help1].col].isConected()) {options.push_back(Down);}
        if (isValid(toConnect[help1].row,toConnect[help1].col-1)&&!maze[toConnect[help1].row][toConnect[help1].col-1].isConected()) {options.push_back(Left);}
        if (isValid(toConnect[help1].row-1,toConnect[help1].col)&&!maze[toConnect[help1].row-1][toConnect[help1].col].isConected()) {options.push_back(Up);}
        if (options.empty()) {
            toConnect.erase(toConnect.begin()+help1);
            continue;
        }
        help2 = rand() % options.size();
        switch (options[help2]) {
        case Right:
            maze[toConnect[help1].row][toConnect[help1].col].right = true;
            maze[toConnect[help1].row][toConnect[help1].col+1].left = true;
            toConnect.push_back({toConnect[help1].row,toConnect[help1].col+1});
            break;
        case Down:
            maze[toConnect[help1].row][toConnect[help1].col].down = true;
            maze[toConnect[help1].row+1][toConnect[help1].col].up = true;
            toConnect.push_back({toConnect[help1].row+1,toConnect[help1].col});
            break;
        case Left:
            maze[toConnect[help1].row][toConnect[help1].col].left = true;
            maze[toConnect[help1].row][toConnect[help1].col-1].right = true;
            toConnect.push_back({toConnect[help1].row,toConnect[help1].col-1});
            break;
        case Up:
            maze[toConnect[help1].row][toConnect[help1].col].up = true;
            maze[toConnect[help1].row-1][toConnect[help1].col].down = true;
            toConnect.push_back({toConnect[help1].row-1,toConnect[help1].col});
            break;
        }
        options.clear();
    }

}

void Maze::clear() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            maze[row][col] = {false, false, false, false};
        }
    }
}


int Maze::getWidth() const {
    return width;
}

int Maze::getHeight() const {
    return height;
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


bool Maze::isValid(int row, int col) const {

    if (row < 0 || row >= width) {return false;}
    if (col < 0 || col >= height) {return false;}
    return true;
}


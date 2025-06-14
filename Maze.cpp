#include "Maze.h"
#include <iostream>

#include "MazeView.h"


Maze::Maze(int width, int height) {
    this->width = width;
    this->height = height;
    maze.resize(height, width);

    create ();
}


void Maze::setStart() {
    start = end;
}

void Maze::setEnd() {
    Position pos = {0,0};
    int maxNum = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
           if (maze[row][col].distans > maxNum) {
               pos.row = row;
               pos.col = col;
               maxNum = maze[row][col].distans;
           }
        }
    }

    end = pos;
}

void Maze::create() { //już za trzecim razem coś działa
    setStart();
    currentPos = start;
    clearMaze();

    Position pos;
    int help;
    std::vector<Position> toConnect;
    toConnect.reserve(width * height);
    std::vector<Direction> options;
    options.reserve(4);

    toConnect.push_back({start.row, start.col});
    maze[start.row][start.col].distans = 0;

    while (!toConnect.empty()) {
        help = rand() % toConnect.size();
        pos = toConnect[help];
        if (isUnconnected(pos.row,pos.col+1)) {options.push_back(Right);}
        if (isUnconnected(pos.row+1,pos.col)) {options.push_back(Down);}
        if (isUnconnected(pos.row,pos.col-1)) {options.push_back(Left);}
        if (isUnconnected(pos.row-1,pos.col)) {options.push_back(Up);}

        if (options.empty()) {
            toConnect.erase(toConnect.begin()+help);
            continue;
        }

        toConnect.push_back(connect(pos.row, pos.col, options[rand() % options.size()]));
        options.clear();
    }

    setEnd();
}

void Maze::clearMaze() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            maze[row][col] = {false, false, false, false, 0};
        }
    }
}

Position Maze::connect(int row, int col, Direction dir) {
    switch (dir) {
    case Right:
        maze[row][col].right = true;
        maze[row][col+1].left = true;
        maze[row][col+1].distans = maze[row][col].distans+1;
        return{row,col+1};
    case Down:
        maze[row][col].down = true;
        maze[row+1][col].up = true;
        maze[row+1][col].distans = maze[row][col].distans+1;
        return{row+1,col};
    case Left:
        maze[row][col].left = true;
        maze[row][col-1].right = true;
        maze[row][col-1].distans = maze[row][col].distans+1;
        return{row,col-1};
    case Up:
        maze[row][col].up = true;
        maze[row-1][col].down = true;
        maze[row-1][col].distans = maze[row][col].distans+1;
        return{row-1,col};
    }
}


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


bool Maze::isValid(int row, int col) const {
    if (row < 0 || row >= height) {return false;}
    if (col < 0 || col >= width) {return false;}
    return true;
}

bool Maze::isUnconnected(int row, int col) const {
    if (!isValid(row, col)) {return false;}
    if (maze[row][col].isConnected()) {return false;}
    return true;
}

bool MazePart::isConnected() const {
    return (right || down || left || up);
}


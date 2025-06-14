#include "Maze.h"
#include <iostream>

#include "MazeView.h"


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

    create ();
}




void Maze::setStart() {
    start = end;
}

void Maze::setEnd() {
    //TODO wymyślić jak znaleść koniec
}

void Maze::create() { //już za trzecim razem coś działa
    setStart();
    clearMaze();

    Position pos;
    int help;
    std::vector<Position> toConnect;
    toConnect.reserve(width * height);
    std::vector<Direction> options;
    options.reserve(4);

    toConnect.push_back({start.row, start.col});

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
            maze[row][col] = {false, false, false, false};
        }
    }
}

Position Maze::connect(int row, int col, Direction dir) {
    switch (dir) {
    case Right:
        maze[row][col].right = true;
        maze[row][col+1].left = true;
        return{row,col+1};
    case Down:
        maze[row][col].down = true;
        maze[row+1][col].up = true;
        return{row+1,col};
    case Left:
        maze[row][col].left = true;
        maze[row][col-1].right = true;
        return{row,col-1};
    case Up:
        maze[row][col].up = true;
        maze[row-1][col].down = true;
        return{row-1,col};
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

bool Maze::isUnconnected(int row, int col) const {
    if (!isValid(row, col)) {return false;}
    if (maze[row][col].isConnected()) {return false;}
    return true;
}

bool MazePart::isConnected() const {
    return (right || down || left || up);
}


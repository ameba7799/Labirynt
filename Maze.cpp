#include "Maze.h"
#include <iostream>



Maze::Maze(int width, int height) {
    this->width = width;
    this->height = height;

    maze.resize(width, height);

    Position pos = {0,0};
    create (pos);
}


void Maze::create(Position& start) {

}

int Maze::getWidth() {
    return width;
}

int Maze::getHeight() {
    return height;
}

//
// Created by User on 14.06.2025.
//

#ifndef MAZEGAME_H
#define MAZEGAME_H
#include "Maze.h"
#include "MazeView.h"
#include "Parameters.h"


class MazeGame {
private:
    Maze &maze;
    MazeView &view;
    sf::RenderWindow window;

    bool started;

    void gameControl(sf::Event &event);

public:
    MazeGame(Maze &maze, MazeView &view);
    void play();
};



#endif //MAZEGAME_H

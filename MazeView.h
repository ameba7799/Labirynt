#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include "Maze.h"
#include <SFML/Graphics.hpp>

#define FIELDSIZE 100



class MazeView {
private:
    Maze &maze;

    sf::RectangleShape rightWall;
    sf::RectangleShape downWall;
    sf::RectangleShape leftWall;
    sf::RectangleShape upWall;

    sf::CircleShape c;

    void createWall(sf::RectangleShape &wall);

public:
    MazeView(Maze &maze);
    void draw();

    void test(sf::RenderWindow &window);
};



#endif //MAZEVIEW_H

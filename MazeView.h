#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include "Maze.h"
#include <SFML/Graphics.hpp>

#define FIELDSIZE 100
#define MARGIN FIELDSIZE*0.2



class MazeView {
private:
    Maze &maze;

    sf::RectangleShape background;
    sf::RectangleShape rightWall;
    sf::RectangleShape downWall;
    sf::RectangleShape leftWall;
    sf::RectangleShape upWall;

    void createWall(sf::RectangleShape &wall);
    void createBackground();
    void drawField(sf::RenderWindow &window, int row, int col);

public:
    MazeView(Maze &maze);
    void draw(sf::RenderWindow &window);

    void test(sf::RenderWindow &window);
};



#endif //MAZEVIEW_H

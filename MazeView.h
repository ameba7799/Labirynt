#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include "Maze.h"
#include <SFML/Graphics.hpp>
#include "Parameters.h"




class MazeView {
private:
    Maze &maze;

    sf::RectangleShape background;
    sf::RectangleShape rightWall;
    sf::RectangleShape downWall;
    sf::RectangleShape leftWall;
    sf::RectangleShape upWall;
    sf::CircleShape end;

    sf::Sprite instruct;
    sf::Texture instructTexture;

    void createWall(sf::RectangleShape &wall);
    void createBackground();
    void createEnd();
    void createInstructions();
    void drawField(sf::RenderWindow &window, int row, int col);
    void drawEnd(sf::RenderWindow &window);

public:
    MazeView(Maze &maze);
    void drawGame(sf::RenderWindow &window);
    void drawInstruct(sf::RenderWindow &window);

    void test(sf::RenderWindow &window);
};



#endif //MAZEVIEW_H

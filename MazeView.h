#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include "Maze.h"
#include <SFML/Graphics.hpp>
#include "Parameters.h"
#include <deque>


struct Move {
    Direction dir;
    float dist;
};


class MazeView {
private:
    Maze &maze;
    std::deque<Move> moves{0};
    int moveX = 0;
    int moveY = 0;

    sf::RectangleShape background;
    sf::RectangleShape rightWall;
    sf::RectangleShape downWall;
    sf::RectangleShape leftWall;
    sf::RectangleShape upWall;
    sf::CircleShape end;

    sf::Sprite instruct;
    sf::Texture instructTexture;

    sf::CircleShape player;
    sf::CircleShape arrow;

    sf::Image icon;

    void createWall(sf::RectangleShape &wall);
    void createBackground();
    void createEnd();
    void createInstructions();
    void createPlayer();
    void createArrow();
    void createIcon();

    void drawBackground(sf::RenderWindow &window);
    void drawField(sf::RenderWindow &window, int row, int col);
    void drawEnd(sf::RenderWindow &window);
    void drawArrow(sf::RenderWindow &window);

    void moveView(sf::RenderWindow &window);

public:
    MazeView(Maze &maze);
    void drawGame(sf::RenderWindow &window);
    void drawInstruct(sf::RenderWindow &window);
    void addMove(Direction dir, int move);
    bool isEndFind();
    void setWindowIcon(sf::RenderWindow &window);

};



#endif //MAZEVIEW_H

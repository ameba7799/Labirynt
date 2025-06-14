#include "MazeView.h"

#define WALLCOLOR sf::Color(96,96,96)



MazeView::MazeView(Maze& maze) : maze(maze) {
    createWall(rightWall);
    rightWall.setOrigin(-FIELDSIZE*0.8, FIELDSIZE*0.2);

    createWall(downWall);
    downWall.setOrigin(FIELDSIZE, FIELDSIZE*0.2);
    downWall.setRotation(-90);

    createWall(leftWall);
    leftWall.setOrigin(0, FIELDSIZE*0.2);

    createWall(upWall);
    upWall.setOrigin(FIELDSIZE*0.2, FIELDSIZE*0.2);
    upWall.setRotation(-90);

    c.setRadius(1);
    c.setFillColor(sf::Color::Red);
    c.setPosition(FIELDSIZE, FIELDSIZE);
}

void MazeView::createWall(sf::RectangleShape& wall) {
    wall.setSize(sf::Vector2f(FIELDSIZE*0.2, FIELDSIZE*1.4));
    wall.setFillColor(WALLCOLOR);
}


void MazeView::draw() {}





//Sprawćmy czy to działa
void MazeView::test(sf::RenderWindow &window) {
    rightWall.setPosition(FIELDSIZE, FIELDSIZE);
    window.draw(rightWall);
    downWall.setPosition(FIELDSIZE, FIELDSIZE);
    window.draw(downWall);
    leftWall.setPosition(FIELDSIZE, FIELDSIZE);
    window.draw(leftWall);
    upWall.setPosition(FIELDSIZE, FIELDSIZE);
    window.draw(upWall);

    window.draw(c);
}

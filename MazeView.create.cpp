#include "MazeView.h"


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

    createBackground();
    createEnd();

    createInstructions();

    createPlayer();
}

void MazeView::createWall(sf::RectangleShape& wall) {
    wall.setSize(sf::Vector2f(FIELDSIZE*0.2, FIELDSIZE*1.4));
    wall.setFillColor(WALLCOLOR);
}

void MazeView::createBackground() {
    background.setSize(sf::Vector2f(FIELDSIZE*maze.getWidth(), FIELDSIZE*maze.getHeight()));
    background.setFillColor(BACKGROUNDCOLOR);
}

void MazeView::createEnd() {
    end.setRadius(FIELDSIZE*0.2);
    end.setFillColor(ENDCOLOR);
    end.setOrigin(-FIELDSIZE*0.3, -FIELDSIZE*0.3);
}

void MazeView::createInstructions() {
    instructTexture.loadFromFile("../instrukcje.png");
    instruct.setTexture(instructTexture);
    instruct.setScale(WINWIDTH/instructTexture.getSize().x, WINHEIGHT/instructTexture.getSize().y);
    instruct.setPosition(0,0);
}

void MazeView::createPlayer() {
    player.setRadius(FIELDSIZE*0.2);
    player.setFillColor(PLAYERCOLOR);
    player.setOrigin(-FIELDSIZE*0.3, -FIELDSIZE*0.3);
    player.setPosition(PLAYERPOSITION);
}
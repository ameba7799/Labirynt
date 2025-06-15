#include "MazeView.h"


MazeView::MazeView(Maze& maze) : maze(maze) {
    createWall(rightWall);
    rightWall.setOrigin(RIGHTWALLPOSITION);

    createWall(downWall);
    downWall.setOrigin(DOWNWALLPOSITION);
    downWall.setRotation(-90);

    createWall(leftWall);
    leftWall.setOrigin(LEFTWALLPOSITION);

    createWall(upWall);
    upWall.setOrigin(UPWALLPOSITION);
    upWall.setRotation(-90);

    createBackground();
    createEnd();
    createInstructions();
    createPlayer();
    createArrow();
}

void MazeView::createWall(sf::RectangleShape& wall) {
    wall.setSize(WALLSIZE);
    wall.setFillColor(WALLCOLOR);
}

void MazeView::createBackground() {
    background.setSize(BACKGROUNDSIZE(maze));
    background.setFillColor(BACKGROUNDCOLOR);
}

void MazeView::createEnd() {
    end.setRadius(FIELDSIZE*0.2);
    end.setFillColor(ENDCOLOR);
    end.setOrigin(CIRCLEORIGIN);
}

void MazeView::createInstructions() {
    instructTexture.loadFromFile(TEXTUREFILE);
    instruct.setTexture(instructTexture);
    instruct.setScale(INSTRUCTSCALE(instructTexture));
    instruct.setPosition(0,0);
}

void MazeView::createPlayer() {
    player.setRadius(FIELDSIZE*0.2);
    player.setFillColor(PLAYERCOLOR);
    player.setOrigin(CIRCLEORIGIN);
    player.setPosition(PLAYERPOSITION);
}

void MazeView::createArrow() {
    arrow.setRadius(FIELDSIZE*0.1);
    arrow.setPointCount(3);
    arrow.setFillColor(ENDCOLOR);
    arrow.setOrigin(ARROWORIGIN);
    arrow.setPosition(ARROWPOSITION);
}
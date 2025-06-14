#include "MazeView.h"

#define BACKGROUNDCOLOR sf::Color(224,224,224)
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

    createBackground();
}

void MazeView::createWall(sf::RectangleShape& wall) {
    wall.setSize(sf::Vector2f(FIELDSIZE*0.2, FIELDSIZE*1.4));
    wall.setFillColor(WALLCOLOR);
}

void MazeView::createBackground() {
    background.setSize(sf::Vector2f(FIELDSIZE*maze.getWidth(), FIELDSIZE*maze.getHeight()));
    background.setFillColor(BACKGROUNDCOLOR);
    background.setPosition(sf::Vector2f(MARGIN, MARGIN));
}


void MazeView::draw(sf::RenderWindow &window) {
    window.clear(WALLCOLOR);
    window.draw(background);

    for (int row = 0; row < maze.getWidth(); row++) {
        for (int col = 0; col < maze.getHeight(); col++) {
            drawField(window, row, col);
        }
    }
}

void MazeView::drawField(sf::RenderWindow &window, int row, int col) {
    if (!maze.isRightOpen(row, col)) {
        rightWall.setPosition(FIELDSIZE*col+MARGIN, FIELDSIZE*row+MARGIN);
        window.draw(rightWall);
    }
    if (!maze.isDownOpen(row, col)) {
        downWall.setPosition(FIELDSIZE*col+MARGIN, FIELDSIZE*row+MARGIN);
        window.draw(downWall);
    }
    if (!maze.isLeftOpen(row, col)) {
        leftWall.setPosition(FIELDSIZE*col+MARGIN, FIELDSIZE*row+MARGIN);
        window.draw(leftWall);
    }
    if (!maze.isUpOpen(row, col)) {
        upWall.setPosition(FIELDSIZE*col+MARGIN, FIELDSIZE*row+MARGIN);
        window.draw(upWall);
    }
}





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
}

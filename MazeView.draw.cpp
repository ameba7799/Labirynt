#include "MazeView.h"


void MazeView::drawGame(sf::RenderWindow &window) {
    moveView(window);
    window.clear(WALLCOLOR);
    drawBackground(window);

    for (int row = (moveY-MARGIN)/FIELDSIZE; row < (moveY+window.getSize().y-MARGIN)/FIELDSIZE; row++) {
        for (int col = (moveX-MARGIN)/FIELDSIZE; col < (moveX+window.getSize().x-MARGIN)/FIELDSIZE; col++) {
            drawField(window, row, col);
        }
    }

    drawEnd(window);
    window.draw(player);
}

void MazeView::drawBackground(sf::RenderWindow& window) {
    background.setPosition(MARGIN-moveX, MARGIN-moveY);
    window.draw(background);
}


void MazeView::drawField(sf::RenderWindow &window, int row, int col) {
    if (!maze.isRightOpen(row, col)) {
        rightWall.setPosition(FIELDSIZE*col+MARGIN-moveX, FIELDSIZE*row+MARGIN-moveY);
        window.draw(rightWall);
    }
    if (!maze.isDownOpen(row, col)) {
        downWall.setPosition(FIELDSIZE*col+MARGIN-moveX, FIELDSIZE*row+MARGIN-moveY);
        window.draw(downWall);
    }
    if (!maze.isLeftOpen(row, col)) {
        leftWall.setPosition(FIELDSIZE*col+MARGIN-moveX, FIELDSIZE*row+MARGIN-moveY);
        window.draw(leftWall);
    }
    if (!maze.isUpOpen(row, col)) {
        upWall.setPosition(FIELDSIZE*col+MARGIN-moveX, FIELDSIZE*row+MARGIN-moveY);
        window.draw(upWall);
    }
}

void MazeView::drawEnd(sf::RenderWindow &window) {
    int x = FIELDSIZE*maze.getEndPosition().col+MARGIN-moveX;
    int y = FIELDSIZE*maze.getEndPosition().row+MARGIN-moveY;
    end.setPosition(static_cast<float>(x), static_cast<float>(y));
    window.draw(end);
}


void MazeView::drawInstruct(sf::RenderWindow &window) {
    window.draw(instruct);
}


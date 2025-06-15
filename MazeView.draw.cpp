#include <cmath>
#include <valarray>

#include "MazeView.h"


void MazeView::drawGame(sf::RenderWindow &window) {
    moveView(window);
    window.clear(WALLCOLOR);
    drawBackground(window);

    for (int row = ONROW(moveY)-1; row < ONROW(moveY+window.getSize().y)+1; row++) {
        for (int col = ONCOL(moveX)-1; col < ONCOL(moveX+window.getSize().x)+1; col++) {
            drawField(window, row, col);
        }
    }

    drawEnd(window);
    drawArrow(window);
    window.draw(player);
}

void MazeView::drawBackground(sf::RenderWindow& window) {
    background.setPosition(MARGIN-moveX, MARGIN-moveY);
    window.draw(background);
}


void MazeView::drawField(sf::RenderWindow &window, int row, int col) {
    if (!maze.isRightOpen(row, col)) {
        rightWall.setPosition(FIELDSTART(row,col));
        window.draw(rightWall);
    }
    if (!maze.isDownOpen(row, col)) {
        downWall.setPosition(FIELDSTART(row,col));
        window.draw(downWall);
    }
    if (!maze.isLeftOpen(row, col)) {
        leftWall.setPosition(FIELDSTART(row,col));
        window.draw(leftWall);
    }
    if (!maze.isUpOpen(row, col)) {
        upWall.setPosition(FIELDSTART(row,col));
        window.draw(upWall);
    }
}

void MazeView::drawEnd(sf::RenderWindow &window) {
    end.setPosition(FIELDSTART(maze.getEndPosition().row,maze.getEndPosition().col));
    window.draw(end);
}

void MazeView::drawArrow(sf::RenderWindow &window) {
    float angle = ATAN(end.getPosition(), player.getPosition());

    if (player.getPosition().x-end.getPosition().x>0) {
        arrow.setRotation(angle-90);
    } else if (player.getPosition().x-end.getPosition().x<0) {
        arrow.setRotation(angle-270);
    } else if (player.getPosition().y-end.getPosition().y<0) {
        arrow.setRotation(180);
    } else {
        arrow.setRotation(0);
    }
    window.draw(arrow);
}


void MazeView::drawInstruct(sf::RenderWindow &window) {
    window.draw(instruct);
}


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



void MazeView::drawGame(sf::RenderWindow &window) {
    moveView(window);
    window.clear(WALLCOLOR);
    drawBackground(window);

    for (int row = 0; row < maze.getHeight(); row++) {
        for (int col = 0; col < maze.getWidth(); col++) {
            drawField(window, row, col);
        }
    }

    drawEnd(window);
    window.draw(player);
}

void MazeView::moveView(sf::RenderWindow &window) {
    if (moves.size() == 0) {return;}
    switch (moves.front().dir) {
    case Right:
        ++moveX;
        break;
    case Down:
        ++moveY;
        break;
    case Left:
        --moveX;
        break;
    case Up:
        --moveY;
        break;
    }
    if (--moves.front().dist == 0) {moves.pop_front();}
    window.setPosition(sf::Vector2i(moveX,moveY));
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


void MazeView::addMove(Direction dir, int move) {
    Move newMove = {dir, move*FIELDSIZE};
    moves.push_back(newMove);
}

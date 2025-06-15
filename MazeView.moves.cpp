#include "MazeView.h"


void MazeView::moveView(sf::RenderWindow &window) {
    while (moves.size() > 0) {
        if (moves.front().dist == 0) {
            moves.pop_front();
            continue;
        }

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
        --moves.front().dist;
        window.setPosition(sf::Vector2i(moveX,moveY));
        break;
    }
}

void MazeView::addMove(Direction dir, int move) {
    Move newMove = {dir, move*FIELDSIZE};
    moves.push_back(newMove);
}


bool MazeView::isEndFind() {
    return (player.getPosition() == end.getPosition());
}

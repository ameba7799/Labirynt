#include "MazeGame.h"


MazeGame::MazeGame(Maze& maze, MazeView& view) : maze(maze), view(view) {
    started = false;
}


void MazeGame::play() {
    window.create(sf::VideoMode(WINWIDTH, WINHEIGHT), "LABIRYNT", sf::Style::None);
    window.setPosition(sf::Vector2i(0,0));

    sf::Event event;
    while (window.isOpen()) {
        if (view.isEndFind()) {maze.create();}

        while (window.pollEvent(event)) {
            gameControl(event);
        }

        if (!started) {view.drawInstruct(window);}
        else {view.drawGame(window);}
        window.display();
    }
}

void MazeGame::gameControl(sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
        return;
    }

    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
        case sf::Keyboard::Escape:
            window.close();
            return;
        case sf::Keyboard::Enter:
            started = true;
            return;
        case sf::Keyboard::Right: case sf::Keyboard::D:
            view.addMove(Right, maze.moveRight());
                return;
        case sf::Keyboard::Down: case sf::Keyboard::S:
            view.addMove(Down, maze.moveDown());
                return;
        case sf::Keyboard::Left: case sf::Keyboard::A:
            view.addMove(Left, maze.moveLeft());
                return;
        case sf::Keyboard::Up: case sf::Keyboard::W:
            view.addMove(Up, maze.moveUp());
                return;
        default:
            return;
        }
    }
}

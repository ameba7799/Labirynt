#include "MazeGame.h"


MazeGame::MazeGame(Maze& maze, MazeView& view) : maze(maze), view(view) {
    started = false;
}


void MazeGame::play() {
    window.create(sf::VideoMode(WINWIDTH, WINHEIGHT), "LABIRYNT", sf::Style::None);
    //Hi hi hi - zabrałam użytkownikowi całą kontrolę nad okienkiem

    sf::Event event;
    while (window.isOpen()) {
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
            //TODO move right
                return;
        case sf::Keyboard::Down: case sf::Keyboard::S:
            //TODO move down
                return;
        case sf::Keyboard::Left: case sf::Keyboard::A:
            //TODO move left
                return;
        case sf::Keyboard::Up: case sf::Keyboard::W:
            //TODO move up
                return;
        }
    }
}

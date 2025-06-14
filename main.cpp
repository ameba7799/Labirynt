#include "Maze.h"
#include "MazeView.h"
#include "MazeGame.h"
#include <SFML/Graphics.hpp>



int main() {
    //Zaczełam robić projekt

    Maze m(0,0);
    MazeView view(m);

    sf::RenderWindow window(sf::VideoMode(FIELDSIZE*3, FIELDSIZE*3), "test");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        view.test(window);
        window.display();
    }

    return 0;

}
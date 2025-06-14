#include "Maze.h"
#include "MazeView.h"
#include "MazeGame.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>



int main() {
    srand(time(nullptr));

    Maze m(4, 4);
    MazeView view(m);

    sf::RenderWindow window(sf::VideoMode(FIELDSIZE*m.getWidth(), FIELDSIZE*m.getHeight()), "test");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        view.draw(window);
        window.display();
    }

    return 0;

}
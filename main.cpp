#include "Maze.h"
#include "MazeView.h"
#include "MazeGame.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>



int main() {
    srand(time(nullptr));

    Maze m(10, 10);
    MazeView view(m);

    int winWidth = FIELDSIZE*(m.getWidth()+0.4);
    int winHeight = FIELDSIZE*(m.getHeight()+0.4);
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "LABIRYNT", sf::Style::None);
    //Hi hi hi - zabrałam użytkownikowi całą kontrolę nad okienkiem

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
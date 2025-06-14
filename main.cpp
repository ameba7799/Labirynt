#include "Maze.h"
#include "MazeView.h"
#include "MazeGame.h"
#include "Parameters.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>



int main() {
    srand(time(nullptr));

    Maze maze(MAZEROWS, MAZECOLS);
    MazeView view(maze);

    MazeGame game(maze, view);
    game.play();

    return 0;
}
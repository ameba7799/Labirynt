#ifndef PARAMETERS_H
#define PARAMETERS_H


#define FIELDSIZE 200.f
#define MARGIN (FIELDSIZE*0.2)

#define MAZEROWS ((sf::VideoMode::getDesktopMode().width-2*MARGIN)/FIELDSIZE)
#define MAZECOLS ((sf::VideoMode::getDesktopMode().height-2*MARGIN)/FIELDSIZE)

#define WINWIDTH (3*FIELDSIZE+2*MARGIN)
#define WINHEIGHT (3*FIELDSIZE+2*MARGIN)

#define PLAYERPOSITION sf::Vector2f(FIELDSIZE+MARGIN,FIELDSIZE+MARGIN)

#define BACKGROUNDCOLOR sf::Color(224,224,224)
#define WALLCOLOR sf::Color(96,96,96)
#define ENDCOLOR sf::Color(255,0,0)
#define PLAYERCOLOR sf::Color(47,47,47)

enum Direction {Right, Down, Left, Up};


#endif //PARAMETERS_H

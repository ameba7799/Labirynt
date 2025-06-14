#ifndef PARAMETERS_H
#define PARAMETERS_H


#define FIELDSIZE 200
#define MARGIN FIELDSIZE*0.2

#define MAZEROWS ((sf::VideoMode::getDesktopMode().width-2*MARGIN)/FIELDSIZE)
#define MAZECOLS ((sf::VideoMode::getDesktopMode().height-2*MARGIN)/FIELDSIZE)

#define WINWIDTH (3*FIELDSIZE+2*MARGIN)
#define WINHEIGHT (3*FIELDSIZE+2*MARGIN)

#define BACKGROUNDCOLOR sf::Color(224,224,224)
#define WALLCOLOR sf::Color(96,96,96)
#define ENDCOLOR sf::Color(255,0,0)


#endif //PARAMETERS_H

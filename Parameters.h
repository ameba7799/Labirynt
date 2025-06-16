#ifndef PARAMETERS_H
#define PARAMETERS_H


#define FIELDSIZE 200.f
#define MARGIN (FIELDSIZE*0.2)

#define MAZEROWS ((sf::VideoMode::getDesktopMode().width-2*MARGIN)/FIELDSIZE)
#define MAZECOLS ((sf::VideoMode::getDesktopMode().height-2*MARGIN)/FIELDSIZE)

#define WINWIDTH (3*FIELDSIZE+2*MARGIN)
#define WINHEIGHT (3*FIELDSIZE+2*MARGIN)

#define ONROW(x) ((x-MARGIN)/FIELDSIZE)
#define ONCOL(x) ((x+MARGIN)/FIELDSIZE)

#define TEXTUREFILE "../instrukcje.png"
#define ICONFILE "../Labirynt.bmp"

#define PLAYERPOSITION sf::Vector2f(FIELDSIZE+MARGIN,FIELDSIZE+MARGIN)
#define ARROWPOSITION sf::Vector2f(FIELDSIZE*1.5+MARGIN,FIELDSIZE*1.5+MARGIN)
#define RIGHTWALLPOSITION sf::Vector2f(-FIELDSIZE*0.8, FIELDSIZE*0.2)
#define DOWNWALLPOSITION sf::Vector2f(FIELDSIZE, FIELDSIZE*0.2)
#define LEFTWALLPOSITION sf::Vector2f(0, FIELDSIZE*0.2)
#define UPWALLPOSITION sf::Vector2f(FIELDSIZE*0.2, FIELDSIZE*0.2)

#define WALLSIZE sf::Vector2f(FIELDSIZE*0.2,FIELDSIZE*1.4)
#define BACKGROUNDSIZE(m) sf::Vector2f(FIELDSIZE*m.getWidth(),FIELDSIZE*m.getHeight())
#define INSTRUCTSCALE(texture) sf::Vector2f(WINWIDTH/texture.getSize().x, WINHEIGHT/texture.getSize().y)
#define CIRCLEORIGIN sf::Vector2f(-FIELDSIZE*0.3, -FIELDSIZE*0.3)
#define ARROWORIGIN sf::Vector2f(FIELDSIZE*0.1, FIELDSIZE*0.45)

#define FIELDSTART(row,col) sf::Vector2f(FIELDSIZE*col+MARGIN-moveX, FIELDSIZE*row+MARGIN-moveY)

#define BACKGROUNDCOLOR sf::Color(224,224,224)
#define WALLCOLOR sf::Color(96,96,96)
#define ENDCOLOR sf::Color(255,0,0)
#define PLAYERCOLOR sf::Color(47,47,47)

#define DEGREES(x) ((x*360)/(2*3.141592))
#define ATAN(pos1, pos2) DEGREES(atan((pos1.y-pos2.y)/(pos1.x-pos2.x)))

enum Direction {Right, Down, Left, Up};


#endif //PARAMETERS_H

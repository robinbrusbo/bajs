#include "target.h"
#include <cmath>

sf::RectangleShape Target::drawTarget(){
    sf::RectangleShape board(sf::Vector2f(5, 50));
    board.setOrigin(2.5, 25);
    board.setPosition(x, y);
    board.setFillColor(sf::Color::Red);
    return board;
}

void Target::maneuver(char direction){
    if (direction == 'l'){
        x -= 0.1;
    }
    if (direction == 'r'){
        x += 0.1;
    }
    if (direction == 'u'){
        y += 0.1;
    }
    if (direction == 'd'){
        y -= 0.1;
    }
}
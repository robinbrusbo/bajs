#include "arrow.h"
#include <cmath>

sf::RectangleShape Arrow::drawArrow(){
    sf::RectangleShape rectangle(sf::Vector2f(15, 80));
    rectangle.setOrigin(15, 80);
    rectangle.setPosition(100, 400);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setRotation(angle);
    return rectangle;
}

float Arrow::newAngle(int b){
    if (b == 1){
        if (angle < 90){
            angle += 0.1;
        }
    } else {
        if (angle > 0){
            angle -= 0.1;
        }
    }    
    printf("Angles: ");
    printf("%f", 90 - angle);
}
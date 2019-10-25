#ifndef ARROW_H
#define ARROW_H

#include <SFML/Graphics.hpp>

class Arrow
{
    public:
        float angle = 0;

        float offset = 25;

        sf::RectangleShape drawArrow();

        float newAngle(int b);
    
    private:
};

#endif
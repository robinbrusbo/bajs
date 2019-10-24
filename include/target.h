#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>

class Target
{
    public:

        float x = 400;
        float y = 400;

        sf::RectangleShape drawTarget();

        void maneuver(char direction);

    private:
};

#endif
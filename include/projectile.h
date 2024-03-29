#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "arrow.h"
#include "target.h"

#include <SFML/Graphics.hpp>

class Projectile
{
    public:

        bool fire = false;
        int timesFired = 0;
        float velocity = 3;
        sf::CircleShape circle;
        float tick = 0;
        float maxvel = 10;
        float minvel = 0.025;

        float newX(float t, Arrow arrow);

        float newY(float t, Arrow arrow);

        void initialize();

        sf::CircleShape drawCircle(Arrow arrow);

        void fireProjectile();

        void changeSpeed(int c);

        void reset();

        void offScreen();

        void checkCollision(Target target);
        
    private:
};

#endif

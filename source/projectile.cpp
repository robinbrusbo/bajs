#include "projectile.h"
#include <cmath>

float Projectile::newX(float t, Arrow arrow){
    return cos(90-(arrow.angle*3.14/180))*velocity*t;
}

float Projectile::newY(float t, Arrow arrow){
    return sin(90-(arrow.angle*3.14/180))*velocity*t-4.91*pow(t, 2);
}

void Projectile::initialize(){
    circle.setRadius(8);
    circle.setFillColor(sf::Color::Blue);
    circle.setOrigin(4, 4);
    circle.setPosition(90, 390);
}

sf::CircleShape Projectile::drawCircle(Arrow arrow){
    if (fire == false){
        return circle;
    }
    if (fire == true){ 
        circle.move(newX(tick, arrow), -newY(tick, arrow));
        tick += 0.0005;
        return circle;
    }
}

void Projectile::fireProjectile(){
    shouldClear = false;
    fire = true;
}

void Projectile::changeSpeed(int c){
    if (c == 1){
        if (velocity < 10){
            velocity += 0.005;
        }
    } else if (c == 0){
        if (velocity > 0.025){
            velocity -= 0.005;
        }
    }
    printf("Velocity: ");
    printf("%f\n", velocity);  
}

void Projectile::reset(){
    shouldClear = true;
    fire = false;
    timesFired = 0;
    tick = 0;
    initialize();
}

void Projectile::offScreen(){
    if (circle.getPosition().x > 720 || circle.getPosition().x < 0){
        reset();
    }
    if (circle.getPosition().y > 480 || circle.getPosition().y < 0){
        reset();
    }
}

void Projectile::checkCollision(Target target){
    if (abs(circle.getPosition().x - target.x) <= 5){
        if (abs(circle.getPosition().y - target.y) <= 25){
            printf("You win\n");
            reset();
        }
    }
}
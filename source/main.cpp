#include "target.h"
#include "projectile.h"
#include "arrow.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Target target;
Arrow arrow;
Projectile projectile;

int main(){

    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(720, 480), "Kast");

    projectile.initialize();

    while (window.isOpen()){
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            projectile.fireProjectile();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            arrow.newAngle(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            arrow.newAngle(0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            projectile.changeSpeed(0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            projectile.changeSpeed(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            target.maneuver('d');
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            target.maneuver('l');
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            target.maneuver('u');
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            target.maneuver('r');
        }

        if (projectile.shouldClear == true){
            window.clear();
        }
        if (projectile.fire == true){
            window.draw(projectile.drawCircle(arrow));
        }
        window.draw(arrow.drawArrow());
        window.draw(target.drawTarget());
        window.display();
        projectile.offScreen();
        projectile.checkCollision(target);
    }
}
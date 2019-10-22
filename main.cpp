#include <SFML/Graphics.hpp>
#include <iostream>
#include <bits/stdc++.h>

#define pi 3.1415926

class Arrow
{
    public:

        float angle = 0;

        sf::RectangleShape drawArrow(){
            sf::RectangleShape rectangle(sf::Vector2f(15, 80));
            rectangle.setOrigin(15, 80);
            rectangle.setPosition(100, 400);
            rectangle.setFillColor(sf::Color::White);
            rectangle.setRotation(angle);
            return rectangle;
        }

        float newAngle(int b){
            if (b == 1){
                if (angle < 90){
                    angle += 0.1;
                }
            } else {
                if (angle > 0){
                    angle -= 0.1;
                }
            }
            std::cout << angle << std::endl;
        }
    
    private:
};

Arrow arrow;

class Projectile
{
    public:

        bool shouldClear = true;
        bool fire = false;
        int timesFired = 0;
        float velocity = 1;
        sf::CircleShape circle;
        float tick = 0;

        float newX(float t){
            return cos(90-(arrow.angle*pi/180))*velocity;
        }

        float newY(float t){
            return sin(90-(arrow.angle*pi/180))*t-4.91*pow(t, 2);
        }

        void initialize(){
            circle.setRadius(8);
            circle.setFillColor(sf::Color::Blue);
            circle.setOrigin(4, 4);
            circle.setPosition(100, 400);
        }

        sf::CircleShape drawCircle(){
            if (fire == false){
                return circle;
            }
            if (fire == true){
                circle.move(newX(tick), -newY(tick));
                tick += 0.0005;
                return circle;
            }
        }

        void fireProjectile(){
            shouldClear = false;
            fire = true;
        }

        void changeSpeed(int c){
            if (c == 1){
                if (velocity < 10){
                    velocity += 0.025;
                }
            } else if (c == 0){
                if (velocity > 0.025){
                    velocity -= 0.025;
                }
            }
            std::cout << velocity << std::endl;
        }
        
    private:
};

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

        if (projectile.shouldClear == true){
            window.clear();
        }
        window.draw(projectile.drawCircle());
        window.draw(arrow.drawArrow());
        window.display();
    }
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <bits/stdc++.h>

// To do:
// Lägg in collisions
// Lägg in text på skärmen (v, alfa)
// Strukturera fint!

#define pi 3.1415926

class Target
{
    public:

        float x = 400;
        float y = 400;

        sf::RectangleShape drawTarget(){
            sf::RectangleShape board(sf::Vector2f(5, 50));
            board.setOrigin(2.5, 25);
            board.setPosition(x, y);
            board.setFillColor(sf::Color::Red);
            return board;
        }

        void maneuver(char direction){
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

    private:
};

Target target;

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
            std::cout << "Angle: " << 90-angle << std::endl;
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
            return cos(90-(arrow.angle*pi/180))*velocity*t;
        }

        float newY(float t){
            return sin(90-(arrow.angle*pi/180))*velocity*t-4.91*pow(t, 2);
        }

        void initialize(){
            circle.setRadius(8);
            circle.setFillColor(sf::Color::Blue);
            circle.setOrigin(4, 4);
            circle.setPosition(90, 390);
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
                if (velocity < 3){
                    velocity += 0.005;
                }
            } else if (c == 0){
                if (velocity > 0.025){
                    velocity -= 0.005;
                }
            }
            std::cout << "Velocity: " << velocity << std::endl;
        }

        void reset(){
            shouldClear = true;
            fire = false;
            timesFired = 0;
            tick = 0;
            initialize();
        }

        void offScreen(){
            if (circle.getPosition().x > 720 || circle.getPosition().x < 0){
                reset();
            }
            if (circle.getPosition().y > 480 || circle.getPosition().y < 0){
                reset();
            }
        }

        void checkCollision(){
            if (abs(circle.getPosition().x - target.x) <= 5){
                if (abs(circle.getPosition().y - target.y) <= 25){
                    std::cout << "You win" << std::endl;
                    reset();
                }
            }
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
            window.draw(projectile.drawCircle());
        }
        window.draw(arrow.drawArrow());
        window.draw(target.drawTarget());
        window.display();
        projectile.offScreen();
        projectile.checkCollision();
    }
}
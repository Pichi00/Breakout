#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"

const int windowWidth = 1024;
const int windowHeight = 576;

template <class T1, class T2> bool isIntersecting(T1& a, T2& b) {
    return  a.right() >= b.left() && a.left() <= b.right() &&
            a.bottom() >= b.top() && a.top() <= b.bottom();
}

bool colision_test(Paddle& p, Ball& b) {
    if (!isIntersecting(p, b)) return false;
    
    b.moveUp();

    if      (b.getPosition().x < p.getPosition().x)    b.moveLeft();
    else if (b.getPosition().x > p.getPosition().x)    b.moveRight();
        
    
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Breakout game");
    window.setFramerateLimit(60);
    sf::Event event;
    Ball ball(windowWidth/3, windowHeight/2);
    Paddle paddle (windowWidth/2, windowHeight*7/8);
    

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        window.pollEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        ball.update(windowWidth, windowHeight);
        paddle.update(windowWidth);
        colision_test(paddle,ball);
        window.draw(ball);
        window.draw(paddle);
        window.display();
    }
    return 0;
}

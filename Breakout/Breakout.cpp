#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"

const int windowWidth = 1024;
const int windowHeight = 576;
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
        window.draw(ball);
        window.draw(paddle);
        window.display();
    }
    return 0;
}

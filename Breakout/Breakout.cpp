#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

const int windowWidth = 1024;
const int windowHeight = 576;

const int blockWidth = 100;
const int blockHeight = 25;
const int blocksAmountX = 8;
const int blocksAmountY = 5;

template <class T1, class T2> bool isIntersecting(T1& a, T2& b) {
    return  a.right() >= b.left() && a.left() <= b.right() &&
            a.bottom() >= b.top() && a.top() <= b.bottom();
}

bool colision_test(Paddle& p, Ball& b) {
    if (!isIntersecting(p, b)) return false;

    b.moveUp();

    if (b.getPosition().x < p.getPosition().x)    b.moveLeft();
    else if (b.getPosition().x > p.getPosition().x)    b.moveRight();
}

bool colision_test(Block& block, Ball& ball) {
    if (!isIntersecting(block, ball)) return false;

    block.destroy();

    float overlapLeft = ball.right() - block.left();
    float overlapRight = ball.left() - block.right();
    float overlapTop  = ball.bottom() - block.top();
    float overlapBottom  = ball.top() - block.bottom();

    if (abs(overlapRight) > abs(overlapLeft)) ball.moveLeft();
    else ball.moveRight();

    if (abs(overlapBottom) > abs(overlapTop)) ball.moveUp();
    else ball.moveDown();
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Breakout game");
    window.setFramerateLimit(60);
    sf::Event event;
    Ball ball(windowWidth/3, windowHeight/2);
    Paddle paddle (windowWidth/2, windowHeight*7/8);
    Block blocks[blocksAmountX][blocksAmountY];
    for (int i = 1; i <= blocksAmountX; i++) {
        for (int j = 1; j <= blocksAmountY; j++) {
            Block block(10 + i * blockWidth * 10/9, 10 + j * blockHeight * 10/8, blockWidth, blockHeight);
            blocks[i-1][j-1] = block;
        }
    }

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        window.pollEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        ball.update(windowWidth, windowHeight);
        paddle.update(windowWidth);
        colision_test(paddle,ball);
        for (int i = 0; i < blocksAmountX; i++) {
            for (int j = 0; j < blocksAmountY; j++) {
                if (!blocks[i][j].isDestroyed()) {
                    colision_test(blocks[i][j], ball);
                    window.draw(blocks[i][j]);
                }
            }
        }
        window.draw(ball);
        window.draw(paddle);
        window.display();
    }
    return 0;
}

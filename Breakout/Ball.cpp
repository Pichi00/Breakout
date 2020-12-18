#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball(float t_X, float t_Y) {
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->shape);
}

void Ball::update(float wW, float wH) {
	shape.move(this->velocity);

	if (left() < 0)				velocity.x = ballSpeed;
	else if (right() > wW)	velocity.x = -ballSpeed;

	if (top() < 0)				velocity.y = ballSpeed;
	else if (bottom() > wH)	velocity.y = -ballSpeed;
}

float Ball::left() {
	return this->shape.getPosition().x - this->ballRadius;
}
float Ball::right() {
	return this->shape.getPosition().x + this->ballRadius;
}
float Ball::top() {
	return this->shape.getPosition().y - this->ballRadius;
}
float Ball::bottom() {
	return this->shape.getPosition().y + this->ballRadius;
}
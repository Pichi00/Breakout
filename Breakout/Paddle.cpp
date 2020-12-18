#include "Paddle.h"

Paddle::Paddle(float t_X, float t_Y) {
	shape.setOrigin(this->paddleWidth / 2, this->paddleHeight / 2);
	shape.setPosition(t_X, t_Y);
	shape.setSize(sf::Vector2f(this->paddleWidth, this->paddleHeight));
	shape.setFillColor(sf::Color::Blue);
	
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->shape);
}

void Paddle::update(float wW) {
	shape.move(this->velocity);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && left() > 0) velocity.x = -paddleSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && right() < wW) velocity.x = paddleSpeed;
	else velocity.x = 0.f;
}

float Paddle::left() {
	return this->shape.getPosition().x - (this->paddleWidth / 2);
}
float Paddle::right() {
	return this->shape.getPosition().x + (this->paddleWidth / 2);
}
float Paddle::top() {
	return this->shape.getPosition().y - (this->paddleHeight / 2);
}
float Paddle::bottom() {
	return this->shape.getPosition().y + (this->paddleHeight / 2);
}
#include "Block.h"
#include<SFML/Graphics.hpp>

Block::Block(float t_X, float t_Y, float t_Width, float t_Height) {
	shape.setSize(sf::Vector2f(t_Width, t_Height));
	shape.setOrigin(t_Width / 2, t_Height / 2);
	shape.setPosition(t_X, t_Y);	
	shape.setFillColor(sf::Color::Green);
}

void Block::update() {

}

float Block::left() {
	return this->shape.getPosition().x - shape.getSize().x / 2;
}
float Block::right() {
	return this->shape.getPosition().x + shape.getSize().x / 2;
}
float Block::top() {
	return this->shape.getPosition().y - shape.getSize().y / 2;
}
float Block::bottom() {
	return this->shape.getPosition().y + shape.getSize().y / 2;
}

bool Block::isDestroyed() {
	return this->destroyed;
}
void Block::destroy() {
	destroyed = true;
}

sf::Vector2f Block::getSize() {
	return this->shape.getSize();
}
sf::Vector2f Block::getPosition() {
	return this->shape.getPosition();
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->shape);
}
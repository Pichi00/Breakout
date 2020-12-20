#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Block: public sf::Drawable
{
public:
	Block() = delete;
	Block(float t_X, float t_Y, float t_Width, float t_Height);
	~Block() = default;

	void update();

	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();
	
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape shape;
	bool destroyed{ false };
};


#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Block: public sf::Drawable
{
public:
	Block() = default;
	Block(int t_X, int t_Y, int t_Width, int t_Height);
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


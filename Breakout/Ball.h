#pragma once
#include<SFML/Graphics.hpp>
class Ball: public sf::Drawable
{
public:
	Ball() = delete;
	Ball(float t_X, float t_Y);
	~Ball() = default;
	void update(float wW, float wH);
	float left();
	float right();
	float top();
	float bottom();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	sf::Vector2f getPosition();

private:
	sf::CircleShape shape;
	const float ballRadius = 16.0f;
	const float ballSpeed = 6.0f;
	sf::Vector2f velocity{ballSpeed,ballSpeed};
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;


};


#pragma once
#include<SFML/Graphics.hpp>
class Paddle : public sf::Drawable
{
public:
	Paddle() = delete;
	Paddle(float t_X, float t_Y);
	~Paddle() = default;
	void update(float wW);
	float left();
	float right();
	float top();
	float bottom();
	sf::Vector2f getPosition();
private:
	sf::RectangleShape shape;
	const float paddleWidth = 150.0f;
	const float paddleHeight = 20.0f;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	const float paddleSpeed = 6.0f;
	sf::Vector2f velocity = { paddleSpeed, 0.f };
};


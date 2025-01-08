#pragma once
#include <SFML/Graphics.hpp>

class boid
{
public:
	sf::Vector2f velocity;
	sf::Vector2f position;
	sf::CircleShape shape;

	boid(sf::Vector2f startPos, sf::Vector2f startVelocity);

	void update();
	void draw(sf::RenderWindow& window);

};


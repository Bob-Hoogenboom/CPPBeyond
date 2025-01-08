#include "boid.h"

boid::boid(sf::Vector2f startPos, sf::Vector2f startVelocity)
	:position(startPos), velocity(startVelocity)
{
	shape.setRadius(3.f);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(3.f, 3.f);
	shape.setPosition(position);
}

void boid::update()
{
	position += velocity;
	shape.setPosition(position);
}

void boid::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

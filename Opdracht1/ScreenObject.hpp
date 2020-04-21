#ifndef SCREENOBJECT_HPP
#define SCREENOBJECT_HPP

#include "SFML/Graphics.hpp"

using sf::Vector2f;
using sf::RenderWindow;
using sf::Color;
using sf::FloatRect;

class ScreenObject {
	protected:
	Vector2f pos;
	Color col;

	public:
	ScreenObject(Vector2f pos, Color col = Color::White) : pos(pos), col(col) {}

	void virtual draw(RenderWindow& window) = 0;
	void virtual update() = 0;
	void virtual interact(const ScreenObject& other) = 0;
	FloatRect virtual getBound() const = 0;
};

#endif //SCREENOBJECT_HPP
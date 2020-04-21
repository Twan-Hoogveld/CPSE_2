#ifndef WALL_HPP
#define WALL_HPP

#include "ScreenObject.hpp"

using sf::RectangleShape;

class Wall : public ScreenObject {
	private:
	RectangleShape rectangle;

	public:
	Wall(const Vector2f position, Vector2f size, Color col = Color::White) : ScreenObject(position, col), rectangle{size}{
		rectangle.setFillColor(col);
		rectangle.setPosition(pos);
	}
	
	void draw(RenderWindow& window) override;
	void update() override;
	void interact(const ScreenObject& other) override;
	FloatRect getBound() const override;
};

#endif //WALL_HPP
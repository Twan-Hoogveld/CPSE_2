#ifndef BALL_HPP
#define BALL_HPP

#include "ScreenObject.hpp"
#include <iostream>

using sf::Vector2i;
using sf::CircleShape;
using sf::Rect;

class ball : public ScreenObject {
 private:
  float size;
	CircleShape circle;
	Vector2f velocity;

	void collision(bool collide_x);
 public:
  ball(Vector2f position, Vector2f speed = {5.0,5.0}, Color col = Color::White, float size = 30.0) : ScreenObject(position, col), size(size), 
	velocity(speed) {
		circle.setFillColor(col);
		circle.setRadius(size);
		circle.setPosition(pos);
	}

  void draw(RenderWindow& window) override;
  void update() override;
	FloatRect getBound() const override;
	void interact(const ScreenObject& other) override;

	void updateSpeed(const Vector2f& accel);
};

#endif  // BALL_HPP

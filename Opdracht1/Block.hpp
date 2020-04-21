#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "ScreenObject.hpp"

using sf::Vector2i;
using sf::RectangleShape;
using sf::Rect;

class moveableBlock : public ScreenObject {
 private:
 Vector2f size;
 RectangleShape rect;

 public:
  moveableBlock(Vector2f pos, Vector2f size, Color col = Color::White) :
	ScreenObject(pos, col), size(size) {
		rect.setFillColor(col);
		rect.setSize(size);
		rect.setPosition(pos);
	}

  void draw(RenderWindow& window) override;
  void update() override;
	void interact(const ScreenObject& other) override;
	FloatRect getBound() const override;

	void move( sf::Vector2f delta );
	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );
};

#endif  // BALL_HPP

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "MoveableObject.hpp"

using sf::CircleShape;

class Circle : public MoveableObject {
 private:
  unsigned int diameter;
  Color color;
  CircleShape circle;

 public:
  Circle(const Vector2f& pos, unsigned int diameter, Color col = Color::White)
      : MoveableObject(pos), diameter(diameter), color(col) {
    circle.setRadius(diameter / 2);
    circle.setFillColor(col);
    circle.setPosition(pos);
  }

	void move(const Vector2f& velo) override;
  void jump(const Vector2f& new_pos) override;
  FloatRect getBound() override;
  void draw(RenderWindow& window) override;
	ostream& writeToFile(ostream& output) override;
};

#endif  // CIRCLE_HPP
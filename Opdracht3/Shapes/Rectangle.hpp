#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "MoveableObject.hpp"

using sf::RectangleShape;

class Rectangle : public MoveableObject {
 private:
  Vector2f pos2;
	Vector2f diff_pos;
  Color color;
  RectangleShape rect;

 public:
  Rectangle(const Vector2f& pos, const Vector2f& pos2, Color col = Color::White)
      : MoveableObject(pos), pos2(pos2), color(col), rect{(pos2 - pos)} {
		diff_pos = pos2 - pos;
    rect.setFillColor(color);
    rect.setPosition(pos);
  }

  void move(const Vector2f& velo) override;
  void jump(const Vector2f& new_pos) override;
  FloatRect getBound() override;
  void draw(RenderWindow& window) override;
  ostream& writeToFile(ostream& output) override;
};

#endif  // RECTANGLE_HPP
#include "Circle.hpp"

void Circle::move(const Vector2f& velo) { pos += velo; }
void Circle::jump(const Vector2f& new_pos) { pos = new_pos; }

FloatRect Circle::getBound() { return circle.getGlobalBounds(); }
void Circle::draw(RenderWindow& window) {
  circle.setPosition(pos);
  window.draw(circle);
}

ostream& Circle::writeToFile(ostream& output) {
  output << pos << " CIRCLE " << color << " " << diameter;
  return output;
}
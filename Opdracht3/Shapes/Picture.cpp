#include "Picture.hpp"

void Picture::move(const Vector2f& velo) { pos += velo; }
void Picture::jump(const Vector2f& new_pos) { pos = new_pos; }

FloatRect Picture::getBound() { return sprite.getGlobalBounds(); }

void Picture::draw(RenderWindow& window) {
  sprite.setPosition(pos);
  window.draw(sprite);
}

ostream& Picture::writeToFile(ostream& output) {
  output << pos << " PICTURE " << filename;
  return output;
}
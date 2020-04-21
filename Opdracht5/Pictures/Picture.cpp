#include "Picture.hpp"

namespace TicTacToe {
  void Picture::draw(RenderWindow& window) {
    sprite.setPosition(pos);
    window.draw(sprite);
  }

  FloatRect Picture::getGlobalBounds() { return sprite.getGlobalBounds(); }
}  // namespace TicTacToe
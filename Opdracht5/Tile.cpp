#include "Tile.hpp"

namespace TicTacToe {
  void Tile::draw(RenderWindow& window) {
    if (is_active) {
      sprite.setPosition(pos);
      window.draw(sprite);
    }
  }

  void Tile::updateTile(int spot_info) {
    is_active = (spot_info != -1);
    if (spot_info == 0 && !texture1_active) {
      texture1_active = true;
      sprite.setTexture(texture);
    } else if (spot_info == 1 && texture1_active) {
      texture1_active = false;
      sprite.setTexture(texture2);
    }
  }

  FloatRect Tile::getGlobalBounds() { return FloatRect(pos, Vector2f(80, 80)); }

}  // namespace TicTacToe
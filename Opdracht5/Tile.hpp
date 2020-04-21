#ifndef TILE_HPP
#define TILE_HPP

#include "Pictures/Picture.hpp"

namespace TicTacToe {
  class Tile : public Picture {
   private:
    string filename2;
    Texture texture2;
    bool is_active = true;
    bool texture1_active = false;

   public:
    Tile(const Vector2f& pos, const string& filename1, const string& filename2)
        : Picture(pos, filename1), filename2(filename2) {
      if (!texture2.loadFromFile(filename2)) {
        cout << "Failed loading picture" << endl;
      }
      texture2.setSmooth(true);
    }

    void updateTile(int spot_info);
    void draw(RenderWindow& window) override;
    FloatRect getGlobalBounds() override;
  };
}  // namespace TicTacToe

#endif  // TILE_HPP
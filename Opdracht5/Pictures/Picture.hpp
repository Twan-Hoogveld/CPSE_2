#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iostream>
#include "SFML/Graphics.hpp"
#include "string"

using sf::FloatRect;
using sf::RenderWindow;
using sf::Sprite;
using sf::Texture;
using sf::Vector2f;
using std::cout;
using std::endl;
using std::string;

namespace TicTacToe {
  class Picture {
   protected:
    Vector2f pos;
    string filename;
    Texture texture;
    Sprite sprite;

   public:
    Picture(const Vector2f& pos, const std::string& filename) : pos(pos), filename(filename) {
      if (!texture.loadFromFile(filename)) {
        cout << "Failed loading picture" << endl;
      }
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    virtual void draw(RenderWindow& window);
    virtual FloatRect getGlobalBounds();
  };
}  // namespace TicTacToe

#endif  // PICTURE_HPP
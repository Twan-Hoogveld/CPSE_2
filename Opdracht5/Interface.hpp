#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "BoardState.hpp"
#include "SFML/Graphics.hpp"
#include "Tile.hpp"
#include "definitions.hpp"
#include "iostream"
#include "string"
#include "time.h"

using std::cout;
using std::endl;
using std::string;
using std::time_t;

namespace TicTacToe {
  class Interface {
   protected:
    bool game_end = false;

   public:
    virtual void showBoard(const board& board) = 0;
    /* If move.x and move.y = -1, than undoMove or reset
     * If move.x = -1 and move.y = 0 than incorrect input
     */
    virtual Move getInput() = 0;
    virtual void showWinner(int winner_id) = 0;
    virtual void resetInterface() = 0;
  };

  class CmdInterface : public Interface {
   private:
    string arrToStr(array<int, 3> to_conv);
    Move decodeStrToMove(string& input);

   public:
    void showBoard(const board& board) override;
    Move getInput() override;
    void showWinner(int winner_id) override;
    void resetInterface() override;
  };

  class SFMLInterface : public Interface {
   private:
    Vector2f start_pos;
    RenderWindow& window;
    Picture playing_field;
    Picture reset_button;
    vector<Tile> tiles;
		time_t reset_pushed;
		bool is_down = false;

   public:
    SFMLInterface(RenderWindow& window, Vector2f start_pos, Vector2f button_pos)
        : Interface(),
          start_pos(start_pos),
          window(window),
          playing_field(start_pos, FILENAME_PLAYING_FIELD),
          reset_button(button_pos, FILENAME_UNDO) {
      for (int count = 0; count < 9; count++) {
				reset_pushed = std::time(0);
        float pos_x = start_pos.x + ((count % 3) * BASE_MULTIPLIER) + BASE_OFFSET_X;
        float pos_y = start_pos.y + (int(count / 3) * BASE_MULTIPLIER) + BASE_OFFSET_Y;
        Vector2f pos_tile(pos_x, pos_y);
        tiles.push_back(Tile(pos_tile, FILENAME_TILE_PLAYER_0, FILENAME_TILE_PLAYER_1));
      }
    }

    void showBoard(const board& board) override;
    Move getInput() override;
    void showWinner(int winner_id) override;
    void resetInterface() override;
  };
}  // namespace TicTacToe

#endif  // INTERFACE_HPP
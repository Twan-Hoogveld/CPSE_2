#ifndef BOARDSTATE_HPP
#define BOARDSTATE_HPP

#include <array>
#include <vector>

using std::array;
using std::vector;

typedef array<array<int, 3>, 3> board;

namespace TicTacToe {
  struct Move {
    int x, y;
    uint player_num;

    bool operator==(const Move& rhs) { return ((x == rhs.x) && (y == rhs.y)); }
  };

  class BoardState {
   private:
    board init_board;

   public:
    void initBoard();
    board getBoard(const vector<Move>& moves);
    board getRows(const vector<Move>& moves);
    board getColumns(const vector<Move>& moves);
    array<array<int, 3>, 2> getDiagonals(const vector<Move>& moves);
  };
}  // namespace TicTacToe

#endif  // BOARDSTATE_HPP
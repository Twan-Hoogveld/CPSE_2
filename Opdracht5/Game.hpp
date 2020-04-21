#ifndef GAME_HPP
#define GAME_HPP

#include "BoardState.hpp"

namespace TicTacToe {
  class Game {
   private:
    BoardState board_state;
    bool player1_turn = false;
    vector<Move> moves;

		bool checkArray(array<int,3> to_check);

   public:
    Game() { board_state.initBoard(); }
    board getBoard();
    void addMove(Move move);
    int checkWin();
		void resetGame();
  };

}  // namespace TicTacToe

#endif  // GAME_HPP
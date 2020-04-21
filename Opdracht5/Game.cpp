#include "Game.hpp"
#include <iostream>

namespace TicTacToe {
  bool Game::checkArray(array<int, 3> to_check) {
    return (to_check[0] != -1 && (to_check[0] == to_check[1]) && (to_check[0] == to_check[2]));
  }
  board Game::getBoard() { return board_state.getBoard(moves); }

  void Game::addMove(Move move) {
    if (move.x == -1) {
      if (move.y == -1 && !moves.empty()) {
        moves.pop_back();
        player1_turn = !player1_turn;
      }
    } else {
      for (auto excisting_move : moves) {
        if (excisting_move == move) {
          return;  // Check if move already exists.
        }
      }
      move.player_num = player1_turn;
      moves.push_back(move);
      player1_turn = !player1_turn;
    }
  }

  int Game::checkWin() {
    /* return values:
     * -2 = not finished
     * -1 = draw
     * 0 = player0 win
     * 1 = player1 win
     */
    if (moves.size() < 5) {
      return -2;
    }

    auto rows = board_state.getRows(moves);
    auto cols = board_state.getColumns(moves);
    auto diag = board_state.getDiagonals(moves);

    for (auto row : rows) {
      if (checkArray(row)) {
        return row[0];
      }
    }

    for (auto col : cols) {
      if (checkArray(col)) {
        return col[0];
      }
    }

    for (auto dia : diag) {
      if (checkArray(dia)) {
        return dia[0];
      }
    }

    if (moves.size() > 8) {
      return -1;
    }
    return -2;
  }

  void Game::resetGame() {
    board_state.initBoard();
    player1_turn = false;
    moves = {};
  }
}  // namespace TicTacToe
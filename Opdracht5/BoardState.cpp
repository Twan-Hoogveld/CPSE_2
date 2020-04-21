#include "BoardState.hpp"

namespace TicTacToe {
  void BoardState::initBoard() {
    for (auto& x : init_board) {
      for (auto& y : x) {
        y = -1;
      }
    }
  }

  board BoardState::getBoard(const vector<Move>& moves) {
    auto state = init_board;
    for (auto move : moves) {
      state[move.y][move.x] = move.player_num;
    }
    return state;
  }

  board BoardState::getRows(const vector<Move>& moves) { return getBoard(moves); }

  board BoardState::getColumns(const vector<Move>& moves) {
    // Rotates the board (matrix) used algorithm found here
    // https://stackoverflow.com/questions/2893101/how-to-rotate-a-n-x-n-matrix-by-90-degrees
    int s_arr = 3;
    auto ret_array = getBoard(moves);
    for (int i = 0; i < s_arr / 2; i++) {
      for (int j = 0; j < (s_arr + 1) / 2; j++) {
        auto temp = ret_array[i][j];
        ret_array[i][j] = ret_array[s_arr - 1 - j][i];
        ret_array[s_arr - 1 - j][i] = ret_array[s_arr - 1 - i][s_arr - 1 - j];
        ret_array[s_arr - 1 - i][s_arr - 1 - j] = ret_array[j][s_arr - 1 - i];
        ret_array[j][s_arr - 1 - i] = temp;
      }
    }
    return ret_array;
  }

  array<array<int, 3>, 2> BoardState::getDiagonals(const vector<Move>& moves) {
    // Get the diagonals from a matrix, algorith used found here:
    // https://www.geeksforgeeks.org/program-to-print-the-diagonals-of-a-matrix/
    int s_arr = 3;
    auto curr_board = getBoard(moves);
    array<array<int, 3>, 2> ret_arr;
    int x_pos = 0, y_pos = 0;
    for (int x = 0; x < s_arr; x++) {
      for (int y = 0; y < s_arr; y++) {
        if (x == y) {
          ret_arr[0][x_pos] = curr_board[x][y];
          x_pos++;
        }
        if ((x + y) == (s_arr - 1)) {
          ret_arr[1][y_pos] = curr_board[x][y];
          y_pos++;
        }
      }
    }
    return ret_arr;
  }
}  // namespace TicTacToe
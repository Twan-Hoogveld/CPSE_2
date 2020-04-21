#include "Interface.hpp"

namespace TicTacToe {
  string CmdInterface::arrToStr(array<int, 3> to_conv) {
    string ret_str = "";
    char c;
    for (auto i : to_conv) {
      if (i == -1) {
        c = '_';
      } else if (i == 0) {
        c = 'X';
      } else if (i == 1) {
        c = 'O';
      }
      ret_str += c;
      ret_str += " ";
    }
    ret_str += "\n";
    return ret_str;
  }

  Move CmdInterface::decodeStrToMove(string& input) {
    Move ret_move;
    if (input == "z" || input == "Z") {
      ret_move.x = -1;
      ret_move.y = -1;
    } else if (input[1] == ',') {
      int x = input[0] - 48;
      int y = input[2] - 48;
      if ((x > 2) || (y > 2)) {
        ret_move.x = -1;
        ret_move.y = 0;
      } else {
        ret_move.x = x;
        ret_move.y = y;
      }
    } else {
      ret_move.x = -1;
      ret_move.y = 0;
    }
    return ret_move;
  }

  void CmdInterface::showBoard(const board& board) {
    cout << "Current board:\n";
    for (auto row : board) {
      cout << arrToStr(row);
    }
    cout << endl;
  }

  Move CmdInterface::getInput() {
    string msg = "Please enter a coordinate, format: X,Y ; Or enter Z to undo the last move.";
    string end_msg = "Please enter Z to restart game";
    string user_in;
    if (game_end) {
      cout << end_msg << endl;
    } else {
      cout << msg << endl;
    }
    std::cin >> user_in;
    return decodeStrToMove(user_in);
  }

  void CmdInterface::showWinner(int winner_id) {
    game_end = true;
    if (winner_id == -1) {
      cout << "The game finished in a draw!";
    } else if (winner_id == 0) {
      cout << "Player 0 Won" << endl;
    } else {
      cout << "Player 1 Won" << endl;
    }
  }

  void CmdInterface::resetInterface() { game_end = false; }

  void SFMLInterface::showBoard(const board& board) {
    window.clear();
    playing_field.draw(window);
    reset_button.draw(window);
    for (int i = 0; i < 9; i++) {
      auto tile = tiles[i];
      int pos_x = i % 3;
      int pos_y = i / 3;
      tile.updateTile(board[pos_y][pos_x]);
      tile.draw(window);
    }
    window.display();
  }
  Move SFMLInterface::getInput() {
    auto move_ret = Move();
    move_ret.x = -1;
    move_ret.y = 0;
    while (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
      // wait for button to be pressed
      is_down = false;
    }
    time_t curr_time = std::time(0);
    auto mouse_pos = Vector2f(sf::Mouse::getPosition(window));
    if (reset_button.getGlobalBounds().contains(mouse_pos) && (std::difftime(curr_time, reset_pushed) > RESET_TIMER) &&
        !is_down) {
      is_down = true;
      reset_pushed = curr_time;
      move_ret.y = -1;
    } else {
      for (int i = 0; i < 9; i++) {
        if (tiles[i].getGlobalBounds().contains(mouse_pos) && !is_down) {
          is_down = true;
          move_ret.x = i % 3;
          move_ret.y = i / 3;
        }
      }
    }
    return move_ret;
  }

  void SFMLInterface::showWinner(int winner_id) {
    window.clear();
    Texture win_texture;
    Sprite sprite_win;
    switch (winner_id) {
      case -1: win_texture.loadFromFile(FILENAME_DRAW); break;
      case 0: win_texture.loadFromFile(FILENAME_WIN0); break;
      case 1: win_texture.loadFromFile(FILENAME_WIN1); break;
      default: break;
    }
    sprite_win.setTexture(win_texture);
    sprite_win.setPosition(start_pos);
    window.draw(sprite_win);
    reset_button.draw(window);
    window.display();
  }

  void SFMLInterface::resetInterface() {
    for (auto tile : tiles) {
      tile.updateTile(-1);
    }
    reset_pushed = std::time(0);
  }

};  // namespace TicTacToe
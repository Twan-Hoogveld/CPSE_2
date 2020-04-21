#include "Game.hpp"
#include "Interface.hpp"
#include "SFML/Graphics.hpp"

int main() {
  cout << "Starting TicTacToe\n";
  TicTacToe::Game game;
  bool reset_done = false;
  bool game_done = false;
  int res_check;
  TicTacToe::Move input_reset;

//   sf::RenderWindow window{sf::VideoMode{WINDOW_SIZE_X, WINDOW_SIZE_Y}, "SFML window"};
//   window.clear();
//   Vector2f base_pos(150, 50);
//   Vector2f button_pos(50, 100);
//   TicTacToe::SFMLInterface interface2(window, base_pos, button_pos);
  
// 	while (window.isOpen()) {
//     sf::Event event;
//     while (!game_done) {
//       auto board = game.getBoard();
//       interface2.showBoard(board);
//       game.addMove(interface2.getInput());
//       res_check = game.checkWin();
//       game_done = (res_check != -2);
//       while (window.pollEvent(event)) {
//         if (event.type == sf::Event::Closed) {
//           window.close();
//         }
//       }
//     }
//     interface2.showWinner(res_check);
//     while (!reset_done) {  // Keep asking for input until reset input given
//       input_reset = interface2.getInput();
//       reset_done = ((input_reset.x == -1) && (input_reset.y == -1));
//       while (window.pollEvent(event)) {
//         if (event.type == sf::Event::Closed) {
//           window.close();
//         }
//       }
//     }
//     interface2.resetInterface();
//     game.resetGame();
//     reset_done = false;
//     game_done = false;
//   }
// }

TicTacToe::CmdInterface interface;

  while (true) {
    while (!game_done) {  // Game running
      interface.showBoard(game.getBoard());
      game.addMove(interface.getInput());
      res_check = game.checkWin();
      game_done = (res_check != -2);
    }
    interface.showWinner(res_check);
    interface.showBoard(game.getBoard());
    while (!reset_done) {  // Keep asking for input until reset input given
      input_reset = interface.getInput();
      reset_done = ((input_reset.x == -1) && (input_reset.y == -1));
    }
    interface.resetInterface();
    game.resetGame();
    reset_done = false;
    game_done = false;
  }
}
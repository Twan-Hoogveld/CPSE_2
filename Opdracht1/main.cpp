#include <iostream>
#include "Action.hpp"
#include "Block.hpp"
#include "Wall.hpp"

using std::cout;

int main(int argc, char* argv[]) {
  cout << "Starting walls and bounce\n";
  unsigned int size_x = 640;
  unsigned int size_y = 480;
  float wall_width = 5.0;

  RenderWindow window{sf::VideoMode{size_x, size_y}, "SFML window"};
  window.clear();

	Wall wall_t = Wall({0.0, 0.0}, {float(size_x), wall_width}, Color::Magenta);
	Wall wall_l = Wall({0.0, 0.0}, {wall_width, float(size_y)}, Color::Magenta);
	Wall wall_r = Wall({(float(size_x) - wall_width), 0.0}, {float(size_x), float(size_y)}, Color::Magenta);
	Wall wall_b = Wall({0.0, (float(size_y) - wall_width)}, {float(size_x), float(size_y)}, Color::Magenta);
  ball my_ball{Vector2f{320.0, 240.0}, Vector2f{5.0, 5.0}, Color::Red};
  moveableBlock block{Vector2f{100.0, 100.0}, Vector2f{50.0, 50.0}};

	array<ScreenObject*, 6> screen_objects = {&wall_t, &wall_l, &wall_r, &wall_b, &my_ball, &block};

  Action actions[] = {Action(Keyboard::Left, [&]() { block.move(Vector2f(-1.0, 0.0)); }),
                      Action(Keyboard::Right, [&]() { block.move(Vector2f(+1.0, 0.0)); }),
                      Action(Keyboard::Up, [&]() { block.move(Vector2f(0.0, -1.0)); }),
                      Action(Keyboard::Down, [&]() { block.move(Vector2f(0.0, +1.0)); }),
                      Action(Mouse::Left, [&]() { block.jump(Mouse::getPosition(window)); }),
                      Action([&]() { my_ball.update(); }),//};
											Action(screen_objects,[&]() {})};

  while (window.isOpen()) {
    for (auto& Action : actions) {
      Action();
    }

    window.clear();
		for(auto object : screen_objects){
			object->draw(window);
		}
    window.display();

    sf::sleep(sf::milliseconds(20));

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }

  cout << "Terminating application\n";
  return 0;
}

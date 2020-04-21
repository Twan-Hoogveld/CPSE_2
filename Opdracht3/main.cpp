#include <iostream>
#include <cstring>
#include "fstream"
#include "Collection.hpp"
#include "Factory.hpp"
#include "Action.hpp"

#define OBJECT_COUNT 4

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::strerror;

int main(int argc, char* argv[]) {
  cout << "Starting Factory\n";
  unsigned int size_x = 640;
  unsigned int size_y = 480;
	bool error_file = false;
	string filename = "windowObjects.txt";

  RenderWindow window{sf::VideoMode{size_x, size_y}, "SFML window"};
  window.clear();
  CollectionMoveables<OBJECT_COUNT> collection{};
	shared_ptr<MoveableObject> active_object;

  ifstream factory_file(filename);
	if(!factory_file.is_open()){
		cerr << "ERROR: " << strerror(errno) << endl;
		error_file = true;
	}

  try {
    for (;;) {
      collection.add(readMoveableObject(factory_file));
			cout << "ADDED SUCCESFUL\n";
    }
  } catch (const end_of_file&) {
    cout << "end of file reached" << endl;
  } catch(exception& problem){
		cout << problem.what() << endl;
		error_file = true;
	}

	Action actions[] = {Action(Keyboard::Left, [&]() { active_object->move(Vector2f(-2.0, 0.0)); }),
                      Action(Keyboard::Right, [&]() { active_object->move(Vector2f(+2.0, 0.0)); }),
                      Action(Keyboard::Up, [&]() { active_object->move(Vector2f(0.0, -2.0)); }),
                      Action(Keyboard::Down, [&]() { active_object->move(Vector2f(0.0, +2.0)); })};

  while (window.isOpen()) {
    collection.drawObjects(window);
    window.display();
		if(Mouse::isButtonPressed(Mouse::Left)){
			active_object = collection.getObject(Mouse::getPosition(window));
		}
		for (auto& Action : actions) {
      Action();
    }
    sf::sleep(sf::milliseconds(20));
    window.clear();
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
	ofstream output_file;
	output_file.open(filename, ofstream::trunc);
	collection.writeObjects(output_file);

  cout << "Terminating application\n";
  return 0;
}

// ()

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Shapes.hpp"
#include "Operators.hpp"
#include "istream"
#include <memory>

using std::istream;
using std::make_shared;
using std::shared_ptr;

shared_ptr<MoveableObject> readMoveableObject(istream& input){
	Vector2f position;
  string name;
  Color color;
  input >> position >> name;
  if (name == "CIRCLE") {
    int diameter;
    input >> color >> diameter;
		return make_shared<Circle>(position, diameter, color);
  } else if (name == "RECTANGLE") {
    Vector2f position2;
    input >> color >> position2;
    return make_shared<Rectangle>(position, position2, color);
  } else if (name == "LINE") {
    Vector2f position2;
    input >> color >> position2;
		return make_shared<Line>(position, position2, color);
  } else if (name == "PICTURE") {
    string filename;
    input >> filename;
		return make_shared<Picture>(position, filename);
  } else if (name == "") {
    throw end_of_file();
  }
  throw unknown_shape(name);
}

#endif  // FACTORY_HPP
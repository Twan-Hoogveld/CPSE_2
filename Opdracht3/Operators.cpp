#include "Operators.hpp"

istream& operator>>(istream& input, Vector2f& rhs) {
  char c;
  if (!(input >> c)) {
    throw end_of_file();
  }
  if (c != '(') {
    throw invalid_position(c);
  }
  if (!(input >> rhs.x)) {
    throw end_of_file();
  }
  if (!(input >> c)) {
    throw end_of_file();
  }
  if (!(input >> rhs.y)) {
    throw end_of_file();
  }
  if (!(input >> c)) {
    throw end_of_file();
  }
  if (c != ')') {
    throw invalid_position(c);
  }
  return input;
}

istream& operator>>(istream& input, Color& rhs) {
  string col;
  input >> col;
  if (col == "") {
    throw end_of_file();
  }
  const struct {
    const char* name;
    Color color;
  } colors[]{{"yellow", Color::Yellow},   {"red", Color::Red},     {"green", Color::Green},
             {"cyan", Color::Cyan},       {"blue", Color::Blue},   {"black", Color::Black},
             {"magenta", Color::Magenta}, {"white", Color::White}, {"transparant", Color::Transparent}};

  for (auto const& color : colors) {
    if (color.name == col) {
      rhs = color.color;
      return input;
    }
  }
  throw unknown_color(col);
}

ostream& operator<<(ostream& output, Vector2f& rhs){
	string str_out = "(" + to_string(int(rhs.x)) + "," + to_string(int(rhs.y)) + ")";
	output << str_out;
	return output;
}

ostream& operator<<(ostream& output, Color& rhs){
	const struct {
    const char* name;
    Color color;
  } colors[]{{"yellow", Color::Yellow},   {"red", Color::Red},     {"green", Color::Green},
             {"cyan", Color::Cyan},       {"blue", Color::Blue},   {"black", Color::Black},
             {"magenta", Color::Magenta}, {"white", Color::White}, {"transparant", Color::Transparent}};
	
	for(auto const& color : colors){
		if(color.color == rhs){
			output << color.name;
			return output;
		}
	}
	throw unknown_color(rhs);
}

#include "Exceptions.hpp"

string colorToString(const Color& col){
	string red = "R: " + to_string(col.r) + "\n";
	string green = "G: " + to_string(col.g) + "\n";
	string blue = "B: " + to_string(col.b) + "\n";
	return red + green + blue;
}
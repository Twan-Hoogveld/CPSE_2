#include "Line.hpp"

void Line::updatePosition(){
	own_line[0].position = pos;
	own_line[1].position = pos2;
}

void Line::move(const Vector2f& velo) { 
	pos += velo;
	pos2 += velo;
}

void Line::jump(const Vector2f& new_pos){
	pos = new_pos;
	pos2 = new_pos + diff_pos;
}

FloatRect Line::getBound(){
	return FloatRect(pos, diff_pos);
}

void Line::draw(RenderWindow& window){
	updatePosition();
	window.draw(own_line);
}

ostream& Line::writeToFile(ostream& output){
	output << pos << " LINE " << color << " " << pos2;
	return output;
}
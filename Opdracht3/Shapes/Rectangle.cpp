#include "Rectangle.hpp"

void Rectangle::move(const Vector2f& velo) { 
	pos += velo;
	pos2 += velo;
}

void Rectangle::jump(const Vector2f& new_pos){
	pos = new_pos;
	pos2 = new_pos + diff_pos;
}

FloatRect Rectangle::getBound(){
	return rect.getGlobalBounds();
}
void Rectangle::draw(RenderWindow& window){
	rect.setPosition(pos);
	window.draw(rect);
}

ostream& Rectangle::writeToFile(ostream& output){
	output << pos << " RECTANGLE " << color << " " << pos2;
	return output;
}
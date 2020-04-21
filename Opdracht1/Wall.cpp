#include "Wall.hpp"

void Wall::draw(RenderWindow& window){
	window.draw(rectangle);
}

void Wall::update(){
}

void Wall::interact(const ScreenObject& other){
}

FloatRect Wall::getBound() const{
	return rectangle.getGlobalBounds();
}
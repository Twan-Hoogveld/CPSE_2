#include "Block.hpp"
#include <iostream>

void moveableBlock::draw(RenderWindow& window) { 
	rect.setPosition(pos);
	window.draw(rect); }

void moveableBlock::update() {}

void moveableBlock::interact(const ScreenObject& other) {}

FloatRect moveableBlock::getBound() const { return rect.getGlobalBounds(); }

void moveableBlock::move(sf::Vector2f delta) { pos += delta; }

void moveableBlock::jump(sf::Vector2f target) { pos = target; }

void moveableBlock::jump(sf::Vector2i target) {
  jump(sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
}

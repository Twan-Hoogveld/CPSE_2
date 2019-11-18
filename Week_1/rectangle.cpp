#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

Rectangle::Rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size):
    position{position},
    color{color},
    size{size}
    {}

void Rectangle::move(const sf::Vector2f & delta){
    position += delta;
}

void Rectangle::jump(const sf::Vector2f & target){
    position = target;
}

void Rectangle::draw(sf::RenderWindow & window) const {
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize(size);
    rectangleShape.setPosition(position);
    rectangleShape.setFillColor(color);
    window.draw(rectangleShape);    
}

sf::Vector2f Rectangle::getPosition(){
    return position;
}
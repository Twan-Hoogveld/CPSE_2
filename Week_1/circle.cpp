#include "circle.hpp"
#include <SFML/Graphics.hpp>

Circle::Circle(sf::Vector2f position, sf::Vector2f speed, float size):
    position{position},
    speed{speed},
    size{size}
    {}

void Circle::move(const sf::Vector2f & delta){
    position += delta;
}

void Circle::jump(const sf::Vector2f & target){
    position = target;
}

void Circle::update(){
    position += speed;
}

void Circle::draw(sf::RenderWindow & window) const {
    sf::CircleShape circleShape;
    circleShape.setRadius(size);
    circleShape.setPosition(position);
    sf::Color color =  sf::Color(0,100,100);
    circleShape.setFillColor(color);
    window.draw(circleShape);
}

float Circle::getSize(){
    return size;
}

sf::Vector2f Circle::getPosition(){
    return position;
}

sf::FloatRect Circle::getGlobalBounds(){
    sf::CircleShape circleShape;
    circleShape.setRadius(size);
    circleShape.setPosition(position);
    return circleShape.getGlobalBounds();
}

void Circle::bounce(sf::Vector2f delta){
    speed.x *= delta.x;
    speed.y *= delta.y;
}
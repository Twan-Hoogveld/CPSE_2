#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "objects.hpp"

class Rectangle : public Object{
  
    private:
        sf::Vector2f position;
        sf::Color color;
        sf::Vector2f size;

    public:
        Rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size = sf::Vector2f{20,10});
        void move(const sf::Vector2f & delta);
        void jump(const sf::Vector2f & target);
        void draw(sf::RenderWindow & window) const override;
        sf::Vector2f getPosition();
        sf::FloatRect getGlobalBounds(){ 
            sf::RectangleShape rectangle;
            rectangle.setSize(size), 
            rectangle.setPosition(position);
            return rectangle.getGlobalBounds();}
};

#endif 
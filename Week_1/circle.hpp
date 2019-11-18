#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "objects.hpp"

class Circle: public Object {
    private:
        sf::Vector2f position;
        sf::Vector2f speed;
        float size;
    
    public:
        Circle(sf::Vector2f position, sf::Vector2f speed, float size = 30.0);
        void move(const sf::Vector2f & delta);
        void jump(const sf::Vector2f & target);
        void draw(sf::RenderWindow & window) const override;
        void update();
        sf::Vector2f getPosition();
        float getSize();
        sf::FloatRect getGlobalBounds();
        void bounce(sf::Vector2f delta);
};

#endif
#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include "SFML/Graphics.hpp"

class Object{
    public:
        virtual void draw(sf::RenderWindow & window) const = 0;
};

#endif

//File is done.
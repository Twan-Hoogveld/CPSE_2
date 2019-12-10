#ifndef SCREENOBJECT_HPP
#define SCREENOBJECT_HPP

#include <SFML/Graphics.hpp>

class ScreenObject : public sf::Drawable {
    private:
        sf::Vector2f position;
        sf::Vector2f position2;
        std::string filename;
        float size;

    public:
        ScreenObject(sf::Vector2f position){
            position = position;
        }
        ScreenObject * read(std::ifstream & input){
            sf::Vector2f pos;
            std::string name;
            input >> pos >> name;
            return new Circle (pos,name);
    }

};

#endif
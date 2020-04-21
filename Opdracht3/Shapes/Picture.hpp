#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "MoveableObject.hpp"
#include <iostream>

using sf::Texture;
using sf::Sprite;
using std::cout;
using std::endl;


class Picture : public MoveableObject {
	private:
	string filename;
	Texture texture;
	Sprite sprite;

	public:
	Picture(const Vector2f& pos, const std::string& filename): MoveableObject(pos), filename(filename){
		if(!texture.loadFromFile(filename)){
			cout << "WAAAA afbeelding faalt" << endl;
		}
		texture.setSmooth(true);
		sprite.setTexture(texture);
	}

	void move(const Vector2f& velo) override;
  void jump(const Vector2f& new_pos) override;
	FloatRect getBound() override;
  void draw(RenderWindow& window) override;
	ostream& writeToFile(ostream& output) override;
};

#endif //PICTURE_HPP
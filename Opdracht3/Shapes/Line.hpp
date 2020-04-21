#ifndef LINE_HPP
#define LINE_HPP

#include "MoveableObject.hpp"

using sf::VertexArray;

class Line : public MoveableObject {
	private:
	Vector2f pos2;
	Vector2f diff_pos;
  Color color;
	VertexArray own_line;

	public:
	Line(const Vector2f& pos, const Vector2f& pos2, Color col = Color::White): MoveableObject(pos), pos2(pos2), color(col){
		diff_pos = pos2 - pos;

		own_line.setPrimitiveType(sf::Lines);
		own_line.resize(2);
		updatePosition();
		own_line[0].color = color;
		own_line[1].color = color;
	}

	void updatePosition();
	void move(const Vector2f& velo) override;
  void jump(const Vector2f& new_pos) override;
	FloatRect getBound() override;
  void draw(RenderWindow& window) override;
	ostream& writeToFile(ostream& output) override;
};

#endif //LINE_HPP
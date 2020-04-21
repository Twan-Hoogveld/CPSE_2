#include "MoveableObject.hpp"

void MoveableObject::jump(const Vector2i& new_pos) { jump(Vector2f(new_pos)); }

void DummyMoveableObject::move(const Vector2f& velo){}
void DummyMoveableObject::jump(const Vector2f& new_pos){}
FloatRect DummyMoveableObject::getBound() { return FloatRect(); }
void DummyMoveableObject::draw(RenderWindow& window) {}
ostream& DummyMoveableObject::writeToFile(ostream& output) { return output; }
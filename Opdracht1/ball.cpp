#include "ball.hpp"

using std::cout;
using std::endl;

void coutRect(FloatRect to_print) {
  cout << "X,Y: " << to_print.left << ',' << to_print.top << endl;
  cout << "W,H: " << to_print.width << ',' << to_print.height << endl;
}

void ball::collision(bool collide_x) {
  if (collide_x) {
    velocity.y *= -0.8;
  } else {
    velocity.x *= -0.8;
  }
}

void ball::draw(RenderWindow& window) { window.draw(circle); }

void ball::update() {
  updateSpeed({1.005, 1.005});
  pos += velocity;
  if (velocity.x > 10) {
    velocity.x = 10;
  }
  if (velocity.y > 10) {
    velocity.y = 10;
  }
  circle.setPosition(pos);
}

void ball::updateSpeed(const Vector2f& accel) {
  velocity.x *= accel.x;
  velocity.y *= accel.y;
}

void ball::interact(const ScreenObject& other) {
  FloatRect oth_bound = other.getBound();
  FloatRect own_bound = getBound();
  if (own_bound.intersects(oth_bound)) {
    // First check Y axis
    Vector2f new_pos = pos;
    new_pos.y -= velocity.y;
    circle.setPosition(new_pos);
    FloatRect new_bound = getBound();
    if (!new_bound.intersects(oth_bound)) {
      // Intersects on X axis
      collision(true);
    } else {
      circle.setPosition(pos);
    }
    // Second check X axis
    new_pos = pos;
    new_pos.x -= velocity.x;
    circle.setPosition(new_pos);
    new_bound = getBound();
    if (!new_bound.intersects(oth_bound)) {
      // Intersects on Y axis
      collision(false);
    } else {
      circle.setPosition(pos);
    }
  }
}

FloatRect ball::getBound() const { return circle.getGlobalBounds(); }

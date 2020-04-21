#ifndef ACTION_HPP
#define ACTION_HPP

#include <SFML/Window.hpp>
#include <functional>
#include "ScreenObject.hpp"
#include "array"
#include "ball.hpp"

using sf::Keyboard;
using sf::Mouse;
using std::array;
using std::function;

class Action {
 private:
  function<bool()> condition;
  function<void()> work;

 public:
  Action(function<bool()> condition, function<void()> work) : condition(condition), work(work) {}

  Action(function<void()> work) : condition([]() -> bool { return true; }), work(work) {}

  Action(array<ScreenObject*, 6> objects, function<void()> work)
      : condition([&objects]() -> bool {
          for (ScreenObject* obj : objects) {
            for (ScreenObject* obj_col : objects) {
              if (obj != obj_col) {
                obj->interact(*obj_col);
              }
            }
          }
          return true;
        }),
        work(work) {}

  Action(Keyboard::Key key, function<void()> work)
      : condition([key]() -> bool { return Keyboard::isKeyPressed(key); }), work(work) {}

  Action(Mouse::Button button, function<void()> work)
      : condition([button]() -> bool { return Mouse::isButtonPressed(button); }), work(work) {}

  void operator()() {
    if (condition()) {
      work();
    }
  }
};

#endif  // ACTION_HPP
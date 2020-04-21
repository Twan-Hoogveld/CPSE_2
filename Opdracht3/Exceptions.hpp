#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>
#include "SFML/Graphics.hpp"

using std::exception;
using std::string;
using sf::Color;
using std::to_string;

string colorToString(const Color& col);

class end_of_file : public exception {
 private:
  string message = "end of file";

 public:
  const char* what() const noexcept override { return message.c_str(); }
};

class unknown_shape : public exception {
 private:
  string message;

 public:
  unknown_shape(const string& name) { message = "Unknown shape: " + name; }

  const char* what() const noexcept override { return message.c_str(); }
};

class unknown_color : public exception {
 private:
  string message;

 public:
  unknown_color(const string& color) { message = "Unknown color: " + color; }
	unknown_color(const Color& color) { message = "Unknown color: " + colorToString(color); }

  const char* what() const noexcept override { return message.c_str(); }
};

class invalid_position : public exception {
 private:
  string message;

 public:
  invalid_position(const char& c) { message = "invalid position: " + c; }

  const char* what() const noexcept override { return message.c_str(); }
};

#endif //EXCEPTIONS_HPP
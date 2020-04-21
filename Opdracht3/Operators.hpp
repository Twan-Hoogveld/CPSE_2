#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include "Exceptions.hpp"
#include "istream"

using sf::Vector2f;
using std::istream;
using std::ostream;

istream& operator>>(istream& input, Vector2f& rhs);

istream& operator>>(istream& input, Color& rhs);

ostream& operator<<(ostream& output, Vector2f& rhs);

ostream& operator<<(ostream& output, Color& rhs);

#endif  // OPERATORS_HPP
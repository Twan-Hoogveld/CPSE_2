using namespace std;
#include <iostream>
#include "SFML/Graphics.hpp"
#include "objects.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
using namespace std;


int main(){

   //Make the window
   sf::RenderWindow window{ sf::VideoMode{640,480}, "Week 01"};

   //Make Colors
   sf::Color color01 = sf::Color(150,0,0);
   sf::Color color02 = sf::Color(250,0,200);

   //Make Objects
   Circle circle        {sf::Vector2f{320,240}, sf::Vector2f{3,7}};
   Rectangle topWall    {sf::Vector2f{0,0}, color01, sf::Vector2f {640,30}};
   Rectangle bottomWall {sf::Vector2f{0, 450}, color01, sf::Vector2f{640, 30}};
   Rectangle leftWall   {sf::Vector2f{0, 0}, color01, sf::Vector2f{30, 480}};
   Rectangle rightWall  {sf::Vector2f{610, 0}, color01, sf::Vector2f{30, 480}};
   Rectangle middleRect {sf::Vector2f{80,80} , color02, sf::Vector2f{270,30}};

   sf::Rect<float> intersectionRect;
   intersectionRect.width = 0;
   intersectionRect.height = 0;  

   window.clear();

   circle.draw(window);
   
   //List with all included
   Rectangle * rectangleList[5] = { &topWall, &bottomWall, &leftWall, &rightWall, &middleRect};

   for(auto x : rectangleList){
      x -> draw(window);
   }

   window.display();

   while(window.isOpen()){
      sf::Event event;
      if (event.type == sf::Event::Closed){
         window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { middleRect.move(sf::Vector2f{-7,0});}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){middleRect.move(sf::Vector2f{+7, 0});}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){middleRect.move(sf::Vector2f{0, -7});}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){middleRect.move(sf::Vector2f{0, +7});}

      circle.update();

      for (int i = 0; i < 5; i++)
      {
         if (circle.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRect))
         {

            if (int(circle.getPosition().x) == int(intersectionRect.left) && intersectionRect.height == circle.getSize() * 2)
            {
               circle.bounce(sf::Vector2f{-1,1});
               while ((intersectionRect.width < 59 && intersectionRect.width > 7) || (intersectionRect.height < 59 && intersectionRect.height > 7))
               {
                  circle.update();
                  circle.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRect);
               }
            }
            else if (int(circle.getPosition().x + int(circle.getSize() * 2) - 1) == int(intersectionRect.left))
            {
               circle.bounce(sf::Vector2f{-1, 1});
               while ((intersectionRect.width < 59 && intersectionRect.width > 7) || (intersectionRect.height < 59 && intersectionRect.height > 7))
               {
                  circle.update();
                  circle.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRect);
               }
            }
            else
            {
               circle.bounce(sf::Vector2f{1, -1});
               while ((intersectionRect.width < 59 && intersectionRect.width > 7) || (intersectionRect.height < 59 && intersectionRect.height > 7))
               {
                  circle.update();
                  circle.getGlobalBounds().intersects(rectangleList[i]->getGlobalBounds(), intersectionRect);
               }
            }
         }
      }

      window.clear();
      circle.draw(window);
      for (auto x : rectangleList)
      {
         x->draw(window);
      }
      window.display();
      sf::sleep(sf::milliseconds(20));
   }
   return 0;
}
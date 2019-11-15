using namespace std;
#include <iostream>
#include "SFML/Graphics.hpp"

int main(int argc, char **argv){

   //Make the window.
   sf::RenderWindow window(sf::VideoMode(800,600), "SFML window");

   //Make a vector for easy adding and drawing objects.
   std::vector<sf::RectangleShape> shapes;

   //Create the objects
   sf::RectangleShape leftWall(sf::Vector2f(10,590));
   sf::RectangleShape rightWall(sf::Vector2f(10,590));
   sf::RectangleShape topWall(sf::Vector2f(790,10));
   sf::RectangleShape bottomWall(sf::Vector2f(790,10));
   sf::RectangleShape randomBlock(sf::Vector2f(75,75));
   sf::CircleShape circle(20);

   //Set positions of the Walls.
   leftWall.setPosition(0,10);
   topWall.setPosition(0,0);
   rightWall.setPosition(790,0);
   bottomWall.setPosition(10,590);

   int blockX = 400;
   int blockY = 300;
   randomBlock.setPosition(blockX,blockY);

   int circleX = 20;
   int circleY = 20;
   circle.setPosition(circleX,circleY);

   //Add objects to the vector
   shapes.push_back(leftWall);
   shapes.push_back(rightWall);
   shapes.push_back(topWall);
   shapes.push_back(bottomWall);

   //Draw all the objects before starting
   for (const auto & x : shapes){ window.draw(x); }

   //Showing the window and actions.
   while(window.isOpen()){
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed){
            window.close();
         }
      }

      if(event.type == sf::Event::KeyPressed){
         switch (event.key.code){
         case 71:
            randomBlock.setPosition(blockX--,blockY);
            break;
         case 72:
            randomBlock.setPosition(blockX++,blockY);            
            break;
         case 73:
            randomBlock.setPosition(blockX,blockY--);            
            break;
         case 74: 
            randomBlock.setPosition(blockX,blockY++);
            break;
         default:
            break;
         }
      }

      window.clear();

      circle.setPosition(circleX++,circleY++);
      
      for (const auto & x : shapes){
         window.draw(x);
      }

      window.draw(circle);
      window.draw(randomBlock);
      window.display();
      sf::sleep(sf::milliseconds(10));
   }
   return EXIT_SUCCESS;
}

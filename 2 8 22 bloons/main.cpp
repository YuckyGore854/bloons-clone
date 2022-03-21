//"bloons" style game, part 1
//coded by Dr. Mo, Feb 2022
//dynamicsofanasteroid.com
#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
#include<math.h>
#include"bloon.h"
#include"point.h"

using namespace std;

//discussion questions for students:
//1) How would you *avoid* diagonals in the path? How do you purposely create them?
//2) Why the "-1" in this line: if(currPath < pathPoints.size()-1)? Why is it needed?
//3) What's the difference between a struct and a class? Could we have used a class instead of a struct?


//create a struct: structs are like classes, but no functions (just variables)



int main() {
	//set up path points using the struct we made
	//set up path points using the struct we made
	struct point p1;
	p1.x = 443;
	p1.y = 793;
	struct point p2;
	p2.x = 443;
	p2.y = 578;
	struct point p3;
	p3.x = 200;
	p3.y = 579;
	struct point p4;
	p4.x = 200;
	p4.y = 278;
	struct point p5;
	p5.x = 290;
	p5.y = 278;
	struct point p6;
	p6.x = 290;
	p6.y = 449;
	struct point p7;
	p7.x = 658;
	p7.y = 449;
	struct point p8;
	p8.x = 658;
	p8.y = 622;
	struct point p9;
	p9.x = 537;
	p9.y = 622;
	struct point p10;
	p10.x = 537;
	p10.y = 167;
	struct point p11;
	p11.x = 407;
	p11.y = 167;
	struct point p12;
	p12.x = 407;
	p12.y = 340;
	struct point p13;
	p13.x = 800;
	p13.y = 340;
	struct point p14;
	p14.x = 900;
	p14.y = 340;


	//set up vector to hold path points, push path points into it
	vector <point> pathPoints;
	pathPoints.push_back(p1);
	pathPoints.push_back(p2);
	pathPoints.push_back(p3);
	pathPoints.push_back(p4);
	pathPoints.push_back(p5);
	pathPoints.push_back(p6);
	pathPoints.push_back(p7);
	pathPoints.push_back(p8);
	pathPoints.push_back(p9);
	pathPoints.push_back(p10);
	pathPoints.push_back(p11);
	pathPoints.push_back(p12);
	pathPoints.push_back(p13);
	pathPoints.push_back(p14);


	// create game window
	sf::RenderWindow window(sf::VideoMode(800, 800), "bloons");
	window.setFramerateLimit(60);


	//balloon variables
	float xpos = p1.x; //start off screen
	float ypos = p1.y;
	
	int currPath = 0; //begin heading towards the first point in the pathing vector

	vector<bloon*> blons;
	vector<bloon*>::iterator blonsIter;
	int tiktak = 0;
	
	
	bloon red(xpos, ypos, pathPoints,2);

	// GAME LOOP----------------------------------------------------------------------------------------
	while (window.isOpen()){
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {

			}
		}
		for (blonsIter = blons.begin(); blonsIter != blons.end();) {
			if ((*blonsIter)->atPathEnd() && blons.size() > 0) {
				(*blonsIter)->~bloon();
				delete* blonsIter;
				blonsIter = blons.erase(blonsIter);
			}
			else {
				++blonsIter;
			}
		}
		tiktak++;
		if (tiktak % 10 == 0) {
			blons.push_back(new bloon(xpos, ypos, pathPoints, 1));
		}
		if (tiktak % 15 == 0) {
			blons.push_back(new bloon(xpos, ypos, pathPoints, 2));
		}
		if (tiktak % 18 == 0) {
			blons.push_back(new bloon(xpos, ypos, pathPoints, 3));
		}
		for (blonsIter = blons.begin(); blonsIter != blons.end(); blonsIter++) {
			(*blonsIter)->move();
		}

		red.move();

		// Render section----------------------------------------------------------------
		window.clear(sf::Color::Black);
		for (blonsIter = blons.begin(); blonsIter != blons.end(); blonsIter++) {
			(*blonsIter)->draw(window);
		}
		red.draw(window);
		
		window.display();
	}

	return 0;//buh bye
}


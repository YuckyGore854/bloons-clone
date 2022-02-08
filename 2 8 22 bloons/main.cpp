//"bloons" style game, part 1
//coded by Dr. Mo, Feb 2022
//dynamicsofanasteroid.com
#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
#include<fstream>
using namespace std;

//discussion questions for students:
//1) How would you *avoid* diagonals in the path? How do you purposely create them?
//2) Why the "-1" in this line: if(currPath < pathPoints.size()-1)? Why is it needed?
//3) What's the difference between a struct and a class? Could we have used a class instead of a struct?


//create a struct: structs are like classes, but no functions (just variables)
struct point {
	int x;
	int y;
};


int main() {
	enum states { EDITING, PLAYING };
	int gameState = EDITING;
	ofstream file1;
	file1.open("test.txt");
	file1 << "Does this work?" << endl;
	file1.close();
	//set up path points using the struct we made
	struct point p1;
	p1.x = 443;
	p1.y = 793;
	struct point p2;
	p2.x = 443;
	p2.y = 579;
	struct point p3;
	p3.x = 200;
	p3.y = 579;
	struct point p4;
	p4.x = 200;
	p4.y = 278;


	//set up vector to hold path points, push path points into it
	vector <point> pathPoints;
	pathPoints.push_back(p1);
	pathPoints.push_back(p2);
	pathPoints.push_back(p3);
	pathPoints.push_back(p4);


	// create game window
	sf::RenderWindow window(sf::VideoMode(800, 800), "bloons");

	//balloon variables
	float xpos = -50; //start off screen
	float ypos = 400;
	sf::CircleShape bloon(25);
	bloon.setFillColor(sf::Color(250, 0, 0));
	bloon.setPosition(xpos, ypos);
	int currPath = 0; //begin heading towards the first point in the pathing vector
	int ticker = 0;



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

		switch (gameState) {
		case EDITING:
			ofstream file1;
			file1.open("map.txt");

		}

		//pathing algorithm*******************************************************************
		//this works by moving the x and y coord of our baloon towards the (x,y) of the next point in the path
		//the path is stored as a series of points in a vector called "pathPoints"

		ticker++; //slow dem bloons down
		if (ticker % 30 == 0) { //make 30 bigger to slow down baloon more

			//first check if you're at the turning point, move to next point if you are
			if ((xpos == pathPoints[currPath].x) && (ypos == pathPoints[currPath].y))
				if (currPath < pathPoints.size() - 1) //don't walk off end of vector!
					currPath++; //iterate to next point

			//if not there yet, move our x towards x position of next junction
			if (xpos < pathPoints[currPath].x)
				xpos += 1;
			if (xpos > pathPoints[currPath].x)
				xpos -= 1;
			//and move our y towards y position of next junction
			if (ypos < pathPoints[currPath].y)
				ypos += 1;
			if (ypos > pathPoints[currPath].y)
				ypos -= 1;
		}//end pathing algorithm**************************************************************


		//move da bloon
		bloon.setPosition(xpos, ypos);

		// Render section----------------------------------------------------------------
		window.clear(sf::Color::Black);
		window.draw(bloon);
		window.display();
	}

	return 0;//buh bye
}
#include"bloon.h"

bloon::bloon(double x, double y, vector<point>Path, int which) {
	xpos = x;
	ypos = y;
	currPath = 0;
	myPath = Path;
	type = which;
	if (type == 1) {
		speed = 5;
		bloonCircle.setFillColor(sf::Color(250, 0, 0));
		bloonCircle.setRadius(20);
	}
	if (type == 2) {
		speed = 7;
		bloonCircle.setFillColor(sf::Color(0, 0, 255));
		bloonCircle.setRadius(25);
	}
	if (type == 3) {
		speed = 9;
		bloonCircle.setFillColor(sf::Color(0, 255, 0));
		bloonCircle.setRadius(30);
	}


	ticker = 0;


	bloonCircle.setPosition(xpos, ypos);
}
bloon::~bloon() { }
void bloon::move() {
	//pathing algorithm*******************************************************************
	//this works by moving the x and y coord of our baloon towards the (x,y) of the next point in the path
	//the path is stored as a series of points in a vector called "pathPoints"

	ticker++; //slow dem bloons down
	if (ticker % 100 == 0) { //make 30 bigger to slow down baloon more

		//if (ypos < ((myPath[currPath].y += speed -= 1)) && ypos >(myPath[currPath].y += (speed -= 1))) {
		//	ypos = myPath[currPath].y;
		//}

		//first check if you're at the turning point, move to next point if you are
		if (sqrt((xpos - myPath[currPath].x) * (xpos - myPath[currPath].x) + (ypos - myPath[currPath].y) * (ypos - myPath[currPath].y)) < bloonCircle.getRadius())//circular collision lol
			if (currPath < myPath.size() - 1) //don't walk off end of vector!
				currPath++; //iterate to next point


		//if not there yet, move our x towards x position of next junction
		if (xpos < myPath[currPath].x)
			xpos += speed;
		if (xpos > myPath[currPath].x)
			xpos -= speed;
		//and move our y towards y position of next junction
		if (ypos < myPath[currPath].y)
			ypos += speed;
		if (ypos > myPath[currPath].y)
			ypos -= speed;
	}//end pathing algorithm**************************************************************
	bloonCircle.setPosition(sf::Vector2f(xpos, ypos));
}
void bloon::draw(sf::RenderWindow& window) {
	window.draw(bloonCircle);
}
bool bloon::atPathEnd() {
	//cout << myPath.size() << " " << currPath << " "<<endl;
	return currPath == myPath.size() - 1;
}
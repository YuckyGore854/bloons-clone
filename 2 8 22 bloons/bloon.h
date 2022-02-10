#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include"point.h"
using namespace std;

class bloon {
private:
	double xpos;
	double ypos;
	int currPath;
	int ticker;
	int type;
	int speed;
	sf::CircleShape bloonCircle;
	vector<point>myPath;
public:
	bloon(double x, double y, vector<point>Path, int which);
	~bloon();
	bool atPathEnd();
	void move();
	void draw(sf::RenderWindow& window);
	void print() { cout << xpos << " " << ypos << endl; }
};
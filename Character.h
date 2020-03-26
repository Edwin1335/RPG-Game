#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

class Character
{
private:
	string name;
	string race;
	int level;
	int health;

public:
	// Overlaoded constructor (parameterized)
	Character(string, string, int , int);

	// Mutators
	void setName(string);
	void setRace(string);
	void setLevel(int);
	void setHealth(int);

	// Accessors 
	string getName() const;
	string getRace() const;
	int getLevel() const;
	int getHealth() const;

	// Pure virtual funtions
	virtual void Attack(Character*) = 0;
	virtual void print() = 0;
};
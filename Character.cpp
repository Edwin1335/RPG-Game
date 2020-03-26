#include "Character.h"

// Initialize all the attributes with user input
Character::Character(string name, string race, int level, int health)
{
	this->name = name;
	this->race = race;
	this->level = level;
	this->health = health;
}

// Mutors
void Character::setName(string name)
{
	this->name = name;
}

void Character::setRace(string race)
{
	this->race = race;
}

void Character::setLevel(int level)
{
	this->level = level;
}

void Character::setHealth(int health)
{
	this->health = health;
}

// Accessors
string Character::getName() const
{
	return name;
}

string Character::getRace() const
{
	return race;
}

int Character::getLevel() const
{
	return level;
}

int Character::getHealth() const
{
	return health;
}
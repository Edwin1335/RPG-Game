#pragma once
#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"

class Game
{
private:
	Character* players[2];
	int current_turn;
	int num_of_characters = 0;

public:
	void RemoveCharacter(int);
	void AddCharacter(Character*);
	void NextTurn();
};

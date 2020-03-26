#pragma once
#include "Character.h"

class Wizard :
	public Character
{
private:
	
	struct spell
	{
		string name;
		int mana_cost;
		int damage;
	};

	int mana;
	spell spells[10];
	int numOfSpells;

public:
	Wizard(string, string, int, int, int);

	void setMana(int);
	int getMana() const;

	int addSpell(string, int, int);

	virtual void Attack(Character*, int);
	virtual void Attack(Character*);
	virtual void print();
};


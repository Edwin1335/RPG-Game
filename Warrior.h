#pragma once
#include "Character.h"

class Warrior : public Character
{
private:
	// Personalise Weapon
	struct weapon
	{
		string name = "";
		int damage = -1;
		int stamina_cost = -1;
	};
	int stamina;
	weapon active_weapon;

public:

	Warrior(string, string, int, int, int);

	void setStamina(int);
	int getStamina() const;

	void EquiptWeapon(string, int, int);

	virtual void Attack(Character*);

	virtual void print();
};

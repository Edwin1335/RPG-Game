#include "Warrior.h"

Warrior::Warrior(string name, string race, int level, int health, int stamina) : Character(name, race, level, health)
{
	this->stamina = stamina;
}

void Warrior::setStamina(int stamina) 
{
	this->stamina = stamina;
}

int Warrior::getStamina() const
{
	return stamina;
}

void Warrior::EquiptWeapon(string name, int damage, int stamina_cost)
{
	weapon warriorWeapon;
	warriorWeapon.name = name;
	warriorWeapon.damage = damage;
	warriorWeapon.stamina_cost = stamina_cost;

	this->active_weapon = warriorWeapon;
}

void Warrior::Attack(Character* attacked_character)
{
	if (this->active_weapon.name == "")
		cout << "Warrior has no weapon!" << endl;
	else if (this->stamina < this->active_weapon.stamina_cost)
		cout << "Insuficient stamina points!" << endl;
	else
	{
		attacked_character->setHealth(attacked_character->getHealth() - this->active_weapon.damage);
		cout << this->getName() << " attacked " << attacked_character->getName() << " with a " << this->active_weapon.name << ", ";
		cout << "dealing " << this->active_weapon.damage << " damage.\n";
	}
}

void Warrior::print()
{
	cout << "Character Status: \n";
	cout << "Name: " << this->getName() << endl;
	cout << "Race: " << this->getRace() << endl;
	cout << "Level: " << this->getLevel() << endl;
	cout << "Health: " << this->getHealth() << endl;
	cout << "Weapon: " << this->active_weapon.name << endl;
}

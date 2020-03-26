#include "Wizard.h"

Wizard::Wizard(string name, string race, int level, int health, int mana) : Character(name, race, level, health)
{
	this->setMana(mana);
	numOfSpells = 0;
}

void Wizard::setMana(int mana)
{
	this->mana = mana;
}

int Wizard::getMana() const
{
	return mana;
}

int Wizard::addSpell(string spell_name, int spell_damage, int mana_cost)
{
	if (numOfSpells == 10)
	{
		cout << "Spell limits reached! " << endl;
		return -1;
	}
	else
	{
		spell *newSpell = new spell;
		newSpell->name = spell_name;
		newSpell->damage = spell_damage;
		newSpell->mana_cost = mana_cost;

		spells[numOfSpells] = *newSpell;

		numOfSpells++;
		return numOfSpells;
	}
}

void Wizard::Attack(Character* character_attacked)
{
	if (this->numOfSpells == 0)
		cout << "The Wizard has no spells! " << endl;
	else if (this->getMana() < this->spells[0].mana_cost)
		cout << "Insufficeint mana points!" << endl;
	else
	{
		character_attacked->setHealth(character_attacked->getHealth() - this->spells[0].damage);
		cout << this->getName() << " attacked " << character_attacked->getName() << " with spell " << this->spells[0].name << " ";
		cout << "dealing " << this->spells[0].damage << " damage." << endl;
	}
}

void Wizard::Attack(Character* character_attacked, int spellnum)
{
	if (spellnum < 0 || spellnum >= numOfSpells)
		cout << "Invalid spell number!" << endl;
	else if (numOfSpells == 0)
		cout << "The wizrd does not have enough spells!" << endl;
	else if (this->getMana() < spells[spellnum].mana_cost)
		cout << "Insufficient mana points" << endl;
	else
	{
		character_attacked->setHealth(character_attacked->getHealth() - this->spells[spellnum].damage);
		cout << this->getName() << " attacked " << character_attacked->getName() << " with spell " << this->spells[0].name << " ";
		cout << "dealing " << this->spells[0].damage << " damage." << endl;
	}
}

void Wizard::print()
{
	cout << "Character Status: \n";
	cout << "Name: " << this->getName() << endl;
	cout << "Race: " << this->getRace() << endl;
	cout << "Level: " << this->getLevel() << endl;
	cout << "Occupation: Wizard" << endl;
	cout << "Health: " << this->getHealth() << endl;
	cout << "Spells: \n";
	for (int i = 0; i < numOfSpells; i++)
	{
		cout << this->spells[i].name << endl;
	}
}
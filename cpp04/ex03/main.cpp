#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);


	std::cout << std::endl;
	tmp = src->createMateria("cure");
	std::cout << tmp->getType() << " has " << tmp->getXP() << "XP" << std::endl;
	me->equip(tmp);
	me->use(2, *bob);
	std::cout << tmp->getType() << " has " << tmp->getXP() << "XP" << std::endl;
	me->unequip(2);
	me->use(2, *bob);
	std::cout << tmp->getType() << " has " << tmp->getXP() << "XP" << std::endl;
	me->equip(tmp);
	me->use(3, *bob);


	delete bob;
	delete me;
	delete src;
	return 0;
}
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* m;

		m = new Ice(); src->learnMateria(m);
		delete m;
		m = new Cure(); src->learnMateria(m);
		delete m;

		ICharacter* me = new Character("me");

		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		delete tmp;

		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete	bob;
		delete	me;
		delete	src;
	}
	{
		Character dftCharacter("Original");

		AMateria* ice = new Ice();
		dftCharacter.equip(ice);

		Character cpyCharacter(dftCharacter);

		std::cout << "dftCharacter [InvotryPtr] : " << &dftCharacter.getInventory()[0] << std::endl;
		std::cout << "cpyCharacter [InvotryPtr] : " << &cpyCharacter.getInventory()[0] << std::endl;

		dftCharacter.use(0, dftCharacter);
		cpyCharacter.use(0, cpyCharacter);

		delete ice;
	}
	return	(0);
}

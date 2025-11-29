#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "CONSTRUCTOR CALL :" << std::endl;

		Animal	*dftAnimal = new Animal();
		Dog		*dftDog = new Dog();
		Cat		*dftCat = new Cat();

		std::cout << std::endl << "TYPE GUETTER :" << std::endl;

		std::cout << dftAnimal->getType() << std::endl;
		std::cout << dftDog->getType() << std::endl;
		std::cout << dftCat->getType() << std::endl;

		std::cout << std::endl << "ANIMAL SOUNDS :" << std::endl;

		dftAnimal->makeSound();
		dftDog->makeSound();
		dftCat->makeSound();

		std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;

		delete dftAnimal;
		delete dftDog;
		delete dftCat;
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "CONSTRUCTOR CALL :" << std::endl;

		WrongAnimal		*dftWrongAnimal = new WrongAnimal();
		WrongCat		*dftWrongCat = new WrongCat();

		std::cout << std::endl << "TYPE GUETTER :" << std::endl;

		std::cout << dftWrongAnimal->getType() << std::endl;
		std::cout << dftWrongCat->getType() << std::endl;

		std::cout << std::endl << "ANIMAL SOUNDS :" << std::endl;

		dftWrongAnimal->makeSound();
		dftWrongCat->makeSound();

		std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;
		
		delete dftWrongAnimal;
		delete dftWrongCat;
	}
	return (0);
}

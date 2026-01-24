#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	//__________VIRTUAL-TEST__________
	{
		AAnimal* cat = new Cat();

		delete cat;
		std::cout << std::endl;
	}
	//__________DEEP-COPY-TEST__________
	{
		Cat dftCat;
		Cat cpyCat = dftCat;

		Dog dftDog;
		Dog cpyDog = dftDog;

		std::cout << "dftCat [brainPtr]: " << &dftCat.getBrain() << std::endl;
		std::cout << "cpyCat [brainPtr]: " << &cpyCat.getBrain() << std::endl;

		std::cout << "dftDog [brainPtr]: " << &dftDog.getBrain() << std::endl;
		std::cout << "cpyDog [brainPtr]: " << &cpyDog.getBrain() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "CONSTRUCTOR CALL :" << std::endl;

		AAnimal	*catAnimal = new Cat();

		catAnimal->makeSound();
		// Animal	*animal = new Animal();

		// animal->makeSound();

		std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;

		delete catAnimal;
	}
	return (0);
}

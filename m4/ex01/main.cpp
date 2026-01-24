#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main(void)
{
	//__________VIRTUAL-TEST__________
	{
		Animal* a = new Cat();

		delete a;
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
	}
	{
		std::cout << "CONSTRUCTOR CALL :" << std::endl;

		Animal	*animalList[20];

		for (int i = 0; i < 20; i++)
		{
			if (i % 2)
				animalList[i] = new Dog();
			else
				animalList[i] = new Cat();
		}

		std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;

		for (int i = 0; i < 20; i++)
		{
			delete animalList[i];
		}
	}
	return (0);
}

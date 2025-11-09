#ifndef ZOMBIE
# define ZOMBIE

#include <iostream>

class Zombie
{
	public :
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	annonce(void);
		void	setName(std::string name);

	private :
		std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);


#endif

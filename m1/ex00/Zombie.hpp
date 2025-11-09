#ifndef ZOMBIE
# define ZOMBIE

#include <iostream>

class Zombie
{
	public :
		Zombie(std::string name);
		~Zombie(void);
		void annonce(void);

	private :
		std::string _name;
		Zombie(void);
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name);

#endif

#include "Zombie.hpp"
#include <cstdlib>

int	main(int argc, char *argv[])
{
	Zombie		*horde;
	int			horde_size;

	if (argc != 3)
		return (1);
	horde_size = std::atoi(argv[1]);
	horde = zombieHorde(horde_size, argv[2]);
	for (int i = 0; i < horde_size; i++)
	{
		horde[i].annonce();
	}
	delete [](horde);
	return (0);
}

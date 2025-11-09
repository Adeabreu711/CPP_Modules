#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack_zombie("Stack");
	Zombie	*heap_zombie;

	stack_zombie.annonce();
	heap_zombie = newZombie("Heap");
	heap_zombie->annonce();
	randomChump("Random");
	delete (heap_zombie);
	return (0);
}

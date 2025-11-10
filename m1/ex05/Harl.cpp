#include "Harl.hpp"

Harl::Harl(void)
{}

Harl::~Harl(void)
{}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl  << std::endl;
}

int	getLevelID(std::string level)
{
	std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(tab[i]))
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		level_id;

	level_id = getLevelID(level);
	if (level_id == -1)
		std::cerr << "Level doesn't match any existing harl level." << std::endl << std::endl;
	else
		(this->*ptr[level_id])();
}

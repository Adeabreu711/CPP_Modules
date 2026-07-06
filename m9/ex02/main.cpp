#include "PmergeMe.hpp"

int	errorMsg(std::string msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

void	printStats(size_t size, double time)
{
	std::cout	<< "Time to process a range of " 
				<< size 
				<< " elements with std::vector : " 
				<< time 
				<< " us" 
				<< std::endl;
}

template <typename T>
double	PmergeMe(T &container)
{
	clock_t	start = clock();
	fordJohnson(container);
	clock_t	end = clock();
	return ((static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000);
}


int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (errorMsg("Error: Too few arguments"));
	try
	{
		Ivec	vec = parseArgs< Ivec >(argc, argv);
		Ilist	lst = parseArgs< Ilist >(argc, argv);

		printContainer(vec, "Before");

		double	vtime = PmergeMe<Ivec>(vec);
		double	ltime = PmergeMe<Ilist>(lst);

		printContainer(vec, "After");

		printStats(vec.size(), vtime);
		printStats(lst.size(), ltime);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

#include "PmergeMe.hpp"

//______________________UTILS______________________

static size_t	jacobsthal(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);

	size_t	prev = 0;
	size_t	curr = 1;
	size_t	next;

	for (size_t i = 2; i <= n; ++i)
	{
		next = curr + (2 * prev);
		prev = curr;
		curr = next;
	}

	return (curr);
}

//________________________________________________
//_____________________VECTOR_____________________
//________________________________________________

static void	splitSmallBig(Ivec &input, Ivec &small, Ivec &big)
{
	for (size_t i = 0; i < input.size() - 1; i += 2)
	{
		if (input[i] < input[i + 1])
		{
			small.push_back(input[i]);
			big.push_back(input[i + 1]);
		}
		else
		{
			small.push_back(input[i + 1]);
			big.push_back(input[i]);
		}
	}
	if (input.size() % 2 != 0)
	{
		big.push_back(input[input.size() - 1]);
	}
}

static void	insertJacobsthal(Ivec &small, Ivec &big)
{
	if (small.empty())
		return;

	big.insert(std::lower_bound(big.begin(), big.end(), small[0]), small[0]);

	size_t	prev = 1;
	for (size_t k = 3; ; ++k)
	{
		size_t	curr = jacobsthal(k);
		
		if (curr > small.size())
			curr = small.size();

		for (size_t j = curr; j > prev; --j)
		{
			size_t	id = j - 1;
			Ivec::iterator pos;
			pos = std::lower_bound(big.begin(), big.end(), small[id]);
			big.insert(pos, small[id]);
		}
		if (curr == small.size())
			break;
		prev = curr;
	}
}

void	fordJohnson(Ivec &input)
{
	Ivec	small;
	Ivec	big;

	if (input.size() < 2)
		return;

	splitSmallBig(input, small, big);
	fordJohnson(big);
	insertJacobsthal(small, big);
	input = big;
}

//________________________________________________
//______________________LIST______________________
//________________________________________________


static void	splitSmallBig(Ilist &input, Ilist &small, Ilist &big)
{
	Ilist::iterator	it = input.begin();

	while (it != input.end())
	{
		int	first = *it;
		++it;
		if (it == input.end())
		{
			big.push_back(first);
			break;
		}
		int	second = *it;
		if (first < second)
		{
			small.push_back(first);
			big.push_back(second);
		}
		else
		{
			small.push_back(second);
			big.push_back(first);
		}
		++it;
	}
}

static void	insertJacobsthal(Ilist &small, Ilist &big)
{
	if (small.empty())
		return;

	Ilist::iterator	itSmall = small.begin();
	Ilist::iterator	pos;

	pos = std::lower_bound(big.begin(), big.end(), *itSmall);
	big.insert(pos, *itSmall);

	size_t	prev = 1;

	for (size_t k = 3; ; ++k)
	{
		size_t	curr = jacobsthal(k);

		if (curr > small.size())
			curr = small.size();

		for (size_t j = curr; j > prev; --j)
		{
			size_t	id = j - 1;

			itSmall = small.begin();
			std::advance(itSmall, id);
			pos = std::lower_bound(big.begin(), big.end(), *itSmall);
			big.insert(pos, *itSmall);
		}
		if (curr == small.size())
			break;
		prev = curr;
	}
}

void	fordJohnson(Ilist &input)
{
	Ilist	small;
	Ilist	big;

	if (input.size() < 2)
		return;

	splitSmallBig(input, small, big);
	fordJohnson(big);
	insertJacobsthal(small, big);
	input = big;
}

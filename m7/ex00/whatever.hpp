#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &nb1, T &nb2)
{
	T tmp = nb1;

	nb1 = nb2;
	nb2 = tmp;
}

template <typename T>
T	min(T nb1, T nb2)
{
	return (nb1 < nb2 ? nb1 : nb2);
}

template <typename T>
T	max(T nb1, T nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}

#endif

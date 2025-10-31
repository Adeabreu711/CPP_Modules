#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account( int initial_deposit )
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed\n";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";";
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
		<< "\n";
}

bool	Account::makeWithdrawal( int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused\n";
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount-= withdrawal;
	_amount -= withdrawal;
	std::cout
		<< withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< "\n";
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< "\n";
}

void	Account::_displayTimestamp( void )
{
	time_t	timestamp;
	tm*		now;

	timestamp = time(NULL);
	now = localtime(&timestamp);
	std::cout
		<< "[" << now->tm_year + 1900
		<< now->tm_mon + 1 << now->tm_mday
		<< "-" << now->tm_hour
		<< now->tm_min << now->tm_sec
		<< "] ";
}



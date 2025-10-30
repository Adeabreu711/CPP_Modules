#include "Account.hpp"
#include <iostream>

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
	std::cout << "ACCOUNTS INFO :\n\n";
	std::cout << "Accouts Number     : " << _nbAccounts << "\n";
	std::cout << "Total Amount       : " << _totalAmount << "\n";
	std::cout << "Deposit Number     : " << _totalNbDeposits << "\n";
	std::cout << "Withdrawals Number : " << _totalNbWithdrawals << "\n";
}

Account::Account( int initial_deposit )
{
	_totalAmount = initial_deposit;
	_amount = initial_deposit;
}

Account::~Account( void )
{
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal)
{
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal refused\n";
		return (false);
	}
	_totalNbWithdrawals++;
	_totalAmount-= withdrawal;
	_amount -= withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	std::cout << "ACCOUNT[" << _accountIndex << "] INFO :\n\n";
	std::cout << "Accout index       : " << _accountIndex << "\n";
	std::cout << "Amount             : " << _amount << "\n";
	std::cout << "Deposit Number     : " << _nbDeposits << "\n";
	std::cout << "Withdrawals Number : " << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp( void )
{

}

Account::Account( void )
{

}



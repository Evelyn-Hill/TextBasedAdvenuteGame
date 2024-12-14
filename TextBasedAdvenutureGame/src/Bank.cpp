#include "Bank.h"
#include <iostream>

Bank::Bank()
{
	std::cout << "Created a bank account." << std::endl;
}

Bank::~Bank()
{
	std::cout << "Destroyed bank!" << std::endl;
}

double Bank::addFunds(double incrementor)
{	
	m_Funds += incrementor;
	std::cout << "Added: " << incrementor << " to bank account funds. New total: " << m_Funds << std::endl;
	return m_Funds;
}

double Bank::removeFunds(double decrementor)
{
	m_Funds -= decrementor;
	std::cout << "Removed: " << decrementor << " from funds. You now have: " << m_Funds << " remaining." << std::endl;
	return m_Funds;
}

double Bank::getFunds()
{
	return m_Funds;
}

bool Bank::isBalancePositive()
{
	if (m_Funds > 0)
	{
		return true;
	}
	return false;
}

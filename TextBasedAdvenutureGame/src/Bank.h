#pragma once
class Bank
{
private:
	double m_Funds = 0;
public:
	Bank();
	~Bank();

	double removeFunds(double decrementor);
	double addFunds(double incrementor);
	double getFunds();

	bool isBalancePositive();
};


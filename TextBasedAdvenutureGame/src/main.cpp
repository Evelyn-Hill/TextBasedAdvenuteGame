#include <iostream>

#include "Bank.h"
#include "Studio.h"

int main()
{	
	srand(time(NULL));

	std::string studioName;

	std::cout << "Welcome to Eve's epic mode game studio text adventure game." << std::endl;
	std::cout << "Enter the name of your game studio: ";

	std::getline(std::cin, studioName);
	std::cout << "\n";
	
	// Init these on the stack for now, if they get to big we can move them to the heap.
	Studio studio(studioName);
	Bank bank;

	bank.addFunds(10000);

	do {	
		std::cout << "Enter Command: \n";
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "Make Game \n";
		std::cout << "Hire Employee \n";
		std::cout << "List Employees \n";
		std::cout << "--------------------------------------------" << std::endl;

		std::string command;
		std::getline(std::cin, command);
	
		// Main control flow, could use a switch if I made an iterator.
		if (command.compare("Make Game") == 0)
		{
			std::cout << "Unimplemented." << std::endl;
		}
		else if (command.compare("Hire Employee") == 0)
		{
			Employee* e = studio.hireEmployeeSequence(&studio, bank.getFunds());
			bank.removeFunds((double)e->getPrice(e));
		}
		else if (command.compare("List Employees") == 0)
		{
			studio.listEmployees(&studio);
		}
		else
		{
			std::cout << "Invalid Command." << std::endl;
		}	
		command = "";
	} while (bank.isBalancePositive());

	std::cout << "Game over!, You ran out of money!" << std::endl;
}




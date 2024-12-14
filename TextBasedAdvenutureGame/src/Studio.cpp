#include "Studio.h"
#include <iostream>

Studio::Studio(std::string name)
{
	m_StudioName = name;
	std::cout << "Created " << m_StudioName << " game studio" << std::endl;
}

Studio::~Studio()
{
	std::cout << "Closed " << m_StudioName << " game studio" << std::endl;
}

std::string Studio::setStudioName(std::string name)
{
	m_StudioName = name;
	return m_StudioName;
}

std::string Studio::getStudioName()
{
	return m_StudioName;
}

Employee* Studio::addEmployee(Employee* employee)
{
	m_Employees.push_back(employee);
	std::cout << "Added Employee: " << employee->getName(employee) << std::endl;
	employee->printStats(employee);
	return employee;
}

Employee* Studio::generateEmployee(double multiplier)
{
	Employee* employee = new Employee(multiplier);
	return employee;
}

void Studio::listEmployees(Studio* studio)
{
	if (m_Employees.size() == 0) {
		std::cout << "No employees to list." << std::endl;
	}

	std::cout << "-------------------------------\n";
	std::cout << "\n";

	for (Employee* e : m_Employees)
	{
		e->printStats(e);
		std::cout << "-------------------------------\n";
	}
}

Employee* Studio::hireEmployeeSequence(Studio* studio, double availableFunds) {
	
	Employee* employee = NULL;
	
	std::cout << "You will be given 3 options. You must hire one of them!" << std::endl;
	
	for (int i = 1; i <= 3; ++i)
	{
		// If we genereate a number greater than 7 we get a little boost to our employee multiplier.
		int employeeMultiplier = rand() % 10 + 1;
		int hireableEmployeeSkillLevel = m_hireableEmployeeSkillLevel;
		if (employeeMultiplier > 7)
		{
			hireableEmployeeSkillLevel += 2;
		}

		Employee* possibleEmployee = studio->generateEmployee(hireableEmployeeSkillLevel);
	
		std::cout << "Candidate " << i << ": \n";
		std::cout << possibleEmployee->getName(possibleEmployee) << "\n";
		possibleEmployee->printStats(possibleEmployee);
		possibleEmployee->printPrice(possibleEmployee);
		std::cout << "-----------------------------------------------\n";
	
		if (i == 3)
		{
			std::cout << "Last candidate. Must hire!" << std::endl;
			return studio->addEmployee(possibleEmployee);
		}
		
		bool decisionMade = false;
		bool hire;
		do {
			std::string s;

			if (availableFunds - possibleEmployee->getPrice(possibleEmployee) <= 0)
			{		
				std::cout << "Would you like to hire this employee? THIS WILL BANKRUPT YOU! \n";
			}
			else
			{
				std::cout << "Would you like to hire this employee? \n";
			}

			std::getline(std::cin, s);

			if (s.compare("yes") == 0 || s.compare("Yes") == 0)
			{
				decisionMade = true;
				hire = true;
			}
			else if (s.compare("No") == 0 || s.compare("no") == 0)
			{
				std::cout << "On to the next!" << std::endl;
				decisionMade = true;
				hire = false;
			}
			else
			{
				std::cout << "Invalid. You can choose Yes or No \n";
			}
		} while (decisionMade == false);
	
		if (hire)
		{
			return studio->addEmployee(possibleEmployee);
		}
		else
		{
			continue;
		}

		return NULL;
	}

}


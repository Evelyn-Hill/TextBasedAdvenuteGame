#include "Employee.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

Employee::Employee(double multiplier)
{
	// Generate 5 Random numbers and assign them to the employee to create a random employee
	double multiplier_max = 10;
	double multiplier_min = 1;

	// The multiplier should never exceed 10 subcede 1
	multiplier = std::clamp(multiplier, multiplier_min, multiplier_max);
	
	
	int nameIdx = (int)rand() % (m_Names.size() - 1) + 1;

	if (nameIdx > m_Names.size())
	{
		std::cerr << "nameIdx to big, cannot set name!" << std::endl;

	}
	else
	{
		Employee::m_Name = Employee::m_Names[nameIdx];
	}

	
	// Generates the properties of the employee
	m_Stats.ArtScore = (int)(rand() % 10 + 1) * multiplier;
	m_Stats.DesignScore = (int)(rand() % 10 + 1) * multiplier;
	m_Stats.GraphicsScore = (int)(rand() % 10 + 1) * multiplier;
	m_Stats.TechScore = (int)(rand() % 10 + 1) * multiplier;
	

	// Calculate the price of the employee based on the stats.
	// Ideal employee = $20,000
	// (100 * 4) * x = 20,000
	// x = 50	

	int statsTotal = m_Stats.ArtScore + m_Stats.DesignScore + m_Stats.GraphicsScore + m_Stats.TechScore;
	m_Price = statsTotal * 50;


}

Employee::~Employee() {}

void Employee::printStats(Employee* employee)
{	
	std::cout << "Employee " << employee->getName(employee) << " has stats (out of 100): ";
	std::cout << "Art: " << employee->m_Stats.ArtScore << ", ";
	std::cout << "Design: " << employee->m_Stats.DesignScore << ", ";
	std::cout << "Graphics: " << employee->m_Stats.GraphicsScore << ", ";
	std::cout << "Tech: " << employee->m_Stats.TechScore << "\n";
}

void Employee::printPrice(Employee* employee)
{	
	std::cout << employee->getName(employee) << " costs " << employee->getPrice(employee) << " to hire." << "\n";
}

std::string Employee::getName(Employee* employee) 
{
	return employee->m_Name;
}

Employee::Stats Employee::getStats(Employee* employee)
{
	return employee->m_Stats;
}

int Employee::getPrice(Employee* employee)
{
	return m_Price;
}




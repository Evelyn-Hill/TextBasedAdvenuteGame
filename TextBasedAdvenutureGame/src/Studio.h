#pragma once

#include <string>
#include <vector>

#include "Game.h"
#include "Employee.h"

class Studio
{
private:
	std::string m_StudioName = "The Studio";
	std::vector<Game*> m_Games;
	std::vector<Employee*> m_Employees;

	int m_hireableEmployeeSkillLevel = 3;

public:
	Studio(std::string name);
	~Studio();

	std::string setStudioName(std::string name);
	std::string getStudioName();
	Employee* addEmployee(Employee* employee);
	Employee* generateEmployee(double multipler);
	Employee* hireEmployeeSequence(Studio* studio, double availableFunds);
	void listEmployees(Studio* studio);
};

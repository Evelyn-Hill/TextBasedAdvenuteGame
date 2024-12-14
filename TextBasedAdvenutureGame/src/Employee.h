#pragma once
#include <string>
#include <vector>
class Employee
{
private:

	std::vector<std::string> m_Names = { 
		"Michael",
		"Sam",
		"Scout",
		"Shawn",
		"Daniel",
		"Adrian",
		"Sue",
		"Kat",
		"Evelyn",
		"Lucie",
		"Baylee",
		"Joe",
		"Manny",
		"Ryan",
		"Zoey",
	};

	// Employee stats, get fed into the game quality algorithm.
	std::string m_Name = "Employee";
	
	int m_Price = 0;

	struct Stats {
		int DesignScore;
		int GraphicsScore;
		int ArtScore;
		int TechScore;
	};

	Stats m_Stats;
	
public:

	Employee(double multiplier);
	~Employee();
	void printStats(Employee* employee);
	std::string getName(Employee* employee);
	Stats getStats(Employee* employee);
	int getPrice(Employee* employee);
	void printPrice(Employee* employee);
};




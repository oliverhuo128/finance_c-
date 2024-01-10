#include "Student.h"
using namespace OOP;

// The default constructor. Note that it you can call a constructor of the base class here. 
// We actually do not call the default constructor of Person but the one taking specific arguments, since we want to indicate with the name that we have a student
Student::Student() :
	Person("Test Student", 1.5, 50., 18),
	strUniversity("A Test University"),
	strSubject("Sports"),
	Modules({ "Hockey", "Tennis" })
{
	std::cout << "Default constructor of Student called with no given input. It constructs a test student. " << std::endl;
}

// A second constructor takes inout arguments
Student::Student(std::string name, double height, double weight, int age, std::string university, std::string subject, std::vector<std::string> modules) :
	Person(name, height, weight, age),
	strUniversity(university),
	strSubject(subject),
	Modules(modules)
{
	std::cout << "Constructor of Student called with given member variables. " << std::endl;
}


// The destructor
Student::~Student()
{
	std::cout << "Destructor of class Student called. " << std::endl;
}

void Student::SportsAssignment(void)
{
	// Since member data in Person is private, we can only access myName and myHeight through the accessor functions
	if (GetHeight() > 1.8)
	{
		Modules.push_back("Basketball");
		std::cout << "Student " << GetName() << " is assigned to the Basketball course" << std::endl;
	}
	else
	{
		Modules.push_back("Football");
		std::cout << "Student " << GetName() << " is assigned to play Football" << std::endl;
	}
}


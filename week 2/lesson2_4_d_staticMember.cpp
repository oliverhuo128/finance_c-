#include <iostream>
class Person {
public:
	Person(const std::string name = "", const double height = 1.0, const double weight = 1.0, const int age = 18) :
		strName(name), height_m(height), weight_kg(weight), iAge(age) {
		count++;
	}

	virtual ~Person() {
		count--;
	}

	void printName()const {
		std::cout << " name: " << strName << std::endl;
	}

	static void printcount() {
		std::cout << " there are : " << count
			<< " Persons." << std::endl;

	}

	// call me first for class
	static void Initialise() {
		count = 0;
	}

private:
	static int count;
	double weight_kg;
	double height_m;
	std::string strName;
	int iAge;
};	// class Person

int Person::count = 0;    // add this to the class source file

int main() {
	Person::Initialise();
	Person a(""), b("Mary"), c("Mark", 1.0), d("Jin", 1.75, 65, 21), * ptd = &d;
	Person* e = new Person("Yang");
	a.printName(); b.printName(); c.printName(); d.printName(); ptd->printName();
	e->printName();
	Person::printcount();
	delete e;
	return 0;
}

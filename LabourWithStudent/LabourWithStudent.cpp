// LabourWithStudent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Foreman-Inheritance.cpp : Defines the entry point for the console application.
//
/*
multiple level of inheritance
*/

#include "stdafx.h"
#include <iostream>
#include <string>

class Student
{
private:
	std::string school;	// name of the school or uni
	std::string degree; // highest degree
public:
	void getEdu()
	{
		std::cout << "Enter name of school or university: "; 
		std::cin >> school;
		std::cout << "Enter highest degree earned \n";
		std::cout << "Highschool, Bachelor's, Master's, PhD: "; 
		std::cin >> degree;
	}
	void putEdu() const
	{
		std::cout << "\n School or Uni: " << school;
		std::cout << "\n Highest degree earned: " << degree;
	}

};

class Employee			// class employee
{
private:
	std::string name;		// employee name
	unsigned long number;	// employee number
public:
	void getData()
	{
		std::cout << "\nEnter last name: "; std::cin >> name;
		std::cout << "Enter number: "; std::cin >> number;
	}
	void putData() const
	{
		std::cout << "\nName: " << name;
		std::cout << "\nNumber: " << number;
	}
};

class Manager : private Employee, private Student // managemen class
{
private:
	std::string title;		//"vice-president" etc
	double dues;			// golf club dues
public:
	void getData()
	{
		Employee::getData();
		std::cout << "Enter title: "; 
		std::cin >> title;
		std::cout << "\nEnter gold club dues: "; 
		std::cin >> dues;
		Student::getEdu();
	}
	void putData() const
	{
		Employee::putData();
		std::cout << "Title: " << title << std::endl;
		std::cout << "Golf club dues: " << dues << std::endl;
		Student::putEdu();
	}
};

class Scientist : private Employee, private Student // scientist class 
{
private:
	int publication;				// number of publications
public:
	void getData()
	{
		Employee::getData();
		std::cout << "\nEnter number of publication: "; 
		std::cin >> publication;
		Student::getEdu();
	}
	void putData() const
	{
		Employee::putData();
		std::cout << "\nNumber of publications: " << publication << std::endl;
		Student::putEdu();
	}
};

class Laborer : public Employee			//labourer class
{

};

class Foreman : public Laborer			// Foreman class
{
	double quotas;						// percent of quotas met sucessfully
public:
	void getData()
	{
		Laborer::getData();
		std::cout << "\nEnter quota: "; std::cin >> quotas;
	}
	void putData()
	{
		Laborer::putData();
		std::cout << "\nQuotas: "; std::cout << quotas << std::endl;
	}
};


int main()
{
	Manager manager1, manager2;
	Scientist scientist1;
	Laborer laborer1;
	Foreman foreman1;

	// get data for all emploeey groups:
	std::cout << "Enter data for manager 1: ";
	manager1.getData();
	std::cout << std::endl;

	std::cout << "Enter data for manager 2: ";
	manager2.getData();
	std::cout << std::endl;

	std::cout << "Enter data for scientist 1: ";
	scientist1.getData();
	std::cout << std::endl;

	std::cout << "Enter data for labourer 1: ";
	laborer1.getData();
	std::cout << std::endl;

	std::cout << "Enter data for foreman 1: ";
	foreman1.getData();
	std::cout << std::endl;

	system("cls");

	// display data for all emploeey groups:
	std::cout << "\nData on manager 1: ";
	manager1.putData();

	std::cout << "\nData on manager 2: ";
	manager2.putData();

	std::cout << "\nData on scientist 1: ";
	scientist1.putData();

	std::cout << "\nData on labourer 1: ";
	laborer1.putData();

	std::cout << "\nData on foreman 1: ";
	foreman1.putData();

	system("pause");
	return 0;
}

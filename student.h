#pragma once 
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	const static int courseDaysArray = 3;	
private:
	string studentID; 
	string firstName;
	string lastName;
	string emailAddr;
	int age;
	int days[courseDaysArray] = { 0,0,0 }; 
	DegreeProgram degreeProgram = DegreeProgram::UNDECLARED;

public:
	Student(string studentID, string firstName, string lastName, string emailAddr, int age, int days[courseDaysArray], DegreeProgram degreeProgram); 
	~Student();
																																	 
	//Declare getters/accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddr();
	int getAge();
	int* getDays(); 
	DegreeProgram getDegreeProgram();

	//Declare setters/mutators
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(int);
	void setCourseDays(int courseDaysArray[]);
	void setDegreeProgram(DegreeProgram);

	void print();	
};
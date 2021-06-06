#pragma once
#include "student.h"
#include <string>
using namespace std;


class Roster {
public:
	const static int numStudents = 5;		
	Student* classRosterArray[numStudents];		

private:
	int lastIndex = -1;

public:
	void parse(string row);		
	void add(string aStudentID,	 
		string aFirstName,		 
		string aLastName,		
		string aEmailAddress,	
		int aAge,				
		int aDay1,				
		int aDay2,				
		int aDay3,				
		DegreeProgram aDegree);	
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);	//dp? aDegree?

	~Roster();
};
#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

int main() {
	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: #001432044" << endl;
	cout << "Name: Robert Hogue" << endl << endl;
	
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Robert,Hogue,rhogue7@wgu.edu,29,15,21,30,SOFTWARE"
	};

	Roster classRoster;
	const int numStudents = 5;
	
	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students: " << endl;
	classRoster.printAll();
	cout << endl;

	classRoster.printInvalidEmails();
	
	cout << "Average remaining days for: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Displaying students in the SOFTWARE degree program: " << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");	

	return 0;
}
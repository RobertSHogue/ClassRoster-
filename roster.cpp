#include <iostream>
#include <string>
using namespace std;
#include "roster.h"

void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::parse(string studentData) {	
	int rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string fName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string eAddr = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d3 = stoi(studentData.substr(lhs, rhs - lhs));
	
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);	//probably won't work
	DegreeProgram aDegree = DegreeProgram::UNDECLARED;
	if (studentData.substr(lhs, rhs - lhs) == "SECURITY") {
		aDegree = DegreeProgram::SECURITY;
	}
	else if (studentData.substr(lhs, rhs - lhs) == "NETWORK") {
		aDegree = DegreeProgram::NETWORK;
	}
	else if (studentData.substr(lhs, rhs - lhs) == "SOFTWARE") {
		aDegree = DegreeProgram::SOFTWARE;
	}
	
	add(sID, fName, lName, eAddr, age, d1, d2, d3, aDegree);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int courseDaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDaysArray, degreeProgram);
}

void Roster::remove(string studentID) {
	bool found = false;
	cout << "Removing student: " << studentID << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			cout << "Student " << classRosterArray[i]->getStudentID() << " removed.";
			Student* hold = classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex];
			classRosterArray[lastIndex] = hold;
			cout << endl;
			lastIndex--;
		}
	}
	if (found == false) {
		cout << "Student " << studentID << " was not found" << endl;
	}
	cout << endl;
}



void Roster::printAverageDaysInCourse(string studentID) {	//Roster.printAverageDaysInCourse
	cout << "Student " << studentID << ": ";
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << ((double)classRosterArray[i]->getDays()[0] + (double)classRosterArray[i]->getDays()[1] + (double)classRosterArray[i]->getDays()[2]) / 3.0 << " days";
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {	//valid email should include an @ and a . and should not include a space
	cout << "Displaying invalid emails: " << endl;
	bool invalidEmailAddr = false;
	for (int i = 0; i <= lastIndex; i++) {
		string unacceptableEmail = classRosterArray[i]->getEmailAddr();
		if ((unacceptableEmail.find('@') == string::npos || unacceptableEmail.find('.') == string::npos) || unacceptableEmail.find(' ') != string::npos) {
			invalidEmailAddr = true;
			cout << unacceptableEmail << endl;
		}
	}
	if (!invalidEmailAddr) {
		cout << "All emails are valid." << endl;
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

//Destructor for Roster
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

}
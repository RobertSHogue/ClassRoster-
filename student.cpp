#include <iostream>
#include "student.h"
using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddr, int age, int days[courseDaysArray], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddr = emailAddr;
    this->age = age;
    this->days[0] = days[0];
    this->days[1] = days[1];
    this->days[2] = days[2];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {} //destructor

//Getters
string Student::getStudentID() {  
    return studentID;
}
string Student::getFirstName() {
    return this->firstName;
}
string Student::getLastName() {
    return this->lastName;
}
string Student::getEmailAddr() {
    return this->emailAddr;
}int Student::getAge() {
    return this->age;
}
int* Student::getDays() { 
    return this->days;
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram; //is this right?
}

//Setters
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmail(string emailAddr) {
    this->emailAddr = emailAddr;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setCourseDays(int days[courseDaysArray]) {
    this->days[0] = days[0];
    this->days[1] = days[1];
    this->days[2] = days[2];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() {
    cout << "Student ID: " << studentID << '\t';
    cout << "First name: " << firstName << '\t';
    cout << "Last name: " << lastName << '\t';
    cout << "Email: " << emailAddr << '\t';
    cout << "Age: " << age << '\t';
    cout << "DaysInCourse: " << days[0] << ',';
    cout << days[1] << ',';
    cout << days[2] << '\t';
    cout << "Degree program: " << degreeProgramStrings[(int)degreeProgram] << endl;
}
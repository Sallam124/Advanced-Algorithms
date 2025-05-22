/*********************** Student.h ***********************/

#include "Student.h"
Student::Student() { id = 0 ; firstName=""; middleName="";lastName=""; gpa=0.0;}
Student::Student(long p_id,const string & p_firstName,const string & p_middleName, const string & p_lastName,float p_gpa) 
	{ id = p_id ; firstName=p_firstName; middleName = p_middleName; lastName=p_lastName; gpa=p_gpa;}
void Student::setId(long p_id) { id = p_id;}
void Student::setFirstName(const string & p_firstName) {firstName = p_firstName;}
void Student::setMiddleName(const string & p_middleName) {middleName = p_middleName;}
void Student::setLastName(const string & p_lastName) { lastName = p_lastName;}
void Student::setGPA (float p_gpa) { gpa = p_gpa;}
long Student::getId() { return id;}
string Student::getFirstName() {return firstName;}
string Student::getMiddleName() {return middleName;}
string Student::getLastName() {return lastName;}
float Student::getGPA() {return gpa;}
void Student::print (){ // Defining the Student Method
	cout << "Student ID:" << id << endl;
	cout << "Student First Name:" << firstName << endl;
	cout << "Student Middle Name:" << middleName << endl;
	cout << "Student Last Name:" << lastName << endl;
	cout << "Student GPA:" << gpa << endl;
}
Student::~Student() { cout << "This is the Student Destructor" << endl; print();}

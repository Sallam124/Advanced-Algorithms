/*********************** Student.h ***********************/
#include <iostream>

using namespace std;

struct Student{
	private: // Private Data Members
		long id;		  // Student ID
		string firstName; // Student First Name
		string middleName; // Student Middle Name
		string lastName;  // Student Last Name
		float gpa;	  // Student GPA
	public: // Public Methods
		Student(); // Default Constructor
		Student(long p_id,const string & p_firstName,const string & p_middleName,const string & p_lastName,float p_gpa);// Parameterized Constructor
		// Setters
		void setId(long p_id);
		void setLastName(const string & p_lastName);
		void setMiddleName(const string & p_middleName);
		void setFirstName(const string & p_firstName);
		void setGPA (float p_gpa);
		// Getters
		long getId();
		string getLastName();
		string getMiddleName();
		string getFirstName();
		float getGPA();
		void print ();
		~Student();// Destructor
};

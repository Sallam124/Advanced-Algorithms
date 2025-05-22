#include "StudentNode.h"
#include <iostream>
#include <thread>
#include <fstream>
#include <sstream>


struct StudentList{
	private:
		std::mutex shared_mtx;
		StudentNode * head; // Pointer to the head of the linked list
		StudentNode * tail; // pointer to the tail of the linked list
		void append(StudentNode * p_studentNode); // Append a StudentNode
		void append(Student * p_student);  // Append a Student
	public:
		StudentList();	// Default Constructor
		void operator += (StudentNode * p_studentNode); // Append operator for StudentNode
		void operator += (Student * p_student);	// Append operator for Student
		~StudentList(); // Destructor
};

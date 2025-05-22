#include "Student.h"

struct StudentNode{
	private:
		Student * student;
		StudentNode * next;
	public:
		StudentNode();	// Default Constructor
		StudentNode(Student * p_student); // Parameterized Constructor
		Student * getStudent(); // Return pointer to student
		StudentNode * getNext(); // Return pointer to the next node
		void setStudent(Student * p_student); // Set the internal data member student pointer
		void append(StudentNode * p_studentNode); // Assign the next pointer to a StudentNode
		void append(Student * p_student); // Assign the next pointer to a new StudentNode containing p_student
		~StudentNode(); // Destructor
};

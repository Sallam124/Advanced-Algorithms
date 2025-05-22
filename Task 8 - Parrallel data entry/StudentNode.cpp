#include "StudentNode.h"

StudentNode::StudentNode() {
	next = NULL; // Set next to NULL
	student = NULL; // Set student to NULL
}
StudentNode::StudentNode(Student * p_student) {
	next = NULL; // Set next to NULL
	student = p_student; // set student ptr
}
Student * StudentNode::getStudent() {
	return student; // return the pointer to the student data member
}
StudentNode * StudentNode::getNext() {
	return next; // return the a pointer to the StudentNode pointer to by Next
}
void StudentNode::setStudent(Student * p_student) {
	student = p_student; // Set the student pointer
}
void StudentNode::append(StudentNode * p_studentNode) {
	// Basically inserts the node p_studentNode just right after this object
	p_studentNode->next = next; // Set next of p_studentNode to object student
	next = p_studentNode; // set next to p_studentNode
}
void StudentNode::append(Student * p_student){
	append(new StudentNode(p_student)); // Create a new StudentNode and append it
}
StudentNode::~StudentNode(){
	// destruct student if student is pointing to an object
	cout << "This is the StudentNode Destructor" << endl;
	if ( student != NULL) delete (student);
	//if ( next != NULL ) delete (next);
}

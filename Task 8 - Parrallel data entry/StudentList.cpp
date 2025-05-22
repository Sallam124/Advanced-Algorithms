#include "StudentList.h"

StudentList::StudentList() { // Constructor to set both head and tail to NULL
	head =tail = NULL;
}
void StudentList::append(StudentNode * p_studentNode) {
	shared_mtx.lock();
	if ( head == NULL && tail == NULL ){ // if list is empty assign head and tail to p_studentNode
		head = p_studentNode;
		tail = head;
	} else { // else append p_studentNode next to the tail and advance tail
		tail->append(p_studentNode);
		tail = p_studentNode;
	}
	shared_mtx.unlock();
}
void StudentList::append(Student * p_student) { // create a new StudentNode from p_student and call the above append
	append(new StudentNode(p_student));
}
void StudentList::operator += (StudentNode * p_studentNode) { // An operator wrapper to append
	append(p_studentNode);
}
void StudentList::operator += (Student * p_student) { // An operator wrapper to append
	append(p_student);
}
StudentList::~StudentList(){ // Destructor : delete head which will recursively delete the whole list
	// delete (head);
	StudentNode * cur = head;
	while ( cur != NULL)
	{
		cur = cur->getNext();
		delete(head);
		head = cur;
	}
}

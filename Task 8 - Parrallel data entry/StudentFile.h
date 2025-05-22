#include <iostream>
#include <thread>
#include <fstream>
#include <sstream>
#include "StudentList.h"
using namespace std;


class StudentFile
{
	private:
		std::mutex shared_mtx;
		ifstream student_file; // File stream tro read students from
		StudentList * studentList; // pointer to the Student List to insert students to
	public:
		StudentFile(StudentList * p_studentList,const char * filename); // constructor
		int processFile(); // Processing file
		static int startThread(StudentFile * me); // A static function to start thtread from
		~StudentFile(); // Destructor
};


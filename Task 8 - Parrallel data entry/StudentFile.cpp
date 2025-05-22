#include "StudentFile.h"
StudentFile::StudentFile(StudentList * p_studentList,const char * filename){
	// receieve a file name to open and an already instantiated StudentList to assign to the data member studentList
	student_file.open(filename,ios::in);
	studentList = p_studentList;
}
int StudentFile::processFile(){
	int processed_students = 0; // Counter to count processed students
	if ( !student_file.is_open()) return processed_students; // if file is not opened correctly return
	string line=""; // A string for reading lines from the text file
	string id = ""; // string to store student id
	string fname=""; // string to store student first name
	string mname=""; // string to store student first name
	string lname=""; // string to store student last name
	string gpa=""; // string to store student gpa
	bool read_line = true;
	while(read_line) { // Loop through the file lines
		shared_mtx.lock();
		read_line = (!getline(student_file,line)? false:true);
		if (!read_line){
			shared_mtx.unlock();
			break;
		}
		stringstream iss(line); // Instantiate stringstream with the current line just read
		getline(iss, id, ','); // parse current student id
		getline(iss, fname, ','); // parse current student first name
		getline(iss, mname, ','); // parse current student first name
		getline(iss, lname, ','); // parse current stduent last name
		getline(iss, gpa, ','); // parser current student gpa
		// instantiate a new student object and add it to the student list
		*studentList += new Student(atol(id.c_str()), // Concert id to an int
						fname.c_str(),
						mname.c_str(),
						lname.c_str(),
						atof(gpa.c_str())); // convert gpa to a float
		processed_students++; // increment processed students
		shared_mtx.unlock();

	}

	return processed_students; // return the number of processed students
}
int StudentFile::startThread(StudentFile * me)	{ return me->processFile(); }
StudentFile::~StudentFile() {
	if ( student_file.is_open()) student_file.close(); // clode the file if was opened correctly
}

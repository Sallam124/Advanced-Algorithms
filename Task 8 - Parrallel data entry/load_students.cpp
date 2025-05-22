	#include "StudentFile.h"
#include <future>
#include <chrono>

using namespace std;
using namespace std::chrono;


int main (int argc, char ** argv)
{
	if ( argc !=3 || atoi(argv[2]) < 1 )
	{
		printf ("Usage: ./%s <filename> <threads>\n",argv[0]);
		exit(1);
	}
	int thread_count = atoi(argv[2]);
	StudentList * studentList = new StudentList(); // Instantiate a new StudentList object in the heap
	// Create 4 StudentFile Objects, each one will process a separate file and store in the shared studentList
	StudentFile studentFile (studentList,argv[1]); 
	std::future<int> * results = (std::future<int> *) calloc(thread_count,sizeof(std::future<int>));
	for ( int i = 0 ; i  < thread_count ; i ++ )
		results[i] = std::async(std::launch::async, StudentFile::startThread,&studentFile);

	for ( int i = 0 ; i  < thread_count ; i ++ )
		while (results[i].wait_for(milliseconds(100)) != future_status::ready);

	delete(studentList); // We have to call the constructor as here as we used new to instantiate the object
	int total = 0 ;
	for ( int i = 0 ; i  < thread_count ; i ++ )
	{
		int count = results[i].get();
		cout << "Thread # "<< i << " Processed "<< count << " records" << endl;
		total += count;
	}
	cout << "Total # of records is " << total << endl;
	free(results);
	return 0;
}

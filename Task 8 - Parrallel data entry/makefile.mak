output: load_students.o Student.o StudentFile.o StudentList.o StudentNode.o
		g++ load_students.o Student.o StudentFile.o StudentList.o StudentNode.o -o output

load_students.o: load_students.cpp
		g++ -c load_students.cpp

Student.o: Student.cpp
		g++ -c Student.cpp

StudentFile.o: StudentFile.cpp
		g++ -c StudentFile.cpp

StudentList.o: StudentList.cpp
		g++ -c StudentList.cpp

StudentNode.o: StudentNode.cpp
		g++ -c StudentNode.cpp

clean: 
		rm -f *.o output *~ *gch
val: 
	valgrind ./output $(STRING) $(INT)

run: ./output $(STRING) $(INT)

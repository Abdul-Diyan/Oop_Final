#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<sfml/Graphics.hpp>
#include<SFML/Window.hpp>
using namespace std;
class validator {
public:
	bool check_student(const string& filename, string rollTocheck) {              // check whether the person logging in is enrolled in the institute or not.
		bool flag = 0;
		ifstream inFile(filename);
		if (!inFile) {															// check whether file opens or not
			cout << "Error opening files." << endl;
			return 0;
		}
		string row;
		while (getline(inFile, row)) {															// File opens and read the data 
			istringstream x(row);
			string r;
			if (x >> r)
			{
				if (r == rollTocheck)
				{
					return flag = 1;
					continue;
				}
			}
		}
		inFile.close();
		return flag;

	}
};
class enroll_student {															// Student class to display,add,remove, or update info of the student
protected:
	string firstName;
	string lastName;
	string Roll_no;
	string contact_no;
	string batch_no;
	int age;

public:
	void student_display() {
		ifstream inputFile("student.txt"); // open the input file

		if (inputFile.is_open()) { // check if the file could not be opened
			char ch;
			while (inputFile.get(ch)) {
				cout << ch;
			}
		}
		else {
			cout << "Error: could not open file." << endl;
		}
		cout << endl;
		inputFile.close();
	}
	void addstudent(string fn, string rn, int a, string cn, string bn, string ln) {										// function to add student in the file

		ofstream file("student.txt", ios::app);

		if (!file.is_open()) {
			cout << "Error opening the file!" << endl;

		}
		else {

			file << "" << rn << "            " << bn << "                 " << a << "		" << cn << "			" << fn << " " << ln << endl;


			file.close();

			cout << "Student details added successfully to student.txt!" << endl;

		}

	}
	void remove_student(const string& filename, string rollToRemove) {															// Function to remove student from the file
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			if (x >> r)
			{
				if (r == rollToRemove)
				{
					found = true;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("student.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "student.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToRemove << " removed from the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_student(const string& filename, string rollToUpdate) {															// Function to update info of the student
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			if (x >> r)
			{
				if (r == rollToUpdate)
				{
					found = true;
					string firstname1;
					string lastname1;
					string rollNumber1;
					int age1;
					string contactnumber1;
					string batchNumber1;
					cout << "Enter student's roll number: ";
					cin >> rollNumber1;
					cout << "Enter student's batch number: ";
					cin >> batchNumber1;
					cout << "Enter student's contact number: ";
					cin >> contactnumber1;
					cout << "Enter student's age: ";
					cin >> age1;
					cout << "Enter student's first name: ";
					cin >> firstname1;
					cout << "Enter student's last name: ";
					cin >> lastname1;
					outFile << "" << rollNumber1 << "            " << batchNumber1 << "                 " << age1 << "		" << contactnumber1 << "			" << firstname1 << " " << lastname1 << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("student.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "student.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
};
class take_course : public enroll_student { 															// class to display course,and available courses, withdraw and register courses
protected:
	string course1 = "";
	string course2 = "";
	string course3 = "";
	string course4 = "";
	string course5 = "";
public:
	void available_courses() {															// Function to show the courses offered by the university
		cout << "Following courses are offered in this semester: " << endl << "1- Object Oriented Programming (CS104)." << endl << "2- Entrepreneurship (CS105)." << endl << "3- Linear Algebra (CS106)." << endl << "4- Data Structures (CS107)." << endl << "5- Discrete Structures (CS108)." << endl;
	}
	void course_display() {
		ifstream inputFile("course.txt"); // open the input file
		if (inputFile.is_open()) { // check if the file could not be opened
			char ch;
			while (inputFile.get(ch)) {
				cout << ch;
			}
		}
		else {
			cout << "Error: could not open file." << endl;
		}
		cout << endl;
		inputFile.close();
	}
	void register_course(const string& filename, string rollToUpdate) {															// Function to regiser courses
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			if (x >> r)
			{
				if (r == rollToUpdate)
				{
					found = true;
					string course;
					x >> batch_no >> firstName >> lastName >> course1 >> course2 >> course3 >> course4 >> course5;
					if (course1 != " " || course2 != " " || course3 != " " || course4 != " " || course5 != " ")
					{
						cout << "Following courses are offered in this semester: " << endl << "1- Object Oriented Programming (CS104)." << endl << "2- Entrepreneurship (CS105)." << endl << "3- Linear Algebra (CS106)." << endl << "4- Data Structures (CS107)." << endl << "5- Discrete Structures (CS108)." << endl;
						cout << "Enter code of the course of form (CS1**) offered: ";
						cin >> course;
						if (course == "CS104" || course == "CS105" || course == "CS106" || course == "CS107" || course == "CS108")
						{
							if (course1 != course && course2 != course && course3 != course && course4 != course && course5 != course) {
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course3 << " " << course4 << " " << course5 << " " << course << endl;

							}
							else {
								cout << "Student is already enrolled in this course." << endl;
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course3 << " " << course4 << " " << course5 << endl;

							}
						}
						else {
							cout << "Course entered is not offered by the university." << endl;
							outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course3 << " " << course4 << " " << course5 << endl;
						}
					}
					else
					{
						cout << "Student has Already taken allowed courses." << endl;
						outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course3 << " " << course4 << " " << course5 << endl;

					}

					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("course.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "course.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void withdraw_course(const string& filename, string rollToUpdate) {															// Function to withdraw courses
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			if (x >> r)
			{
				if (r == rollToUpdate)
				{
					found = true;
					string course;
					cout << "Following courses are offered in this semester: " << endl << "1- Object Oriented Programming (CS104)." << endl << "2- Entrepreneurship (CS105)." << endl << "3- Linear Algebra (CS106)." << endl << "4- Data Structures (CS107)." << endl << "5- Discrete Structures (CS108)." << endl << "6- Marketting & Management (CS109)." << endl;
					cout << "Enter code of the course of form (CS1**) offered: ";
					cin >> course;
					x >> batch_no >> firstName >> lastName >> course1 >> course2 >> course3 >> course4 >> course5;
					if (course1 != course || course2 != course || course3 != course || course4 != course || course5 != course) {
						if (course == "CS104" || course == "CS105" || course == "CS106" || course == "CS107" || course == "CS108" || course == "CS109") {
							if (course == course1) {
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course2 << " " << course3 << " " << course4 << " " << course5 << endl;
							}
							else if (course == course2) {
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course3 << " " << course4 << " " << course5 << endl;
							}
							else if (course == course3) {
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course4 << " " << course5 << endl;
							}
							else if (course == course4) {
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course3 << " " << course5 << endl;
							}
							else if (course == course5) {
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course3 << " " << course4 << endl;
							}
							else {
								cout << "Student is not enrolled in the following course." << endl;
								outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << " " << course2 << " " << course3 << " " << course4 << course5 << endl;
							}
						}
						else {
							cout << "Course entered is not offered by the university." << endl;
							outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << course2 << course3 << endl;
						}
					}
					else {
						cout << "Student is not registered in this course." << endl << endl;
						outFile << rollToUpdate << "		" << batch_no << "		  " << firstName << " " << lastName << "		         " << course1 << course2 << course3 << endl;

					}
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("course.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "course.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
};
class marks : public enroll_student {															// Class to display and assign marks.
protected:
	float assignment;
	float quizes;
	float mids;

public:
	void marks_display() {															// Function to display marks of different subjects
		cout << "1- For Oop Marks." << endl << "2- For data structures Marks." << endl << "3- For Linear Algebra Marks." << endl << "4- For Discrete Structures Marks." << endl << "5- For Entrepreneurship Marks." << endl << "Press 1 to 5 to select an option: " << endl;
		int m;
		cin >> m;
		if (m == 1) {																			// Function to display marks of OOP subjects

			cout << endl << endl << "List of Marks of students in Object Oriented Programming." << endl << endl;
			ifstream inputFile("marks_oop.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 2) {																									// Function to display marks of DS subjects

			cout << endl << endl << "List of Marks of students in  Data Structure." << endl << endl;
			ifstream inputFile("marks_ds.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 3) {															// Function to display marks of LA subjects

			cout << endl << endl << "List of Marks of students in Linear Algebra." << endl << endl;
			ifstream inputFile("marks_la.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 4) {																	// Function to display marks of Discrete structures subjects

			cout << endl << endl << "List of Marks of students in Discrete Structures." << endl << endl;
			ifstream inputFile("marks_discrete_s.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 5) {																					// Function to display marks of Entrepreneurship subjects

			cout << endl << endl << "List of Marks of students in Entrepreneurship." << endl << endl;
			ifstream inputFile("marks_entrep.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else {
			cout << "Invalid Number Entered." << endl;
		}

	}
	void update_oopmarks(const string& filename, string rollToUpdate) {																		// Function to display update marks of OOP subjects
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			float q, a, m;
			if (x >> r >> batch_no >> q >> a >> m)
			{
				if (r == rollToUpdate)
				{
					found = true;

					cout << "Enter student's marks in Quizes: ";
					cin >> quizes;
					quizes = quizes + q;
					cout << "Enter student's marks in Assignment: ";
					cin >> assignment;
					assignment += a;
					cout << "Enter student's marks in Mids: ";
					cin >> mids;
					mids += m;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << quizes << "			   " << assignment << "			   	 " << mids << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("marks_oop.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "marks_oop.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_dsmarks(const string& filename, string rollToUpdate) {														// Function to display update marks of DS subjects
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			float q, a, m;
			if (x >> r >> batch_no >> q >> a >> m)
			{
				if (r == rollToUpdate)
				{
					found = true;

					cout << "Enter student's marks in Quizes: ";
					cin >> quizes;
					quizes = quizes + q;
					cout << "Enter student's marks in Assignment: ";
					cin >> assignment;
					assignment += a;
					cout << "Enter student's marks in Mids: ";
					cin >> mids;
					mids += m;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << quizes << "			   " << assignment << "			   	 " << mids << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("marks_ds.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "marks_ds.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_lamarks(const string& filename, string rollToUpdate) {														// Function to display update marks of LA subjects
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			float q, a, m;
			if (x >> r >> batch_no >> q >> a >> m)
			{
				if (r == rollToUpdate)
				{
					found = true;

					cout << "Enter student's marks in Quizes: ";
					cin >> quizes;
					quizes = quizes + q;
					cout << "Enter student's marks in Assignment: ";
					cin >> assignment;
					assignment += a;
					cout << "Enter student's marks in Mids: ";
					cin >> mids;
					mids += m;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << quizes << "			   " << assignment << "			   	 " << mids << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("marks_la.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "marks_la.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_discrete_smarks(const string& filename, string rollToUpdate) {														// Function to display update marks of Discrete Structures subjects
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			float q, a, m;
			if (x >> r >> batch_no >> q >> a >> m)
			{
				if (r == rollToUpdate)
				{
					found = true;

					cout << "Enter student's marks in Quizes: ";
					cin >> quizes;
					quizes = quizes + q;
					cout << "Enter student's marks in Assignment: ";
					cin >> assignment;
					assignment += a;
					cout << "Enter student's marks in Mids: ";
					cin >> mids;
					mids += m;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << quizes << "			   " << assignment << "			   	 " << mids << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("marks_discrete_s.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "marks_discrete_s.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_entrepmarks(const string& filename, string rollToUpdate) {														// Function to display update marks of Entreprenuership subjects
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			float q, a, m;
			if (x >> r >> batch_no >> q >> a >> m)
			{
				if (r == rollToUpdate)
				{
					found = true;

					cout << "Enter student's marks in Quizes: ";
					cin >> quizes;
					quizes = quizes + q;
					cout << "Enter student's marks in Assignment: ";
					cin >> assignment;
					assignment += a;
					cout << "Enter student's marks in Mids: ";
					cin >> mids;
					mids += m;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << quizes << "			   " << assignment << "			   	 " << mids << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("marks_entrep.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "marks_entrep.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
};
class attendance : public enroll_student {														// Class to display and assign attendance to the students
protected:
	int absents;
	int presents;

public:
	void marks_display() {												// Class to display attendance of the students

		cout << "1- For Oop attendance." << endl << "2- For data structures attendance." << endl << "3- For Linear Algebra attendance." << endl << "4- For Discrete Structures attendance." << endl << "5- For Entrepreneurship attendance." << endl << "Press 1 to 5 to select an option: " << endl;
		int m;
		cin >> m;
		if (m == 1) {          												// Class to display attendance of the students in OOP class

			cout << endl << endl << "List of attendance of students in Object Oriented Programming." << endl << endl;
			ifstream inputFile("attendance_oop.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 2) {          												// Class to display attendance of the students in DS class

			cout << endl << endl << "List of attendance of students in  Data Structure." << endl << endl;
			ifstream inputFile("attendance_ds.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 3) {          												// Class to display attendance of the students in LA class

			cout << endl << endl << "List of attendance of students in Linear Algebra." << endl << endl;
			ifstream inputFile("attendance_la.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 4) {          												// Class to display attendance of the students in Discrete Structures class
			cout << endl << endl << "List of attendance of students in Discrete Structures." << endl << endl;
			ifstream inputFile("attendance_discrete_s.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else if (m == 5) {          												// Class to display attendance of the students in Entrepreneurship class
			cout << endl << endl << "List of attendance of students in Entrepreneurship." << endl << endl;
			ifstream inputFile("attendance_entrep.txt"); // open the input file
			if (inputFile.is_open()) { // check if the file could not be opened
				char ch;
				while (inputFile.get(ch)) {
					cout << ch;
				}
			}
			else {
				cout << "Error: could not open file." << endl;
			}
			cout << endl;
			inputFile.close();
		}
		else {
			cout << "Invalid Number Entered." << endl;
		}

	}
	void update_oopattendance(const string& filename, string rollToUpdate) {												// Class to update attendance of the students in oop class
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			int p, o, t;
			if (x >> r >> batch_no >> p >> o >> t)
			{
				if (r == rollToUpdate)
				{
					found = true;
					char at;
					cout << "Press p if student is present or a for absent" << endl;
					cin >> at;
					if (at == 'p') {
						p = p + 1;
					}
					else if (at == 'a') {
						o = o + 1;
					}
					presents = p;
					absents = o;
					t++;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << presents << "			   " << absents << "			   	 " << t << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("attendance_oop.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "attendance_oop.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_dsattendance(const string& filename, string rollToUpdate) {												// Class to display attendance of the students in DS class
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			int p, o, t;
			if (x >> r >> batch_no >> p >> o >> t)
			{
				if (r == rollToUpdate)
				{
					found = true;

					char at;
					cout << "Press p if student is present or a for absent" << endl;
					cin >> at;
					if (at == 'p') {
						p = p + 1;
					}
					else if (at == 'a') {
						o = o + 1;
					}
					presents = p;
					absents = o;
					t++;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << presents << "			   " << absents << "			   	 " << t << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("attendance_ds.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "attendance_ds.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_laattendance(const string& filename, string rollToUpdate) {												// Class to display attendance of the students in LA class
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			int p, o, t;
			if (x >> r >> batch_no >> p >> o >> t)
			{
				if (r == rollToUpdate)
				{
					found = true;
					char at;
					cout << "Press p if student is present or a for absent" << endl;
					cin >> at;
					if (at == 'p') {
						p = p + 1;
					}
					else if (at == 'a') {
						o = o + 1;
					}
					presents = p;
					absents = o;
					t++;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << presents << "			   " << absents << "			   	 " << t << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("attendance_la.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "attendance_la.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_discrete_sattendance(const string& filename, string rollToUpdate) {												// Class to display attendance of the students in Discrete Structures class
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			int p, o, t;
			if (x >> r >> batch_no >> p >> o >> t)
			{
				if (r == rollToUpdate)
				{
					found = true;
					char at;
					cout << "Press p if student is present or a for absent" << endl;
					cin >> at;
					if (at == 'p') {
						p = p + 1;
					}
					else if (at == 'a') {
						o = o + 1;
					}
					presents = p;
					absents = o;
					t++;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << presents << "			   " << absents << "			   	 " << t << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("attendance_discrete_s.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "attendance_discrete_s.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
	void update_entrepattendance(const string& filename, string rollToUpdate) {												// Class to display attendance of the students in Entrepreurship class
		ifstream inFile(filename);
		ofstream outFile("temp.txt");
		enroll_student temp;
		bool found = false;

		if (!inFile || !outFile) {
			cout << "Error opening files." << endl;
			return;
		}
		string row;
		while (getline(inFile, row)) {
			istringstream x(row);
			string r;
			int p, o, t;
			if (x >> r >> batch_no >> p >> o >> t)
			{
				if (r == rollToUpdate)
				{
					found = true;
					char at;
					cout << "Press p if student is present or a for absent" << endl;
					cin >> at;
					if (at == 'p') {
						p = p + 1;
					}
					else if (at == 'a') {
						o = o + 1;
					}
					presents = p;
					absents = o;
					t++;
					outFile << "" << rollToUpdate << "            " << batch_no << "                " << presents << "			   " << absents << "			   	 " << t << endl;
					continue;
				}
			}
			outFile << row << '\n';
		}

		inFile.close();
		outFile.close();

		if (found) {
			if (remove("attendance_entrep.txt") != 0)
			{
				cout << "Error removing original file!\n";
			}
			if (rename("temp.txt", "attendance_entrep.txt") != 0)
			{
				cout << "Error renaming file!\n";
			}
			else
			{
				cout << "Student with roll number " << rollToUpdate << " is updated in the file." << endl;
			}
		}
		else
		{
			cout << "found not" << endl;
			remove("temp.txt");
		}
	}
};
class Systemstudent : public enroll_student, public take_course, public marks, public attendance {												// Class to display thhe main sub menu's of if the person is student
private:
	string main_menu;
	string student_menu;
	string course_menu;
	string marks_menu;
	string attendance_menu;
public:
	Systemstudent() {
		main_menu = "1- Enroll a student \n2- Course Registration \n3- Marks  \n4- Attendance  \n5- Exit \n\n ";
		student_menu = "1- to see already enrolled students \n2-to add a students \n3- to remove a students \n4- to update information of the students \n5- to go back \n ";
		course_menu = "1- Courses Available \n2- Register Courses \n3- to Withdraw a Course \n4- to veiw studnets enrolled in a Course \n5- to to go back \n";
		marks_menu = "1- Display Marks\n2- to to go back \n ";
		attendance_menu = "1- Display attendance\n2- to to go back \n ";
	}
	void displaymain() {																								// Function to display main menu
		cout << main_menu << endl << "Press 1 to 5 to select an option: " << endl;
	}
	void displaystudent() {																								// Function to display sub menu of student
		cout << student_menu << endl << "Press 1 to 5 to select an option: " << endl;
	}
	void displaycourse() {																								// Function to display sub menu of course

		cout << course_menu << endl << "Press 1 to 5 to select an option: " << endl;
	}
	void displaymarks() {																								// Function to display sub menu of Marks

		cout << marks_menu << endl << "Press 1 to 2 to select an option: " << endl;
	}
	void displayattendance() {																								// Function to display sub menu of attendance

		cout << attendance_menu << endl << "Press 1 to 2 to select an option: " << endl;
	}
	int input() {																								// Function to take input from the user

		int input;
		cout << "Enter a number: " << endl;
		cin >> input;
		return input;
	}
	bool valid_input(int num, int max, int min) {															//Function to check whether entered number is valid or not
		return (num <= max && num >= min);
	}
	void student() {																						//Function to call the Student class function
		int n1;
		do {
			displaystudent();
			n1 = input();
			if (valid_input(n1, 5, 1)) {
				if (n1 == 1) {
					cout << endl;
					cout << "Already Enrolled Students are:" << endl;
					enroll_student::student_display();
					cout << endl;
				}
				else if (n1 == 2) {
					cout << endl;
					string firstname;
					string lastname;
					string rollNumber;
					int age;
					string contactnumber;
					string batchNumber;
					cout << "Enter student's batch number: ";
					cin >> batchNumber;
					cout << "Enter student's roll number: ";
					cin >> rollNumber;
					cout << "Enter student's contact number: ";
					cin >> contactnumber;
					cout << "Enter student's age: ";
					cin >> age;
					cout << "Enter student's first name: ";
					cin >> firstname;
					cout << "Enter student's last name: ";
					cin >> lastname;
					enroll_student::addstudent(firstname, rollNumber, age, contactnumber, batchNumber, lastname);
					cout << endl;
				}
				else if (n1 == 3) {
					cout << endl;
					string filename = "student.txt";
					string rollnumber;
					cout << "Enter student's roll number which you want to remove: ";
					cin >> rollnumber;
					enroll_student::remove_student(filename, rollnumber);
					cout << endl;
				}
				else if (n1 == 4) {
					cout << endl;
					string filename = "student.txt";
					string rollnumber1;
					cout << "Enter student's roll number whose information you want to update: ";
					cin >> rollnumber1;
					enroll_student::update_student(filename, rollnumber1);
					cout << endl;
				}
			}
			else if (n1 != 5) {
				cout << "Invalid number entered." << endl;
			}
		} while (n1 != 5);
	}
	void course() {																						//Function to call the course class function

		int n2;
		do {
			displaycourse();
			n2 = input();
			if (valid_input(n2, 5, 1)) {
				if (n2 == 1) {
					cout << endl;
					take_course obj0;
					obj0.available_courses();
					cout << endl;
				}
				else if (n2 == 2) {
					cout << endl;
					string rollNumber;
					string filename = "course.txt";
					cout << "Enter student's roll number whose courses you want to register: ";
					cin >> rollNumber;
					take_course::register_course(filename, rollNumber);
					cout << endl;
				}
				else if (n2 == 3) {
					cout << endl;
					string rollNumber;
					string filename = "course.txt";
					cout << "Enter student's roll number whose courses you want to register: ";
					cin >> rollNumber;
					take_course::withdraw_course(filename, rollNumber);
					cout << endl;
				}
				else if (n2 == 4) {
					cout << endl;
					take_course::course_display();
					cout << endl;
				}
			}
			else if (n2 != 5) {
				cout << "Invalid Number entered." << endl;
			}
		} while (n2 != 5);


	}
	void marks() {																						//Function to call the marks class function

		int n3;
		do {
			displaymarks();
			n3 = input();
			if (n3, 2, 1) {
				if (n3 == 1) {
					cout << endl;
					marks::marks_display();
					cout << endl;
				}
			}
			else if (n3 != 2) {
				cout << "Invalid Input please enter again" << endl;
			}
		} while (n3 != 2);


	}
	void attendance() {																						//Function to call the attendance class function

		int n4;
		do {
			displayattendance();
			n4 = input();
			if (valid_input(n4, 3, 1)) {
				if (n4 == 1) {
					cout << endl;
					attendance::marks_display();
					cout << endl;
				}
			}
			else if (n4 != 2) {
				cout << "Invalid Input Please enter again." << endl;
			}
		} while (n4 != 2);
	}
	void call(int num) {																						//Function to call the function in systemstudent class function

		if (num >= 1 && num <= 4) {
			if (num == 1) {
				student();
			}
			else if (num == 2) {
				course();
			}
			else if (num == 3) {
				marks();
			}
			else if (num == 4) {
				attendance();
			}
		}
		else {
			cout << "Invaid number entered." << endl;
		}

	}
};
class Systemteacher : public enroll_student, public take_course, public marks, public attendance {											// Class to display thhe main sub menu's of if the person is instructor
private:
	string main_menu;
	string student_menu;
	string course_menu;
	string marks_menu;
	string attendance_menu;
public:
	Systemteacher() {
		main_menu = "1- Enroll a student \n2- Course Registration \n3- Marks  \n4- Attendance  \n5- Exit \n\n ";
		student_menu = "1- to see already enrolled students \n2-to add a students \n3- to remove a students \n4- to update information of the students \n5- to go back \n ";
		course_menu = "1- Courses Available \n2- Register Courses \n3- to Withdraw a Course \n4- to veiw studnets enrolled in a Course \n5- to to go back \n";
		marks_menu = "1- Display Marks \n2- Assign Marks \n3- to to go back \n ";
		attendance_menu = "1- Display attendance \n2- Assign attendance \n3- to to go back \n ";
	}
	void displaymain() {																		// Function to display main menu
		cout << main_menu << endl << "Press 1 to 5 to select an option: " << endl;
	}
	void displaystudent() {																		// Function to display sub menu of student
		cout << student_menu << endl << "Press 1 to 5 to select an option: " << endl;
	}
	void displaycourse() {																					// Function to display sub menu of course

		cout << course_menu << endl << "Press 1 to 5 to select an option: " << endl;
	}
	void displaymarks() {																						// Function to display sub menu of Marks
		cout << marks_menu << endl << "Press 1 to 3 to select an option: " << endl;
	}
	void displayattendance() {																							// Function to display sub menu of attendance
		cout << attendance_menu << endl << "Press 1 to 3 to select an option: " << endl;
	}
	int input() {																								// function to take input from the user
		int input;
		cout << "Enter a number: " << endl;
		cin >> input;
		return input;
	}
	bool valid_input(int num, int max, int min) {																//function to check whether the input is valid or not
		return (num <= max && num >= min);
	}
	void student() {																															// Function to call student class functions
		int n1;
		do {
			displaystudent();
			n1 = input();
			if (valid_input(n1, 5, 1)) {
				if (n1 == 1) {
					cout << endl;
					cout << "Already Enrolled Students are:" << endl;
					enroll_student::student_display();
					cout << endl;
				}
				else if (n1 == 2) {
					cout << endl;
					string firstname;
					string lastname;
					string rollNumber;
					int age;
					string contactnumber;
					string batchNumber;
					cout << "Enter student's batch number: ";
					cin >> batchNumber;
					cout << "Enter student's roll number: ";
					cin >> rollNumber;
					cout << "Enter student's contact number: ";
					cin >> contactnumber;
					cout << "Enter student's age: ";
					cin >> age;
					cout << "Enter student's first name: ";
					cin >> firstname;
					cout << "Enter student's last name: ";
					cin >> lastname;
					enroll_student::addstudent(firstname, rollNumber, age, contactnumber, batchNumber, lastname);
					cout << endl;
				}
				else if (n1 == 3) {
					cout << endl;
					string filename = "student.txt";
					string rollnumber;
					cout << "Enter student's roll number which you want to remove: ";
					cin >> rollnumber;
					enroll_student::remove_student(filename, rollnumber);
					cout << endl;
				}
				else if (n1 == 4) {
					cout << endl;
					string filename = "student.txt";
					string rollnumber1;
					cout << "Enter student's roll number whose information you want to update: ";
					cin >> rollnumber1;
					enroll_student::update_student(filename, rollnumber1);
					cout << endl;
				}
			}
			else if (n1 != 5) {
				cout << "Invalid number entered." << endl;
			}
		} while (n1 != 5);
	}
	void course() {																															// Function to call course class functions
		int n2;
		do {
			displaycourse();
			n2 = input();
			if (valid_input(n2, 5, 1)) {
				if (n2 == 1) {
					cout << endl;
					take_course obj0;
					obj0.available_courses();
					cout << endl;
				}
				else if (n2 == 2) {
					cout << endl;
					string rollNumber;
					string filename = "course.txt";
					cout << "Enter student's roll number whose courses you want to register: ";
					cin >> rollNumber;
					take_course::register_course(filename, rollNumber);
					cout << endl;
				}
				else if (n2 == 3) {
					cout << endl;
					string rollNumber;
					string filename = "course.txt";
					cout << "Enter student's roll number whose courses you want to register: ";
					cin >> rollNumber;
					take_course::withdraw_course(filename, rollNumber);
					cout << endl;
				}
				else if (n2 == 4) {
					cout << endl;
					take_course::course_display();
					cout << endl;
				}
			}
			else if (n2 != 5) {
				cout << "Invalid Number entered." << endl;
			}
		} while (n2 != 5);


	}
	void marks() {																															// Function to call marks class functions
		int n3;
		do {
			displaymarks();
			n3 = input();
			if (n3, 3, 1) {
				if (n3 == 1) {
					cout << endl;
					marks::marks_display();
					cout << endl;
				}
				else if (n3 == 2) {
					cout << "1- For updating Oop Marks." << endl << "2- For updating data structures Marks." << endl << "3- For updating Linear Algebra Marks." << endl << "4- For updating Discrete Structures Marks." << endl << "5- For updating Entrepreneurship Marks." << endl << "Press 1 to 5 to select an option: " << endl;
					int m1;
					cin >> m1;
					if (m1 == 1) {
						cout << endl;
						string filename = "marks_oop.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						marks::update_oopmarks(filename, rollnumber1);
						cout << endl;
					}
					else if (m1 == 2) {
						cout << endl;
						string filename = "marks_ds.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						marks::update_dsmarks(filename, rollnumber1);
						cout << endl;
					}
					else if (m1 == 3) {
						cout << endl;
						string filename = "marks_la.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						marks::update_lamarks(filename, rollnumber1);
						cout << endl;
					}
					else if (m1 == 4) {
						cout << endl;
						string filename = "marks_discrete_s.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						marks::update_discrete_smarks(filename, rollnumber1);
						cout << endl;
					}
					else if (m1 == 5) {
						cout << endl;
						string filename = "marks_entrep.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						marks::update_entrepmarks(filename, rollnumber1);
						cout << endl;
					}
				}


			}
			else if (n3 != 3) {
				cout << "Invalid Input please enter again" << endl;
			}
		} while (n3 != 3);


	}
	void attendance() {																															// Function to call attendance class functions
		int n4;
		do {
			displayattendance();
			n4 = input();
			if (valid_input(n4, 3, 1)) {
				if (n4 == 1) {
					cout << endl;
					attendance::marks_display();
					cout << endl;
				}
				else if (n4 == 2) {
					cout << "1- For updating Oop attendance." << endl << "2- For updating data structures attendance." << endl << "3- For updating Linear Algebra attendance." << endl << "4- For updating Discrete Structures attendance." << endl << "5- For updating Entrepreneurship attendance." << endl << "Press 1 to 5 to select an option: " << endl;
					int a1;
					cin >> a1;
					if (a1 == 1) {
						cout << endl;
						string filename = "attendance_oop.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						attendance::update_oopattendance(filename, rollnumber1);
						cout << endl;
					}
					else if (a1 == 2) {
						cout << endl;
						string filename = "attendance_ds.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						attendance::update_dsattendance(filename, rollnumber1);
						cout << endl;
					}
					else if (a1 == 3) {
						cout << endl;
						string filename = "attendance_la.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						attendance::update_laattendance(filename, rollnumber1);
						cout << endl;
					}
					else if (a1 == 4) {
						cout << endl;
						string filename = "attendance_discrete_s.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						attendance::update_discrete_sattendance(filename, rollnumber1);
						cout << endl;
					}
					else if (a1 == 5) {
						cout << endl;
						string filename = "attendance_entrep.txt";
						string rollnumber1;
						cout << "Enter student's roll number whose information you want to update: ";
						cin >> rollnumber1;
						attendance::update_entrepattendance(filename, rollnumber1);
						cout << endl;
					}
				}
			}
			else if (n4 != 3) {
				cout << "Invalid Input Please enter again." << endl;
			}
		} while (n4 != 3);
	}
	void call(int num) {																															// Function to call functions of the systemteacher class functions
		if (num >= 1 && num <= 4) {
			if (num == 1) {
				student();
			}
			else if (num == 2) {
				course();
			}
			else if (num == 3) {
				marks();
			}
			else if (num == 4) {
				attendance();
			}
		}
		else {
			cout << "Invaid number entered." << endl;
		}

	}
};
int main() {

	// SFML CODE


	sf::RectangleShape rect(sf::Vector2f(800, 600));
	rect.setFillColor(sf::Color::White);
	float x, y;
	x = 0;
	y = 150;
	sf::RectangleShape rect1(sf::Vector2f(200, 80));
	rect1.setFillColor(sf::Color::White);
	rect1.setOutlineThickness(5.f);
	rect1.setOutlineColor(sf::Color::Black);
	float x1, y1;
	x1 = 550;
	y1 = 410;
	sf::RectangleShape rect2(sf::Vector2f(195, 197));
	rect2.setFillColor(sf::Color::White);
	rect2.setOutlineThickness(5.f);
	rect2.setOutlineColor(sf::Color::Black);
	float x2, y2;
	x2 = 550;
	y2 = 200;
	sf::Font font;
	font.loadFromFile("Milk_Mango.otf");
	sf::Text text, text1, text2;
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(sf::Color::White);
	text.setPosition(150, 5);
	text.setString("         FAST NUCES\nDIYAN's STUDENT PORTAL");
	//enter;
	text1.setFont(font);
	text1.setCharacterSize(60);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(550, 410);
	text1.setString("Enter");
	//instructions 
	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(10, 200);
	text2.setString("DIRECTIVES:\n\n1. Press Space to continue\n\n2. Enter you roll number\n\n3. make sure you are enrolled\n\n4. Carefully choose your action");
	//sprite
	sf::Sprite sprite;
	sf::Texture spriteTexture;
	if (spriteTexture.loadFromFile("fast.jpg"))
	{
		sprite.setTexture(spriteTexture);
		 //Set position and size for the sprite
		sprite.setPosition(550.f, 200.f);
		sprite.setScale(0.5, 0.5); // Adjust the scale as needed
	}
	else
	{
		cout << "not opened";
	}
	sf::RenderWindow window(sf::VideoMode(800, 600), "diyan portal");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 32)
				{
					window.close();
				}
			}
			else if (sf::Mouse::getPosition(window).x > rect1.getGlobalBounds().left &&
				sf::Mouse::getPosition(window).x < rect1.getGlobalBounds().left +
				rect1.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
				rect1.getGlobalBounds().top && sf::Mouse::getPosition(window).y
				< (rect1.getGlobalBounds().top + rect1.getGlobalBounds().height) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window.close();
			}
		}
		window.clear();
		window.draw(rect);
		window.draw(rect1);
		window.draw(text);
		window.draw(text1);
		window.draw(text2);
		window.draw(rect2);
		window.draw(sprite);
		window.display();
		rect1.setPosition(sf::Vector2f(x1, y1));
		rect.setPosition(sf::Vector2f(x, y));
		rect2.setPosition(sf::Vector2f(x2, y2));
	}

	// SFML CODE

	// Input to check whether the person logging in is a student or teacher
	cout << "1- If you are a Instructor. \n2- If you are a student \nPress 1 to 2 to select an option:  " << endl;
	int check;
	cin >> check;
	if (check >= 1 && check <= 2) {
		if (check == 1) {															
			validator obj1;
			string filename = "instructor.txt";
			string rollnumber1;
			cout << "Instructor's login id / roll number: ";
			cin >> rollnumber1;
			if (obj1.check_student(filename, rollnumber1)) {
				Systemteacher obj;
				int n;
				do {
					obj.displaymain();
					n = obj.input();
					if (obj.valid_input(n, 4, 1)) {
						obj.call(n);
					}
					else if (n != 5) {
						cout << "Invalid Number entered Please Enter again." << endl;
					}
				} while (n != 5);
			}
			else {
				cout << "You are not registered in this flex." << endl;
			}
		}
		else {
			validator obj;
			string filename = "student.txt";
			string rollnumber1;
			cout << "Student's login id / roll number: ";
			cin >> rollnumber1;
			if (obj.check_student(filename, rollnumber1)) {
				Systemstudent obj;
				int n;
				do {
					obj.displaymain();
					n = obj.input();
					if (obj.valid_input(n, 4, 1)) {
						obj.call(n);
					}
					else if (n != 5) {
						cout << "Invalid Number entered Please Enter again." << endl;
					}
				} while (n != 5);
			}
			else {
				cout << "You are not registered in this flex." << endl;
			}
		}
	}
	else {
		cout << "Invalid Number Entered." << endl;
	}
	cout << endl << endl;
	system("pause");
	return 0;
}


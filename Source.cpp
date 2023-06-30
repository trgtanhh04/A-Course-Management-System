#include"Function.h"
//Tao mau sac cho Code :))

void SET_COLOR(int color)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

//Giao dien MENU
void MENU() {


	system("cls");

	SET_COLOR(10);
	cout << "******************************************************************************\n\n";

	SET_COLOR(12);
	cout << "                          A COURSE MANAGEMENT SYSTEM                          \n\n";

	SET_COLOR(10);
	cout << "**********************************   MENU   **********************************\n\n";

}

void menuSystem()
{
	system("cls");

	SET_COLOR(10);
	cout << "******************************************************************************\n\n";

	SET_COLOR(12);
	cout << "                          A COURSE MANAGEMENT SYSTEM                          \n\n";

	SET_COLOR(10);
	cout << "**********************************   MENU   **********************************\n\n";

	SET_COLOR(15);

	cout << "1. VEW YOUR PROFILE INFO." << endl;

	cout << "2. CHANGE THE PASSWORD." << endl;

	cout << "3. A COURSE MANAGEMENT SYSTEM." << endl;

	cout << "0. LOG OUT THE SYSTEM." << endl;

	cout << "\nEnter your choice: ";
}

//Dang nhap vao he thong
bool loginStudent(Student*& S, string username, string password, int& index)
{
	for (int i = 0; i < cntStudent(); i++)
	{
		if (S[i].password == password &&  S[i].firstName + " " + S[i].lastName == username)
		{
			index = i;
			return true;
		}
	}
	return false;
}

bool loginTeacher(Teacher*& T, string username, string password, int& index)
{
	for (int i = 0; i < cntTeacher(); i++)
	{
		if (T[i].password == password && T[i].firstName + " " + T[i].lastName == username)
		{
			index = i;
			return true;
		}
	}
	return false;
}

//View profile
void viewProfileStudent(Student *&S,int &index)
{
	cout << "============================  YOUR PROFILE INFO  ========================" << endl;
	cout << "ID: " << S[index].studentID << endl;
	cout << "Name student: " << S[index].firstName << " " << S[index].lastName << endl;
	cout << "Gender: " << S[index].gender << endl;
	cout << "DOB: " << S[index].dateOfBirth << endl;
	cout << "Social ID: " << S[index].socialID << endl;
	cout << "Pass: " << S[index].password << endl;
	cout << "=========================================================================" << endl;
}

void viewProfileTeacher(Teacher*& T, int& index)
{
	cout << "============================  YOUR PROFILE INFO  ========================" << endl;
	cout << "ID: " << T[index].teacherID << endl;
	cout << "Name teacher: " << T[index].firstName << " " << T[index].lastName << endl;
	cout << "Gender: " << T[index].gender << endl;
	cout << "Social ID: " << T[index].socialID << endl;
	cout << "Pass: " << T[index].password << endl;
	cout << "=========================================================================" << endl;
}

//Thay doi mat khau
void changePassStudent(Student*& S, string newpass, int& index)
{
	SET_COLOR(14);
	system("cls");

	S[index].password = newpass;

	cout << "Change password successfully" << endl;
	system("pause");

	int n = cntStudent();

	ofstream f("Student.csv");
	if (!f)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		f << S[i].no << "," << S[i].studentID << "," << S[i].firstName << ","
			<< S[i].lastName << "," << S[i].dateOfBirth << "," << S[i].gender << ","
			<< S[i].socialID << "," << S[i].className << "," << S[i].password << endl;
	}

	f.close();
}

void changePassTeacher(Teacher*& T, string newpass, int& index)
{
	SET_COLOR(14);
	system("cls");

	T[index].password = newpass;

	cout << "Change password successfully" << endl;
	system("pause");

	int n = cntTeacher();

	ofstream f("Teacher.csv");
	if (!f)
	{
		return;
	}

	for (int i = 0; i < n; i++)
	{
		f << T[i].no << "," << T[i].teacherID << "," << T[i].firstName << ","
			<< T[i].lastName << "," << T[i].dateOfBirth << "," << T[i].gender << ","
			<< T[i].socialID << "," << T[i].className << "," << T[i].password << endl;
	}

	f.close();
}

//Sinh vien mac dinh trong Web
int cntStudent()
{
	int cnt = 0;

	ifstream file("Student.csv");

	if (!file)
	{
		cout << "Can't open file!" << endl;

		system("pause");

		return -1;
	}

	string line;

	while (getline(file, line))
	{
		cnt++;
	}

	file.close();

	return cnt;
}

int cntTeacher()
{
	int cnt = 0;

	ifstream file("Teacher.csv");

	if (!file)
	{
		cout << "Can't open file!" << endl;

		system("pause");

		return -1;
	}

	string line;

	while (getline(file, line))
	{
		cnt++;
	}

	file.close();

	return cnt;
}

void addStudentFromCSV(Student *&S,int &numStudent)
{
	S = new Student[cntStudent()];

	ifstream student("Student.csv");

	string line;

	int cnt = 0;

	while (getline(student, line))
	{
		stringstream ss(line);

		string no,student_id, Fname, Lname, dob, gender, social_id, Class, pass;

		getline(ss, no, ',');

		getline(ss, student_id, ',');

		getline(ss, Fname, ',');

		getline(ss, Lname, ',');

		getline(ss, dob, ',');

		getline(ss, gender, ',');

		getline(ss, social_id, ',');

		getline(ss, Class, ',');

		getline(ss, pass, ',');

		Student student_x = {no, student_id, Fname, Lname, dob ,gender, social_id, Class, pass };

		S[cnt++] = student_x;
	}

	numStudent = cnt;
}

void addTeacherFromCSV(Teacher*&T,int &numTeacher)
{
	T = new Teacher[cntTeacher()];

	ifstream teacher("Teacher.csv");

	string line;

	int cnt = 0;

	while (getline(teacher, line))
	{
		stringstream ss(line);

		string no,teaher_id, Fname, Lname, dob, gender, social_id, Class, pass;

		getline(ss, no, ',');

		getline(ss, teaher_id, ',');

		getline(ss, Fname, ',');

		getline(ss, Lname, ',');

		getline(ss, dob, ',');

		getline(ss, gender, ',');

		getline(ss, social_id, ',');

		getline(ss, Class, ',');

		getline(ss, pass, ',');

		Teacher teacher_x = {no,teaher_id, Fname, Lname, dob, gender, social_id, Class, pass };

		T[cnt++] = teacher_x;
	}

	numTeacher = cnt;
}

//*********************** [ NHIEM VU CUA GIAO VIEN ] ****************************

//------------------ VAO DAU NAM HOC --------------------
void view1StYearStudent(Class *&C)
{
	for (int i = 0; i < C->numClasses; i++)
	{
		SET_COLOR(11);
		cout << "__________________________________________________________________________________________________________________" << endl;
		SET_COLOR(14);
		cout << left << setw(4) << "STT";
		cout << left << setw(30) << C[i].className;
		cout << right << setw(10) << "ID";
		cout << right << setw(20) << "NAME";
		cout << right << setw(10) << "      GENDER";
		cout << right << setw(12) << "DOB";
		cout << right << setw(15) << "SOCIAL-ID" << endl;
		SET_COLOR(2);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		SET_COLOR(11);

		for (int j = 0; j < C[i].numStudents; j++)
		{
			cout << left << setw(4) << j + 1;
			cout << left << setw(30) << " ";
			cout << right << setw(10) << C[i].students[j].studentID;
			cout << right << setw(20) << C[i].students[j].firstName + " " + C[i].students[j].lastName;
			cout << right << setw(10) << C[i].students[j].gender;
			cout << right << setw(15) << C[i].students[j].dateOfBirth;
			cout << right << setw(15) << C[i].students[j].socialID << endl;
		}
	}
}

void view1StYearClass(Class*& C)
{
	SET_COLOR(14);
	cout << left << setw(4) << "STT";
	cout << left << setw(30) << "CLASS NAME";
	cout << right << setw(20) << "NUM OF STUDENT" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	SET_COLOR(11);

	for (int i = 0; i < C->numClasses; i++)
	{
		cout << left << setw(4) << i + 1;
		cout << left << setw(30) << C[i].className;
		cout << right << setw(10) << C[i].numStudents << endl;
		SET_COLOR(14);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		SET_COLOR(11);
	}
}

void menuCreateSchoolYear(int nam)
{
	SET_COLOR(10);

	cout << "******************************************************************************\n\n";

	SET_COLOR(12);
	cout << "                      WELCOME TO THE SCHOOL YEAR " << nam << "                \n\n";

	SET_COLOR(10);
	cout << "******************************************************************************\n\n";

	SET_COLOR(14);

	cout << "1. Create classes." << endl;

	cout << "2. View a list of class." << endl;

	cout << "3. view a list of student in class." << endl;

	cout << "0. Exit!" << endl;

	cout << "\nEnter your choice: ";
}

void createSchoolYear(Class*& C, Student*& S)
{
	int number = cntStudent();

	int schoolYear;

	cout << "School year: ";
	cin >> schoolYear;

	bool check = false;

	while (true)
	{
		menuCreateSchoolYear(schoolYear);

		int choice;
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
		{
			cout << "Number of classes: ";
			int numClasses;
			cin >> numClasses;

			C = new Class[numClasses];

			C->schoolYear = schoolYear;
			C->numClasses = numClasses;

			cin.ignore();

			int i = 0;

			while (i < numClasses)
			{
				string className;

				SET_COLOR(11);
				cout << "Class name: ";
				SET_COLOR(15);

				getline(cin, className);

				C[i].students = new Student[cntStudent()];

				ofstream ClassFile("Student_1st_year.csv",ios::app);

				if (!ClassFile)
				{
					cout << "Please upload the file containing the information of students in class " << className << endl;
					system("pause");
					continue;
				}

				int cnt = 0;

				for (int j = 0; j < number; j++)
				{
					if (S[j].className == className)
					{
						ClassFile << to_string(cnt + 1) << "," << S[j].studentID << "," 
							<< S[j].firstName << "," << S[j].lastName << "," << S[j].dateOfBirth <<"," << S[j].gender
							<< "," << S[j].socialID << "," << S[j].className << "," << S[j].password << endl;

						Student stu = { to_string(cnt + 1), S[j].studentID, S[j].firstName,
							S[j].lastName, S[j].dateOfBirth, S[j].gender,
							S[j].socialID, S[j].className, S[j].password };

						C[i].students[cnt++] = stu;

						check = true;
					}
				}

				if (!check)
				{
					cout << "Invalid class name." << endl;
					continue;
				}
				else
				{
					cout << "The student information has been added to " << className << endl;
					C[i].numStudents = cnt;
					C[i].className = className;
					ClassFile.seekp(0, ios::beg);
				}

				ClassFile.close();
				i++;
			}

			system("pause");
			break;
		}
		case 2:
		{
			if (!check)
			{
				SET_COLOR(9);
				cout << "You need to input student information for the classes before viewing this option." << endl;
			}
			else
			{
				view1StYearClass(C);
			}

			system("pause");
			break;
		}
		case 3:
		{
			if (!check)
			{
				SET_COLOR(9);
				cout << "You need to input student information for the classes before viewing this option." << endl;
			}
			else
			{
				view1StYearStudent(C);
			}

			system("pause");
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Invalid choice. Please try again!" << endl;
			break;
		}

		}
		system("cls");
	}
}

//------------------- VAO DAU HOC KI --------------------

//Them cac khoa hoc vao hoc ki nay
void enterCourses(Course*& courses, int& numcourse)
{
	courses = new Course[numcourse];

	SET_COLOR(2);
	cout << "____________________________________________________________________________________________________" << endl;
	SET_COLOR(14);
	cout << "                                       ENTER COURSES INFORMATION                                     " << endl;
	SET_COLOR(2);
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	SET_COLOR(15);

	cin.ignore();

	for (int i = 0; i < numcourse; i++)
	{
		string courseID, courseName, className, teacherName, DOW, day, session;

		int credit, maxStudent;

		SET_COLOR(11);

		cout << "COURSE " << i + 1 << endl;

		SET_COLOR(15);

		cout << "Course ID: ";

		getline(cin, courseID);

		cout << "Course name: ";

		getline(cin, courseName);

		cout << "Class name: ";

		getline(cin, className);

		cout << "Teacher name: ";

		getline(cin, teacherName);

		cout << "Credit: ";

		cin >> credit;

		cout << "Max student: ";

		cin >> maxStudent;

		cin.ignore();

		cout << "DOW: ";

		getline(cin, DOW);

		cout << "Day: ";

		getline(cin, day);

		cout << "Session: ";

		getline(cin, session);

		Course course = { courseID, courseName, className, teacherName, credit, maxStudent, DOW, day, session };

		courses[i] = course;

		cout << endl;
	}
	system("pause");
}

void addStudentToCourse(Course*& courses, int& numcourse)
{
	system("cls");

	viewCourses(courses, numcourse);

	cout << endl;

	SET_COLOR(2);
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	SET_COLOR(14);
	cout << "                                                         ADD STUDENTS TO THE COURSES                                                         " << endl;
	SET_COLOR(2);
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	SET_COLOR(15);

	bool check;

	for (int i = 0; i < numcourse; i++)
	{
		string courseID;

		check = false;

		SET_COLOR(11);

		cout << "COURSE " << i + 1 << endl;

		SET_COLOR(15);

		cout << "Course ID: ";

		getline(cin, courseID);

		if (courses[i].courseID == courseID)
		{
			courses[i].students = new StudentCourse[cntStudent()];

			ifstream file("Stucourse.csv");

			if (!file)
				return;

			string line;

			int cnt = 0;

			while (getline(file, line))
			{
				string studentID, nameStudent, gender, nameTeacher,
					courseID, nameCourse, nameClass, DOW, day;

				stringstream ss(line);

				getline(ss, studentID, ',');
				getline(ss, nameStudent, ',');
				getline(ss, gender, ',');
				getline(ss, nameTeacher, ',');
				getline(ss, courseID, ',');
				getline(ss, nameCourse, ',');
				getline(ss, nameClass, ',');
				getline(ss, DOW, ',');
				getline(ss, day, ',');

				StudentCourse student = { studentID, nameStudent, gender,
					nameTeacher, courseID, nameCourse, nameClass, DOW, day };

				if (courseID == courses[i].courseID)
				{
					courses[i].students[cnt++] = student;
				}
			}

			courses[i].students->numStudents = cnt;

			cout << "The student has registered for the course and has been added to Course " << endl;

			file.seekg(0, ios::beg);
			file.close();
		}
		else
		{
			cout << "Please double-check the course ID" << endl;

			i--;
		}
	}
}

//Xem danh sach cac khoa hoc
void viewCourses(Course*& courses, int numcourse)
{
	SET_COLOR(14);

	int i = 0;

	cout << left << setw(10) << "ID";
	cout << left << setw(30) << "NAME COURSE";
	cout << left << setw(20) << "NAME CLASS";
	cout << left << setw(20) << "NAME TEACHER";
	cout << left << setw(10) << "CREDITS";
	cout << left << setw(10) << "STUDENTS";
	cout << left << setw(10) << "DATE";
	cout << left << setw(15) << "PERFORMED   ";
	cout << left << setw(12) << "SESSION" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;

	while (i < numcourse)
	{
		SET_COLOR(11);
		cout << left << setw(10) << courses[i].courseID;
		cout << left << setw(30) << courses[i].courseName;
		cout << left << setw(20) << courses[i].className;
		cout << left << setw(20) << courses[i].teacherName;
		cout << left << setw(10) << courses[i].credit;
		cout << left << setw(10) << courses[i].maxStudents;
		cout << left << setw(10) << courses[i].dayOfWeek;
		cout << left << setw(15) << courses[i].day;
		cout << left << setw(12) << courses[i].session << endl;
		SET_COLOR(14);
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
		i++;
	}
}

//Cap nhap khoa hoc
void updateCourses(Course*& courses, int& numcourse)
{
	viewCourses(courses, numcourse);

	cout << "Course ID: ";

	string id;
	cin.ignore();
	getline(cin, id);

	int index = -1; // luu vi tri khoa hoc can cap nhap

	for (int i = 0; i < numcourse; i++)
	{
		if (courses[i].courseID == id)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		while (true)
		{
			system("cls");
			viewCourses(courses, numcourse);

			SET_COLOR(2);
			cout << "____________________________________________________________________________________________________" << endl;
			SET_COLOR(14);
			cout << "                                       UPDATE COURSE INFORMATION                                    " << endl;
			SET_COLOR(2);
			cout << "----------------------------------------------------------------------------------------------------" << endl;
			SET_COLOR(15);

			cout << "1. Course id" << endl;
			cout << "2. Course name" << endl;
			cout << "3. Class name" << endl;
			cout << "4. Teacher name" << endl;
			cout << "5. Number of credits" << endl;
			cout << "6. Number of student" << endl;
			cout << "7. Performed" << endl;
			cout << "8. D/M/Y" << endl;
			cout << "9. Session" << endl;
			cout << "0. Exit!" << endl;
			cout << "\nEnter your choice: ";

			int lc;
			cin >> lc;

			switch (lc)
			{
			case 1:
			{
				string newId;
				cout << "New ID: ";
				cin.ignore();
				getline(cin, newId);
				courses[index].courseID = newId;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 2:
			{
				string newName;
				cout << "New course name: ";
				cin.ignore();
				getline(cin, newName);
				courses[index].courseName = newName;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 3:
			{
				string newClassName;
				cout << "New class name: ";
				cin.ignore();
				getline(cin, newClassName);
				courses[index].className = newClassName;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 4:
			{
				string newTeacherName;
				cout << "New teacher name: ";
				cin.ignore();
				getline(cin, newTeacherName);
				courses[index].teacherName = newTeacherName;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 5:
			{
				int newCredit;
				cout << "New number of credits: ";
				cin >> newCredit;
				courses[index].credit = newCredit;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 6:
			{
				int newNumStudent;
				cout << "New number of students: ";
				cin >> newNumStudent;
				courses[index].maxStudents = newNumStudent;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 7:
			{
				string newDOW;
				cout << "New DOW: ";
				cin.ignore();
				getline(cin, newDOW);
				courses[index].dayOfWeek = newDOW;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 8:
			{
				string newDate;
				cout << "D/M/Y: ";
				cin.ignore();
				getline(cin, newDate);
				courses[index].day = newDate;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 9:
			{
				string newSession;
				cout << "New Session: ";
				cin.ignore();
				getline(cin, newSession);
				courses[index].session = newSession;
				writeFileAfterUpdate(courses, numcourse);
				break;
			}
			case 0:
			{
				return;
			}
			default:
			{
				cout << "Invalid choice. Please try again!" << endl;
				break;
			}
			}

			cout << "Change successfully!" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "Invalid course ID" << endl;
	}
}

//Them 1 hoc sinh vo khoa hoc
void viewACourses(Course*& courses, int& numcourse, string courseID)
{
	SET_COLOR(14);
	cout << left << setw(4) << "STT";
	cout << left << setw(30) << "NAME COURSE";
	cout << right << setw(8) << "ID";
	cout << right << setw(20) << "NAME CLASS";
	cout << right << setw(20) << "NAME";
	cout << right << setw(12) << "        GENDER" << endl;
	SET_COLOR(2);
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < numcourse; i++)
	{
		if (courses[i].courseID == courseID)
		{
			SET_COLOR(14);
			cout << left << setw(4) << i + 1;
			cout << left << setw(30) << courses[i].courseName << endl;
			SET_COLOR(11);

			for (int j = 0; j < courses[i].students->numStudents; j++)
			{
				cout << left << setw(4) << " ";
				cout << left << setw(30) << " ";
				cout << left << setw(20) << courses[i].students[j].studentID;
				cout << left << setw(20) << courses[i].students[j].className;
				cout << left << setw(20) << courses[i].students[j].studentName;
				cout << left << setw(12) << courses[i].students[j].gender << endl;
			}
			SET_COLOR(2);
			cout << "__________________________________________________________________________________________________________________" << endl;
			break;
		}
	}
}

void addAStudentToCourse(Course*& courses, int& numcourse)
{
	viewCourses(courses, numcourse);

	SET_COLOR(15);
	cout << "Course ID: ";
	cin.ignore();
	string courseID;
	getline(cin, courseID);

	int indexCo = -1; // Luu khoa hoc muon them sinh vien moi

	for (int i = 0; i < numcourse; i++)
	{
		if (courses[i].courseID == courseID)
		{
			indexCo = i;
			break;
		}
	}

	if (indexCo != -1)
	{
		system("cls");
		SET_COLOR(2);
		cout << "____________________________________________________________________________________________________" << endl;
		SET_COLOR(14);
		cout << "                                  THE STUDENT INFORMATION TO BE ADDED                              " << endl;
		SET_COLOR(2);
		cout << "----------------------------------------------------------------------------------------------------\n" << endl;
		SET_COLOR(15);

		string studentID, nameStudent, gender, nameClass;

		cout << "ID: ";
		getline(cin, studentID);

		cout << "Name student: ";
		getline(cin, nameStudent);

		cout << "Gender: ";
		getline(cin, gender);

		cout << "Name class: ";
		getline(cin, nameClass);

		StudentCourse student = {
			studentID,
			nameStudent,
			gender,
			courses[indexCo].teacherName,
			courses[indexCo].courseID,
			courses[indexCo].courseName,
			nameClass,
			courses[indexCo].dayOfWeek,
			courses[indexCo].day
		};

		int newNumStudent = courses[indexCo].students->numStudents + 1;

		for (int i = courses[indexCo].students->numStudents; i > 0; i--)
		{
			courses[indexCo].students[i] = courses[indexCo].students[i - 1];
		}

		courses[indexCo].students[0] = student;

		system("cls");

		courses[indexCo].students->numStudents = newNumStudent;

		cout << "The student " << nameStudent << " has been added to the course " << courses[indexCo].courseName << endl << endl;

		writeFileAfterUpdate(courses, numcourse);

		viewACourses(courses, numcourse, courseID);
	}
	else
	{
		cout << "Invalid course ID" << endl;
	}
}

//Xoa 1 hoc sinh khoi khoa hoc
void removeAStudentFromCourse(Course*& courses, int& numcourse)
{
	viewStudentCourse(courses, numcourse);

	SET_COLOR(15);
	cout << "ID: ";
	string id;
	cin.ignore();
	getline(cin, id);

	int indexStu = -1; // Vi tri sinh vien can xoa
	int indexCo = -1; // Vi tri khoa hoc ma sinh vien do hoc

	for (int i = 0; i < numcourse; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (courses[i].students[j].studentID == id)
			{
				indexStu = j;
				indexCo = i;
				break;
			}
		}
		if (indexStu != -1)
		{
			break;
		}
	}
	cout << indexStu << " -> 1 " << endl;
	cout << indexCo << " -> 2 " << endl;

	if (indexStu != -1 && indexCo != -1)
	{
		for (int i = indexStu; i < courses[indexCo].students->numStudents - 1; i++)
		{
			courses[indexCo].students[i] = courses[indexCo].students[i + 1];
		}
		courses[indexCo].students->numStudents--;

		writeFileAfterUpdate(courses, numcourse);

		cout << "The student with ID " << id << " has been removed from course " << courses[indexCo].courseName << endl << endl;

		// -> Xoa cac sinh vien tinh tu sinh vien thu 2 tro di thi duoc con xoa sinh vien dau thi mat het sinh vien trong khoa hoc
	}
	else
	{
		cout << "Student does not exist." << endl;
	}
	viewStudentCourse(courses, numcourse);
}

//Xoa 1 khoa hoc
void removeACourse(Course*& courses, int& numcourse)
{
	viewCourses(courses, numcourse);

	cout << "ID: ";
	cin.ignore();

	string courseID;
	getline(cin, courseID);

	int indexCo = -1;

	for (int i = 0; i < numcourse; i++)
	{
		if (courses[i].courseID == courseID)
		{
			indexCo = i;
			break;
		}
	}

	if (indexCo == -1)
	{
		cout << "Invalid course ID" << endl;
	}
	else
	{
		for (int i = indexCo; i < numcourse - 1; i++)
		{
			courses[i] = courses[i + 1];
		}
		numcourse--;

		courses[indexCo].numCourses--;

		system("cls");

		SET_COLOR(15);

		cout << "The course with code " << courseID << " has been deleted." << endl << endl;

		viewCourses(courses, numcourse);
	}
}

//Xem hoc sinh trong khoa hoc
void viewStudentCourse(Course*& courses, int numcourse)
{
	SET_COLOR(14);
	cout << left << setw(4) << "STT";
	cout << left << setw(30) << "NAME COURSE";
	cout << right << setw(8) << "ID";
	cout << right << setw(20) << "NAME CLASS";
	cout << right << setw(20) << "NAME";
	cout << right << setw(12) << "        GENDER" << endl;
	SET_COLOR(2);
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < numcourse; i++)
	{
		SET_COLOR(14);
		cout << left << setw(4) << i + 1;
		cout << left << setw(30) << courses[i].courseName << endl;
		SET_COLOR(11);

		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			cout << left << setw(4) << " ";
			cout << left << setw(30) << " ";
			cout << left << setw(20) << courses[i].students[j].studentID;
			cout << left << setw(20) << courses[i].students[j].className;
			cout << left << setw(20) << courses[i].students[j].studentName;
			cout << left << setw(12) << courses[i].students[j].gender << endl;
		}
		SET_COLOR(2);
		cout << "__________________________________________________________________________________________________________________" << endl;
	}
}

void writeFileAfterUpdate(Course*& courses, int& numcourse)
{
	ofstream fout("Stucourse.csv");

	if (!fout)
	{
		cout << "Can't update" << endl;
		return;
	}

	for (int i = 0; i < numcourse; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			fout << courses[i].students[j].studentID << ","
				<< courses[i].students[j].studentName << ","
				<< courses[i].students[j].gender << ","
				<< courses[i].teacherName << ","
				<< courses[i].courseID << ","
				<< courses[i].courseName << ","
				<< courses[i].students[j].className << ","
				<< courses[i].dayOfWeek << ","
				<< courses[i].day << endl;
		}
	}

	fout.close();
}

//Phan bo thoi gia tung hoc ki
void timeForSemester(Course*& courses, int& semester, int& year)
{
	while (true)
	{
		SET_COLOR(2);
		cout << "----------------------------------------------------------------------------------------------------" << endl;
		SET_COLOR(14);
		cout << "               INPUT THE NECESSARY DATA FOR THE SEMESTER YOU WANT TO CREATE                         " << endl;
		SET_COLOR(2);
		cout << "----------------------------------------------------------------------------------------------------\n" << endl;
		SET_COLOR(15);

		cout << "The semester 1, 2, or 3: ";
		cin >> semester;
		courses->semester = semester;

		cout << "School year: ";
		cin >> year;
		courses->year = year;

		cout << "Start day: ";
		int sDay;
		cin >> sDay;

		cout << "End day: ";
		int eDay;
		cin >> eDay;

		if (semester == 1)//Bat dau tu thang 1->5
		{
			courses->dateStart = to_string(sDay) + "/" + "1" ;
			courses->dateEnd = to_string(eDay) + "/" + "5"  ;
			break;
		}
		else if (semester == 2)//Bat dau tu thang 6->8
		{
			courses->dateStart = to_string(sDay) + "/" + "6" ;
			courses->dateEnd = to_string(eDay) + "/" + "8" ;
			break;
		}
		else if (semester == 3)//Bat dau tu thang 9->12
		{
			courses->dateStart = to_string(sDay) + "/" + "9" ;
			courses->dateEnd = to_string(eDay) + "/" + "12" ;
			break;
		}
		else
		{
			cout << "The semester does not exist." << endl;
			system("pause");
		}
		system("cls");
	}
}

// TAO MOT HOC KI
void createSemester(Course*& courses, int& numcourse)
{
	bool check = false;

	int semester;

	int year;

	courses = new Course;

	timeForSemester(courses, semester, year);

	system("cls");

	while (true)
	{
		SET_COLOR(10);
		cout << "******************************************************************************\n\n";

		SET_COLOR(12);
		cout << "                     WELCOME TO SEMESTER " << semester << " OF " << year << "-" << year + 1 << "  \n\n";

		SET_COLOR(10);
		cout << "******************************************************************************\n\n";

		SET_COLOR(15);

		cout << "1. Add the courses to the " << semester << " semester." << endl;
		cout << "2. View the list of courses." << endl;
		cout << "3. Update courses information." << endl;
		cout << "4. Add a students to the course." << endl;
		cout << "5. Remove a student from the course." << endl;
		cout << "6. Delete a course." << endl;
		cout << "7. View a list of student in a course." << endl;
		cout << "0. Exit" << endl;
		cout << "\nEnter your choice: ";
		int lc;
		cin >> lc;

		system("cls");

		switch (lc)
		{
		case 1:
		{
			cout << "The number of courses to generate: ";
			cin >> numcourse;

			courses = new Course[numcourse];
			courses->numCourses = numcourse;

			enterCourses(courses, numcourse);
			addStudentToCourse(courses, numcourse);

			check = true;

			system("pause");
			break;
		}
		case 2:
		{
			if (!check)
			{
				cout << "Please enter course information before viewing this option!" << endl;
			}
			else
			{
				viewCourses(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 3:
		{
			if (!check)
			{
				cout << "Please enter course information before viewing this option!" << endl;
			}
			else
			{
				updateCourses(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 4:
		{
			if (!check)
			{
				cout << "Please enter course information before viewing this option!" << endl;
			}
			else
			{
				addAStudentToCourse(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 5:
		{
			if (!check)
			{
				cout << "Please enter course information before viewing this option!" << endl;
			}
			else
			{
				removeAStudentFromCourse(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 6:
		{
			if (!check)
			{
				cout << "Please enter course information before viewing this option!" << endl;
			}
			else
			{
				removeACourse(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 7:
		{
			if (!check)
			{
				cout << "Please enter course information before viewing this option!" << endl;
			}
			else
			{
				viewStudentCourse(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Invalid choice. Please try again." << endl;
			system("pause");
			break;
		}
		}

		system("cls");
	}
}

//------------------- VAO CUOI HOC KI -------------------- 
void menuYearEndReview()
{
	SET_COLOR(10);
	cout << "******************************************************************************\n\n";

	SET_COLOR(12);
	cout << "                              YEAR END REVIEW                                 \n\n";

	SET_COLOR(10);
	cout << "******************************************************************************\n\n";

	SET_COLOR(15);
	cout << "1. Import the scoreboard of a course." << endl;
	cout << "2. View the scoreboard of a course." << endl;
	cout << "3. Update a student's result." << endl;
	cout << "4. View the scoreboard of a class." << endl;
	cout << "0. Exit!" << endl;
	cout << "\nEnter your choice: ";
}

int findCourseIndex(Course*& courses, string courseID, int numcourse)
{
	int index = -1;

	for (int i = 0; i < numcourse; i++)
	{
		if (courses[i].courseID == courseID)
		{
			index = i;
			break;
		}
	}
	return index;
}

//Xuat danh sach sin vien trong khoa hoc sang tep CSV
void exportStudentsToCSV(Course*& courses, int indexCourse)
{
	ofstream coursesFile(courses[indexCourse].courseID + ".csv");

	if (!coursesFile)
	{
		cout << "Can't open file" << endl;
		return;
	}
	for (int i = 0; i < courses[indexCourse].students->numStudents; i++)
	{
		coursesFile << courses[indexCourse].students[i].studentID << ","
			<< courses[indexCourse].students[i].studentName << ","
			<< courses[indexCourse].students[i].gender << ","
			<< courses[indexCourse].students[i].teacherName << ","
			<< courses[indexCourse].students[i].courseID << ","
			<< courses[indexCourse].students[i].courseName << ","
			<< courses[indexCourse].students[i].className << ","
			<< courses[indexCourse].students[i].dayOfWeek << ","
			<< courses[indexCourse].students[i].day << endl;
	}
	coursesFile.close();
}

//Nhap diem sinh vien
void writeFileAfterImportScore(Course*& courses, int numCourse)
{
	ofstream courseScore("Stucourse.csv");

	if (!courseScore)
	{
		cout << "Can't open file" << endl;
		return;
	}

	for (int i = 0; i < numCourse; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			courseScore << courses[i].students[j].studentID << ","
				<< courses[i].students[j].studentName << ","
				<< courses[i].students[j].gender << ","
				<< courses[i].teacherName << ","
				<< courses[i].courseID << ","
				<< courses[i].courseName << ","
				<< courses[i].students[j].className << ","
				<< courses[i].students[j].dayOfWeek << ","
				<< courses[i].students[j].day << ","
				<< courses[i].students[j].midtermGrade << ","
				<< courses[i].students[j].finalGrade << ","
				<< courses[i].students[j].overallGrade << endl;
		}
	}

	courseScore.close();

	SET_COLOR(15);
	cout << "Student information has been updated into the system." << endl;
}

void enterScoreboard(Course*& courses, int numCourses)
{
	int cnt = 0;

	while (cnt < numCourses)
	{
		viewCourses(courses, numCourses);

		cout << "The course with ID " << cnt + 1 << " to enter scores: ";
		cin.ignore();
		string courseID;
		getline(cin, courseID);

		int index = findCourseIndex(courses, courseID, numCourses);

		system("cls");

		if (index != -1)
		{
			SET_COLOR(14);
			cout << left << setw(4) << "STT";
			cout << left << setw(30) << courses[index].courseName;
			cout << right << setw(10) << "Student ID";
			cout << right << setw(20) << "Name student";
			cout << right << setw(20) << "Scoreboard" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			exportStudentsToCSV(courses, index);

			for (int i = 0; i < courses[index].students->numStudents; i++)
			{
				SET_COLOR(11);
				cout << left << setw(4) << i + 1;
				cout << left << setw(30) << " ";
				cout << right << setw(10) << courses[index].students[i].studentID;
				cout << right << setw(20) << courses[index].students[i].studentName;

				cout << right << setw(20) << "Midterm: ";
				cin >> courses[index].students[i].midtermGrade;
				cout << endl;

				cout << right << setw(84) << "Final: ";
				cin >> courses[index].students[i].finalGrade;
				cout << endl;

				courses[index].students[i].overallGrade = (courses[index].students[i].midtermGrade + courses[index].students[i].finalGrade * 2) / 3.0;
				cout << right << setw(84) << "Overall: " << fixed << setprecision(2) << courses[index].students[i].overallGrade << endl;
				SET_COLOR(14);
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			}
			cnt++;
			system("cls");
		}
		else
		{
			cout << "The course does not exist." << endl;
			cnt--;
		}
	}
	writeFileAfterImportScore(courses, numCourses);
}

//Xem diem cua 1 khoa hoc
void viewScoreboardForCourse(Course*& courses, int numCourses)
{
	viewCourses(courses, numCourses);

	cout << "Enter the ID of the course you want to view: ";

	string courseID;
	cin.ignore();
	getline(cin, courseID);

	int index = findCourseIndex(courses, courseID, numCourses);

	system("cls");

	if (index != -1)
	{
		SET_COLOR(14);
		cout << left << setw(4) << "STT";
		cout << left << setw(30) << courses[index].courseName;
		cout << right << setw(10) << "Student ID";
		cout << right << setw(10) << "Class";
		cout << right << setw(20) << "Student Name";
		cout << right << setw(10) << "Midterm";
		cout << right << setw(10) << "Final";
		cout << right << setw(10) << "Overall" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < courses[index].students->numStudents; i++)
		{
			SET_COLOR(11);
			cout << left << setw(4) << i + 1;
			cout << left << setw(30) << " ";
			cout << right << setw(10) << courses[index].students[i].studentID;
			cout << right << setw(10) << courses[index].students[i].className;
			cout << right << setw(20) << courses[index].students[i].studentName;
			cout << right << setw(10) << courses[index].students[i].midtermGrade;
			cout << right << setw(10) << courses[index].students[i].finalGrade;
			cout << right << setw(10) << courses[index].students[i].overallGrade << endl;
			SET_COLOR(14);
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "Invalid course ID" << endl;
	}
}

//Cap nhap ket qua sinh vien
void updateStudentResult(Course*& courses, int numCouse)
{
	viewStudentCourse(courses, numCouse);
	cout << endl;
	SET_COLOR(15);
	string studentID;
	cin.ignore();
	cout << "The student ID to update: ";
	getline(cin, studentID);

	int indexStu = -1;
	int indexCo = -1;

	for (int i = 0; i < numCouse; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (courses[i].students[j].studentID == studentID)
			{
				indexStu = j;
				indexCo = i;
				break;
			}
		}
		if (indexStu != -1)
		{
			break;
		}
	}

	system("cls");

	if (indexStu != -1)
	{
		SET_COLOR(14);
		cout << left << setw(30)<< "Course name";
		cout << right << setw(10) << "Student ID";
		cout << right << setw(20) << "Name student";
		cout << right << setw(20) << "Scoreboard" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;

		SET_COLOR(11);
		cout << left << setw(30) << courses[indexCo].courseName;
		cout << right << setw(10) << courses[indexCo].students[indexStu].studentID;
		cout << right << setw(20) << courses[indexCo].students[indexStu].studentName;

		cout << right << setw(20) << "Midterm: ";
		cin >> courses[indexCo].students[indexStu].midtermGrade;
		cout << endl;

		cout << right << setw(80) << "Final: ";
		cin >> courses[indexCo].students[indexStu].finalGrade;
		cout << endl;

		courses[indexCo].students[indexStu].overallGrade = (courses[indexCo].students[indexStu].midtermGrade + courses[indexCo].students[indexStu].finalGrade * 2) / 3.0;
		cout << right << setw(80) << "Overall: " << courses[indexCo].students[indexStu].overallGrade << endl;
		SET_COLOR(14);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl << endl;
		SET_COLOR(15);
		cout << "The academic results of student " << courses[indexCo].students[indexStu].studentName << " have been updated.\n" << endl;
	}
	else
	{
		cout << "Student does not exist." << endl;
	}
}

//Xem diem so cua 1 lop
void viewScoreboardClass(Course*& courses, int numCourse)
{
	cout << "Name of the class you want to view: ";
	string className;
	cin.ignore();
	getline(cin, className);

	bool foundClass = false;

	for (int i = 0; i < numCourse; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (courses[i].students[j].className == className)
			{
				foundClass = true;
				break;
			}
		}
		if (foundClass)
		{
			break;
		}
	}

	if (foundClass == true)
	{
		SET_COLOR(14);
		cout << left << setw(4) << "STT";
		cout << right << setw(20) << "Student ID";
		cout << right << setw(10) << "Class";
		cout << right << setw(20) << "Student Name";
		cout << right << setw(10) << "Midterm";
		cout << right << setw(10) << "Final";
		cout << right << setw(10) << "Overall" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;

		int stt = 1;

		for (int i = 0; i < numCourse; i++)
		{
			for (int j = 0; j < courses[i].students->numStudents; j++)
			{
				if (courses[i].students[j].className == className)
				{
					SET_COLOR(11);
					cout << left << setw(4) << stt;
					cout << right << setw(20) << courses[i].students[j].studentID;
					cout << right << setw(10) << courses[i].students[j].className;
					cout << right << setw(20) << courses[i].students[j].studentName;
					cout << right << setw(10) << courses[i].students[j].midtermGrade;
					cout << right << setw(10) << courses[i].students[j].finalGrade;
					cout << right << setw(10) << courses[i].students[j].overallGrade << endl;
					SET_COLOR(14);
					cout << "------------------------------------------------------------------------------------------------------------------" << endl;
					stt++;
				}
			}
		}
	}
	else
	{
		cout << "The class does not exit!" << endl;
	}
}

void yearEndReview(Course*& courses, int& numcourse)
{
	bool gradesEntered = false;

	while (true)
	{
		menuYearEndReview();

		int choice;
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
		{
			enterScoreboard(courses, numcourse);
			gradesEntered = true;
			system("pause");
			break;
		}
		case 2:
		{
			if (!gradesEntered)
			{
				cout << "The grades for the course need to be entered before accessing this option." << endl;
			}
			else
			{
				viewScoreboardForCourse(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 3:
		{
			if (!gradesEntered)
			{
				cout << "The grades for the course need to be entered before accessing this option." << endl;
			}
			else
			{
				updateStudentResult(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 4:
		{
			if (!gradesEntered)
			{
				cout << "The grades for the course need to be entered before accessing this option." << endl;
			}
			else
			{
				viewScoreboardClass(courses, numcourse);
			}
			system("pause");
			break;
		}
		case 0:
		{
			return;
		}
		}

		system("cls");
	}
}

//HTH001
//Vi Tich Phan 2B
//22CTT2A
//N.Tien dat
//4
//50
//Monday 
//15/5/2023
//S1
//MATH001
//Dai So Tuyen Tinh
//22CTT2
//Le Van Luyen
//4
//30
//Wednesday
//14/3/2023
//S1
//PHY001
//Vat Ly Dai Cuong
//22CTT6
//Le Tung Lam
//3
//84
//Tuesday 
//12/3/2023
//S1
//BIO001
//Sinh Dai Cuong
//22KDL1
//Luu Hue Phuong
//6
//84
//Monday
//12/6/2023
//S4

//************************ [ NHIEM VU CUA SINH VIEN ] ****************************

bool checkStudentAppeared(Course*& courses, Student*& student, int& indexStu, string courseID, int& numCourses)
{
	for (int i = 0; i < numCourses; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (courses[i].students[j].studentID == student[indexStu].studentID && courses[i].courseID == courseID)
			{
				return false;
			}
		}
	}
	return true;
}

int findStudentCourse(Course*& courses, Student*& student, int*& indexCourses, int &indexStu, int &numCourses)
{
	indexCourses = new int[10];

	int cnt = 0;

	for (int i = 0; i < numCourses; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (courses[i].students[j].studentID == student[indexStu].studentID)
			{
				indexCourses[cnt++] = i;
			}
		}
	}
	return cnt;
}

void registerCourses(Course*& courses, Student*& student, int *&indexCourses ,int indexStu, int numCourses)
{
	viewCourses(courses, numCourses);
	cin.ignore();
	string courseID;
	SET_COLOR(15);
	cout << "Enter the ID of the course to register: ";
	getline(cin, courseID);

	bool checkStudent = checkStudentAppeared(courses, student, indexStu, courseID, numCourses);
	int indexCo = -1;

	for (int i = 0; i < numCourses; i++)
	{
		if (courses[i].courseID == courseID)
		{
			indexCo = i;
			break;
		}
	}

	if (indexCo != -1 && checkStudent==true)
	{
		StudentCourse newStudent =
		{
			student->studentID,
			student->firstName + " " + student->lastName,
			student->gender,
			courses[indexCo].teacherName,
			courses[indexCo].courseID,
			courses[indexCo].courseName,
			student->className,
			courses[indexCo].dayOfWeek,
			courses[indexCo].day
		};

		for (int i = courses[indexCo].students->numStudents; i > 0; i--)
		{
			courses[indexCo].students[i] = courses[indexCo].students[i - 1];
		}

		int newNumStudent = courses[indexCo].students->numStudents + 1;

		courses[indexCo].students[0] = newStudent;

		courses[indexCo].students->numStudents = newNumStudent;

		writeFileAfterUpdate(courses, numCourses);

		SET_COLOR(11);
		cout << "Registration successful." << endl;
	}
	else
	{
		SET_COLOR(11);
		cout <<"The course does not exist or you have already registered for this course." << endl;
	}
}

void viewSchedule(Course*& courses, Student*& student, int*& indexCourses, int& indexStu, int& numCourses)
{
	int cnt = findStudentCourse(courses, student, indexCourses, indexStu, numCourses);

	if (cnt != 0)
	{
		SET_COLOR(14);

		int i = 0;

		cout << left << setw(10) << "ID";
		cout << left << setw(30) << "NAME COURSE";
		cout << left << setw(20) << "NAME CLASS";
		cout << left << setw(20) << "NAME TEACHER";
		cout << left << setw(10) << "CREDITS";
		cout << left << setw(10) << "STUDENTS";
		cout << left << setw(10) << "DATE";
		cout << left << setw(15) << "PERFORMED   ";
		cout << left << setw(12) << "SESSION" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;

		while (i < cnt)
		{
			SET_COLOR(11);
			cout << left << setw(10) << courses[indexCourses[i]].courseID;
			cout << left << setw(30) << courses[indexCourses[i]].courseName;
			cout << left << setw(20) << courses[indexCourses[i]].className;
			cout << left << setw(20) << courses[indexCourses[i]].teacherName;
			cout << left << setw(10) << courses[indexCourses[i]].credit;
			cout << left << setw(10) << courses[indexCourses[i]].maxStudents;
			cout << left << setw(10) << courses[indexCourses[i]].dayOfWeek;
			cout << left << setw(15) << courses[indexCourses[i]].day;
			cout << left << setw(12) << courses[indexCourses[i]].session << endl;
			SET_COLOR(14);
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
			i++;
		}
	}
}

void viewStudentYourCourses(Course*& courses, Student*& student, int*& indexCourses, int indexStu, int numCourses)
{
	int cnt = findStudentCourse(courses, student, indexCourses, indexStu, numCourses);

	SET_COLOR(14);
	cout << left << setw(4) << "STT";
	cout << left << setw(30) << "NAME COURSE";
	cout << right << setw(8) << "ID";
	cout << right << setw(20) << "NAME CLASS";
	cout << right << setw(20) << "NAME";
	cout << right << setw(12) << "        GENDER" << endl;
	SET_COLOR(2);
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < cnt; i++)
	{
		SET_COLOR(14);
		cout << left << setw(4) << i + 1;
		cout << left << setw(30) << courses[indexCourses[i]].courseName << endl;
		SET_COLOR(11);

		for (int j = 0; j < courses[indexCourses[i]].students->numStudents; j++)
		{
			cout << left << setw(4) << " ";
			cout << left << setw(30) << " ";
			cout << left << setw(20) << courses[indexCourses[i]].students[j].studentID;
			cout << left << setw(20) << courses[indexCourses[i]].students[j].className;
			cout << left << setw(20) << courses[indexCourses[i]].students[j].studentName;
			cout << left << setw(12) << courses[indexCourses[i]].students[j].gender << endl;
		}
		SET_COLOR(2);
		cout << "__________________________________________________________________________________________________________________" << endl;
	}
}

void viewStudentYourClass(Course* &courses, Student* &student, int& indexStu, int& numCourses)
{
	// Tao mot mang danh dau sinh vien co mat
	map <string, int> myMap;

	for (int i = 0; i < numCourses; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (courses[i].students[j].className == student[indexStu].className)
			{
				myMap[courses[i].students[j].studentID]++;
			}
		}
	}

	int stt = 1;

	SET_COLOR(14);
	cout << left << setw(4) << "STT";
	cout << left << setw(30) << student[indexStu].className;
	cout << right << setw(8) << "ID";
	cout << right << setw(18) << "NAME";
	cout << right << setw(18) << "GENDER" << endl;
	SET_COLOR(14);
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < numCourses; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (myMap[courses[i].students[j].studentID]>=1)
			{
				SET_COLOR(11);
				cout << left << setw(4) << stt;
				cout << left << setw(30) << " ";
				cout << left << setw(20) << courses[i].students[j].studentID;
				cout << left << setw(18) << courses[i].students[j].studentName;
				cout << left << setw(18) << courses[i].students[j].gender << endl;
				stt++;
				myMap[courses[i].students[j].studentID] = 0;
				SET_COLOR(14);
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
	}
}

void viewYourScorebroad(Course*& courses, Student*& student, int& indexStu, int& numCourses)
{
	SET_COLOR(14);
	cout << left << setw(4) << "STT";
	cout << left << setw(30) << "Courses name";
	cout << right << setw(20) << "Student ID";
	cout << right << setw(20) << "Student Name";
	cout << right << setw(10) << "Midterm";
	cout << right << setw(10) << "Final";
	cout << right << setw(10) << "Overall" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;

	int cnt = 1;

	for (int i = 0; i < numCourses; i++)
	{
		for (int j = 0; j < courses[i].students->numStudents; j++)
		{
			if (courses[i].students[j].studentID == student[indexStu].studentID)
			{
				SET_COLOR(11);
				cout << left << setw(4) << cnt;
				cout << left << setw(30) << courses[i].students[j].courseName;
				cout << right << setw(20) << courses[i].students[j].studentID;
				cout << right << setw(20) << courses[i].students[j].studentName;
				cout << right << setw(10) << courses[i].students[j].midtermGrade;
				cout << right << setw(10) << courses[i].students[j].finalGrade;
				cout << right << setw(10) << courses[i].students[j].overallGrade << endl;
				SET_COLOR(14);
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;
				cnt++;
				break;
			}
		}
	}
}

//--> Dang toi cho cua sinh vien can lam xem lai video ytb va chinh sua, cai ham removeAStudentFromCourses chua Fix duoc =)))
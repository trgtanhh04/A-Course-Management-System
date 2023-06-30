#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<limits>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<sstream>
#include<istream>
#include<stdlib.h>
#include <iterator>
#include <Windows.h>
using namespace std;

//Vao dau nam hoc 
struct Student
{
	string no;
	string studentID;
	string firstName;
	string lastName;
	string dateOfBirth;
	string gender;
	string socialID;
	string className;
	string password;
};

struct Teacher
{
	string no;
	string teacherID;
	string firstName;
	string lastName;
	string dateOfBirth;
	string gender;
	string socialID;
	string className;
	string password;
};


//Lop hoc nam nhat
struct Class
{
	Student* students;
	string className;
	int numStudents;
	int schoolYear;
	int numClasses;
};

//Tao 1 khoa hoc

struct StudentCourse
{
	string studentID;

	string studentName;

	string gender;

	string teacherName;

	string courseID;

	string courseName;

	string className;

	string dayOfWeek;//Thu 2 3 ..

	string day;//Ngay thang nam...

	float midtermGrade;

	float finalGrade;

	float overallGrade;

	int numStudents;

	string dateStart;//Thoi gian bat dau hoc sinh hoc khoa hoc nao do

	string dateEnd;//Thoi gian ket thuc hoc sinh hoc khoa hoc nao do
};

struct Course
{
	string courseID;

	string courseName;

	string className;

	string teacherName;

	int credit;

	int maxStudents;

	string dayOfWeek;//Thu 2 3 4...

	string day;//Ngay thang nam..

	string session;//Tiet 1 2...

	StudentCourse* students;

	int numCourses;

	string dateStart;// Thoi gian hoc ki bat dau

	string dateEnd;// thoi gian hoc ki ket thuc

	int semester;

	int year;
};

//Trang tri cho web

void SET_COLOR(int color);

//Giao dien menu
void MENU();
void menuSystem();

//Dang nhap vao he thong
bool loginStudent(Student*& S, string user, string pass, int& index);

bool loginTeacher(Teacher*& T, string user, string pass, int& index);

void addStudentFromCSV(Student*& S, int& numStudent);

void addTeacherFromCSV(Teacher*& T, int& numTeacher);


//Xem thong tin ca nhan
int cntStudent();

int cntTeacher();

void viewProfileStudent(Student*& S, int& index);

void viewProfileTeacher(Teacher*& T, int& index);

//Thay doi mat khau
void changePassStudent(Student*& S, string newpass, int& index);

void changePassTeacher(Teacher*& T, string newpass, int& index);

//*********************** NHIEM VU CUA GIAO VIEN ***************************

//------------- VAO DAU NAM HOC --------------
void createSchoolYear(Class*& C, Student*& S);

void view1StYearStudent(Class*& C);

void view1StYearClass(Class*& C);

//------------- VAO DAU HOC KI ---------------
void createSemester(Course*& coursesCO, int& numcourse);

void enterCourses(Course*& courses, int& numcourse);

void viewCourses(Course*& courses, int numcourse);

void updateCourses(Course*& courses, int& numcourse);

void addAStudentToCourse(Course*& courses, int& numcourse);

void removeAStudentFromCourse(Course*& courses, int& numcourse);

void removeACourse(Course*& courses, int& numcourse);

void viewStudentCourse(Course*& courses, int numcourse);

void writeFileAfterUpdate(Course*& courses, int& numcourse);

void exportStudentsToCSV(Course*& courses, int indexCourse);

//------------- VAO CUOI HOC KI -----------------
void yearEndReview(Course*& courses, int& numcourse);

void enterScoreboard(Course*& courses, int numCourses);

void updateStudentResult(Course*& courses, int numCouse);

void viewScoreboardClass(Course*& courses, int numCourse);

void viewScoreboardForCourse(Course*& courses, int numCourses);

//*********************** NHIEM VU CUA SINH VIEN ***************************

void registerCourses(Course*& courses, Student*& student, int*& indexCourses, int indexStu, int numCourses);

void viewSchedule(Course*& courses, Student*& student, int*& indexCourses, int& indexStu, int& numCourses);

void viewStudentYourCourses(Course*& courses, Student*& student, int*& indexCourses, int indexStu, int numCourses);

void viewStudentYourClass(Course*& courses, Student*& student, int& indexStu, int& numCourses);

void viewYourScorebroad(Course*& courses, Student*& student, int& indexStu, int& numCourses);
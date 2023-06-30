#include "Function.h"

int main()
{
    Student* students;
    Teacher* teacher;
    Class* classes; // Quan ly lop hoc nam nhat
    Course* courses;

    string newpass;

    int indexTS = 0; // vi tri cua giao vien/ sinh vien
    int numStudent = 0; // So luong sinh vien
    int numTeacher = 0; //so luong giao vien
    int numCourse = 0; // So luong khoa hoc
    int* indexCourse; //mamg cap phat luu vi tri cua khoa hoc ma sinh vien da dang ky

    int lc;
    int choice;

    addStudentFromCSV(students, numStudent);
    addTeacherFromCSV(teacher, numTeacher);

    // Dang nhap vao he thong
    while (true)
    {
        MENU();
        SET_COLOR(15);
        cout << "1. LOGIN." << endl;
        cout << "2. EXIT!" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            cin.ignore();
            cout << "Enter name: ";
            string pass, user;
            getline(cin, user);
            cout << "Enter pass: ";
            getline(cin, pass);

            // GIAO VIEN
            if (loginTeacher(teacher, user, pass, indexTS) == true)
            {
                // Sau khi dang nhap vao he thong co the thuc hien cac lua chon
                cout << "\nHello  "
                    << "\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n\n";
                system("pause");

                while (true)
                {
                    menuSystem();
                    cin >> lc;
                    system("cls");

                    // Xem thong tin ca nhan
                    if (lc == 1) 
                    {
                        viewProfileTeacher(teacher, indexTS);
                        system("pause");
                    }
                    // Thay doi mat khau
                    else if (lc == 2) 
                    {
                        cout << "Enter new pass: ";
                        cin.ignore();
                        getline(cin, newpass);
                        changePassTeacher(teacher, newpass, indexTS);
                    }
                    // Thuc hien cac yeu cau ve quan ly khoa hoc
                    else if (lc == 3) 
                    {
                        // MENU thuc hien cac yeu cau quan ly khoa hoc

                        bool checkSystem = false;

                        while (true)
                        {
                            MENU();
                            SET_COLOR(15);
                            cout << "1. Create a School year." << endl;
                            cout << "2. Create a semester." << endl;
                            cout << "3. Year-end Review." << endl;
                            cout << "0. Exit!" << endl;
                            cout << "\nEnter your choice: ";
                            cin >> lc;
                            system("cls");

                            switch (lc) 
                            {
                            case 1:
                                createSchoolYear(classes, students);
                                system("pause");
                                checkSystem = true;
                                break;
                            case 2:
                                //if (checkSystem == true)
                                //{
                                    createSemester(courses, numCourse);
                                //}
                                //else
                                //{
                                //    cout << "You need to create an academic year before viewing this option." << endl;
                                //}
                                system("pause");
                                break;
                            case 3:
                                //if (checkSystem == true)
                                //{
                                    yearEndReview(courses, numCourse);
                                //}
                                //else
                                //{
                                //    cout << "You need to create an academic year and semester before viewing this option." << endl;
                                //}
                                system("pause");
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                                system("pause");
                                break;
                            }

                            if (lc == 0)
                                break;
                        }
                    }
                    // Dang xuat khoi he thong
                    else if (lc == 0)
                    {
                        break;
                    }
                }

                system("pause");
            }

            // SINH VIEN
            else if (loginStudent(students, user, pass, indexTS) == true)
            {
                cout << "\nHello  "
                    << "\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n\n";
                system("pause");

                while (true)
                {
                    menuSystem();
                    cin >> lc;
                    system("cls");

                    // Xem thong tin ca nhan
                    if (lc == 1) 
                    {
                        viewProfileStudent(students, indexTS);
                        system("pause");
                    }
                    // Thay doi mat khau
                    else if (lc == 2) 
                    {
                        cout << "Enter new pass: ";
                        cin.ignore();
                        getline(cin, newpass);
                        changePassStudent(students, newpass, indexTS);
                    }
                    // Thuc hien cac yeu cau ve quan ly khoa hoc
                    else if (lc == 3)
                    {
                        // MENU thuc hien cac yeu cau quan ly khoa hoc
    
                        while (true) 
                        {
                            MENU();
                            SET_COLOR(15);
                            cout << "1. Register for the course" << endl;
                            cout << "2. View your schedule." << endl;
                            cout << "3. view the list of student in your course" << endl;
                            cout << "4. View the list of students in your class" << endl;
                            cout << "5. View your scoreboard." << endl;
                            cout << "0. Exit!" << endl;
                            cout << "\nEnter your choice: ";
                            cin >> lc;

                            system("cls");

                            switch (lc)
                            {
                            case 1:
                            {
                                registerCourses(courses, students, indexCourse, indexTS, numCourse);
                                system("pause");
                                break;
                            }

                            case 2:
                            {
                                viewSchedule(courses, students, indexCourse, indexTS, numCourse);
                                system("pause");
                                break;
                            }
                            case 3:
                            {
                                viewStudentYourCourses(courses, students, indexCourse, indexTS, numCourse);
                                system("pause");
                                break;
                            }
                            case 4:
                            {
                                viewStudentYourClass(courses, students, indexTS, numCourse);
                                system("pause");
                                break;
                            }
                            case 5:
                            {
                                viewYourScorebroad(courses, students, indexTS, numCourse);
                                system("pause");
                                break;
                            }

                            case 0:
                                break;
                            }
                            system("cls");
                        }
                    }
                    // Dang xuat khoi he thong
                    else if (lc == 4) 
                    {
                        system("cls");
                        SET_COLOR(9);
                        cout << "*************  YOU ARE LOGGED OUT  *************" << endl;
                        break;
                    }

                    system("cls");
                }
            }
            else 
            {
                cout << "\nLOGIN ERROR\nPlease check your username and password\n";
                system("pause");
            }
        }
        else if (choice == 2) 
        {
            system("cls");
            SET_COLOR(9);
            cout << "*********************  THANKS FOR LOGGING IN  *******************" << endl;
            return 0;
        }
    }
    system("cls");
}
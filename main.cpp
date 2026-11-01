
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string ID, Name;

public:
    Person() {
        ID = "";
        Name = "";
    }

    virtual void display() {
        cout << "ID: " << ID << "\nName: " << Name << endl;
    }

    virtual ~Person() {}
};

// Derived Class
class Student : public Person {
private:
    string Course, Subject[5];
    int Semester, Marks[5], count;

public:
    Student() {
        Course = "";
        Semester = 0;
        count = 0;
    }

    void addStudent(string id, string name, string course, int sem) {
        ID = id;
        Name = name;
        Course = course;
        Semester = sem;
        count = 0;
    }

    void addSubject(string sub, int marks) {
        if (count < 5) {
            Subject[count] = sub;
            Marks[count] = marks;
            count++;
        }
    }

    string getID() {
        return ID;
    }

    // Function Overloading
    float percentage() {
        int total = 0;
        for (int i = 0; i < count; i++)
            total += Marks[i];

        return count == 0 ? 0 : (float)total / count;
    }

    string grade(float p) {
        if (p >= 90) return "A+";
        if (p >= 80) return "A";
        if (p >= 70) return "B";
        if (p >= 60) return "C";
        if (p >= 50) return "D";
        return "F";
    }

    string grade() {
        return grade(percentage());
    }

    // Function Overriding
    void display() override {
        Person::display();
        cout << "Course: " << Course
             << "\nSemester: " << Semester << endl;
    }

    void updateDetails(string name, string course, int sem) {
        Name = name;
        Course = course;
        Semester = sem;
    }

    void updateMarks(int index, int marks) {
        if (index >= 0 && index < count)
            Marks[index] = marks;
    }

    void showResult() {
        display();

        cout << "\nSubject\t\tMarks\n";

        for (int i = 0; i < count; i++)
            cout << Subject[i] << "\t\t" << Marks[i] << endl;

        cout << "\nPercentage: " << percentage() << "%";
        cout << "\nGrade: " << grade() << endl;
    }

    // Unique Feature: What-If Grade Calculator
    void whatIf() {
        if (count == 0) {
            cout << "No subjects available!\n";
            return;
        }

        for (int i = 0; i < count; i++)
            cout << i + 1 << ". " << Subject[i]
                 << " (" << Marks[i] << ")\n";

        int choice, newMarks;
        cout << "Select subject: ";
        cin >> choice;

        if (choice < 1 || choice > count) {
            cout << "Invalid choice!\n";
            return;
        }

        cout << "Enter hypothetical marks: ";
        cin >> newMarks;

        if (newMarks < 0 || newMarks > 100) {
            cout << "Invalid marks!\n";
            return;
        }

        float oldP = percentage();
        float newP = oldP + (newMarks - Marks[choice - 1]) / (float)count;

        cout << "\nOriginal Percentage: " << oldP << "%";
        cout << "\nPredicted Percentage: " << newP << "%";
        cout << "\nOriginal Grade: " << grade(oldP);
        cout << "\nPredicted Grade: " << grade(newP);
        cout << "\nChange: " << newP - oldP << "%\n";

        // Original marks are not modified.
    }

    // Friend Function
    friend void compare(Student s1, Student s2);
};

// Compare two students
void compare(Student s1, Student s2) {
    cout << "\n" << s1.Name << ": " << s1.percentage() << "%";
    cout << "\n" << s2.Name << ": " << s2.percentage() << "%\n";

    if (s1.percentage() > s2.percentage())
        cout << s1.Name << " has higher marks.\n";
    else if (s2.percentage() > s1.percentage())
        cout << s2.Name << " has higher marks.\n";
    else
        cout << "Both students have equal marks.\n";
}

// Search student by ID
int searchStudent(Student s[], int n, string id) {
    for (int i = 0; i < n; i++)
        if (s[i].getID() == id)
            return i;

    return -1;
}

// Main Function
int main() {
    Student s[50];
    int n = 0, choice, index;
    string id, name, course;
    int sem, subjects, marks, subChoice;

    do {
        cout << "\n===== STUDENT RESULT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student Details\n";
        cout << "5. Update Marks\n";
        cout << "6. Performance Report\n";
        cout << "7. Delete Student\n";
        cout << "8. What-If Grade Calculator\n";
        cout << "9. Compare Students\n";
        cout << "10. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            if (n == 50) {
                cout << "Student limit reached!\n";
                break;
            }

            cout << "Enter ID: ";
            cin >> id;

            if (searchStudent(s, n, id) != -1) {
                cout << "ID already exists!\n";
                break;
            }

            cout << "Enter Name (one word): ";
            cin >> name;
            cout << "Enter Course (one word): ";
            cin >> course;
            cout << "Enter Semester: ";
            cin >> sem;

            if (sem < 1 || sem > 12) {
                cout << "Invalid semester!\n";
                break;
            }

            s[n].addStudent(id, name, course, sem);

            cout << "Number of Subjects (1-5): ";
            cin >> subjects;

            if (subjects < 1 || subjects > 5) {
                cout << "Invalid subject count!\n";
                break;
            }

            for (int i = 0; i < subjects; i++) {
                string sub;
                cout << "Subject Name: ";
                cin >> sub;
                cout << "Marks: ";
                cin >> marks;

                if (marks < 0 || marks > 100) {
                    cout << "Invalid marks! Student not added.\n";
                    break;
                }

                s[n].addSubject(sub, marks);
            }

            if (s[n].percentage() >= 0 && subjects > 0 &&
                s[n].getID() == id) {
                n++;
                cout << "Student added successfully!\n";
            }
            break;

        case 2:
            for (int i = 0; i < n; i++) {
                Person* ptr = &s[i];
                ptr->display();
                cout << "Percentage: " << s[i].percentage() << "%\n";
                cout << "Grade: " << s[i].grade() << "\n\n";
            }
            if (n == 0) cout << "No records found!\n";
            break;

        case 3:
            cout << "Enter Student ID: ";
            cin >> id;
            index = searchStudent(s, n, id);

            if (index == -1)
                cout << "Student not found!\n";
            else
                s[index].showResult();
            break;

        case 4:
            cout << "Enter Student ID: ";
            cin >> id;
            index = searchStudent(s, n, id);

            if (index != -1) {
                cout << "New Name: ";
                cin >> name;
                cout << "New Course: ";
                cin >> course;
                cout << "New Semester: ";
                cin >> sem;

                if (sem >= 1 && sem <= 12) {
                    s[index].updateDetails(name, course, sem);
                    cout << "Details updated!\n";
                } else {
                    cout << "Invalid semester!\n";
                }
            } else cout << "Student not found!\n";
            break;

        case 5:
            cout << "Enter Student ID: ";
            cin >> id;
            index = searchStudent(s, n, id);

            if (index != -1) {
                cout << "Enter Subject Number: ";
                cin >> subChoice;
                cout << "Enter New Marks: ";
                cin >> marks;

                if (marks >= 0 && marks <= 100) {
                    s[index].updateMarks(subChoice - 1, marks);
                    cout << "Marks updated!\n";
                } else cout << "Invalid marks!\n";
            } else cout << "Student not found!\n";
            break;

        case 6:
            cout << "Enter Student ID: ";
            cin >> id;
            index = searchStudent(s, n, id);

            if (index != -1)
                s[index].showResult();
            else
                cout << "Student not found!\n";
            break;

        case 7:
            cout << "Enter Student ID: ";
            cin >> id;
            index = searchStudent(s, n, id);

            if (index != -1) {
                for (int i = index; i < n - 1; i++)
                    s[i] = s[i + 1];

                n--;
                cout << "Student deleted!\n";
            } else cout << "Student not found!\n";
            break;

        case 8:
            cout << "Enter Student ID: ";
            cin >> id;
            index = searchStudent(s, n, id);

            if (index != -1)
                s[index].whatIf();
            else
                cout << "Student not found!\n";
            break;

        case 9: {
            string id2;
            cout << "Enter First Student ID: ";
            cin >> id;
            cout << "Enter Second Student ID: ";
            cin >> id2;

            int i = searchStudent(s, n, id);
            int j = searchStudent(s, n, id2);

            if (i != -1 && j != -1)
                compare(s[i], s[j]);
            else
                cout << "Student not found!\n";
            break;
        }

        case 10:
            cout << "Thank you for using the system!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 10);

    return 0;
}

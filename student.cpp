#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    char name[50];
    float marks;

    void input() {
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Marks: "; cin >> marks;
    }

    void display() {
        cout << id << " " << name << " " << marks << endl;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.dat", ios::app | ios::binary);
    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();
}

void viewStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);
    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n1.Add 2.View 3.Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
        }
    } while(choice != 3);

    return 0;
}

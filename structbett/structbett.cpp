#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//n1
struct Student {
    string surname;
    string group;
    int grades[5];
};
void otlichniki(Student* students, int size) {
    cout << "otlichniki:\n";
    for (int i = 0; i < size; i++) {
        int excellentCount = 0;
        for (int grade : students[i].grades) if (grade == 5) excellentCount++;
        if (excellentCount >= 4) cout << students[i].surname << " (" << students[i].group << ")\n";
    }
}
void dvoechniki(Student* students, int size) {
    cout << "dvoechniki:\n";
    for (int i = 0; i < size; i++) {
        int poorCount = 0;
        for (int grade : students[i].grades) if (grade <= 3) poorCount++;
        if (poorCount >= 3) cout << students[i].surname << " (" << students[i].group << ")\n";
    }
}
int main() {
    system("chcp 1251>nul");
    int studentSize = 2;
    Student* students = new Student[studentSize]{
        {"Tuiakhov", "G2", {5, 5, 4, 5, 5}},
        {"Bogomolenko", "T1", {1, 1, 1, 1, 1}}
    };
    otlichniki(students, studentSize);
    dvoechniki(students, studentSize);
    delete[] students;
}

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
//n2
struct Man {
    string surname, name;
    int age;
    string birthDate;
};
void surnameSort(vector<Man>& people) {
    sort(people.begin(), people.end(), [](Man a, Man b) { return a.surname < b.surname; });
}
void birthday(vector<Man>& people, string month) {
    cout << "birthdays in " << month << ":\n";
    for (const Man& p : people) {
        if (p.birthDate.find(month) != string::npos)
            cout << p.name << " " << p.surname << " - " << p.birthDate << "\n";
    }
}
void findP(vector<Man>& people, string surname, string name) {
    for (const Man& p : people) {
        if (p.surname == surname && p.name == name)
            cout << p.surname << " " << p.name << " - " << p.age << " years, date: " << p.birthDate << "\n";
    }
}
void addPerson(vector<Man>& people, const Man& person) {
    people.push_back(person);
}
void removePerson(vector<Man>& people, string surname, string name) {
    people.erase(remove_if(people.begin(), people.end(), [&](Man& p) {
        return p.surname == surname && p.name == name;
        }), people.end());
}
void editPerson(vector<Man>& people, string surname, string name, const Man& updatedPerson) {
    for (Man& p : people) {
        if (p.surname == surname && p.name == name) {
            p = updatedPerson;
            return;
        }
    }
}
int main() {
    system("chcp 1251>nul");
    //n1
    int studentSize = 2;
    Student* students = new Student[studentSize]{
        {"Tuiakhov", "G2", {5, 5, 4, 5, 5}},
        {"Bogomolenko", "T1", {1, 1, 1, 1, 1}}
    };
    otlichniki(students, studentSize);
    dvoechniki(students, studentSize);
    delete[] students;
    //n2
    string month;
    vector<Man> people = { {"Tuiakhov", "Kyrylo", 16, "01-10-2008"}, {"Ktoto", "Sasha", 23, "01-01-2002"} };
    surnameSort(people);
    birthday(people, "10");
    findP(people, "Tuiakhov", "Kyrylo");

    addPerson(people, {"Napadailo", "Nazar", 25, "05-06-1999" });
    removePerson(people, "Ktoto", "Sasha");
    editPerson(people, "Tuiakhov", "Kyrylo", { "Bogatiy", "Kyrylo", 16, "01-10-2008" });

    birthday(people, "06");
    findP(people, "Napadailo", "Nazar");

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    public:
    string name;
    Student(string name) : name{name} { cout << "New Student" << endl; }
    ~Student() { cout << "Has died!" << endl; }
    Student(const Student &s) {
        cout << "Student cloned" << endl;
        name = s.name;
    }
};

class Classroom {
    public:
    vector<Student*> students;
};

int main() {
    Student paul{"Paul"};
    {
        Classroom classroom;
        classroom.students.push_back(&paul);
    }
    cout << "end of program" << endl;
}

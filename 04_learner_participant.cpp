#include <iostream>

using namespace std;

class Learner {
protected:
    string course;

public:
    void study() {
        cout << "Attends classes and studies " << course << endl;
    }
};

class Participant {
protected:
    string club;

public:
    void join() {
        cout << "Joins events of " << club << " club" << endl;
    }
};

class Student : public Learner, public Participant {
    string name;

public:
    Student(string n, string c, string cl) {
        name = n;
        course = c;
        club = cl;
    }

    void show() {
        cout << "Student: " << name << endl;
    }
};

int main() {
    string n, c, cl;

    cout << "Enter name, course, club: ";
    cin >> n >> c >> cl;

    Student s(n, c, cl);
    s.show();
    s.study();
    s.join();

    return 0;
}

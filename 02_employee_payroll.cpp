#include <iostream>

using namespace std;

class Employee {
protected:
    string name, address, mail, mobile;
    int id;

public:
    void get() {
        cout << "Name, id, address, mail, mobile: ";
        cin >> name >> id >> address >> mail >> mobile;
    }

    void slip(string post, float bp) {
        float da = 0.95 * bp, hra = 0.10 * bp, pf = 0.12 * bp, other = 0.002 * bp;
        float gross = bp + da + hra + other, net = gross - pf;

        cout << "\n--- Salary Slip ---\n";
        cout << "Post: " << post << "\nName: " << name << "\nId: " << id << endl;
        cout << "Address: " << address << "\nMail: " << mail << "\nMobile: " << mobile << endl;
        cout << "Basic: " << bp << "\nDA: " << da << "\nHRA: " << hra << "\nOther: " << other << endl;
        cout << "PF: " << pf << "\nGross: " << gross << "\nNet: " << net << endl;
    }
};

class Programmer : public Employee {
    float bp;

public:
    void pay() {
        cout << "Basic pay: ";
        cin >> bp;

        slip("Programmer", bp);
    }
};

class TeamLead : public Employee {
    float bp;

public:
    void pay() {
        cout << "Basic pay: ";
        cin >> bp;

        slip("Team Lead", bp);
    }
};

class AsstManager : public Employee {
    float bp;

public:
    void pay() {
        cout << "Basic pay: ";
        cin >> bp;

        slip("Assistant Project Manager", bp);
    }
};

class Manager : public Employee {
    float bp;

public:
    void pay() {
        cout << "Basic pay: ";
        cin >> bp;

        slip("Project Manager", bp);
    }
};

int main() {
    int ch;

    cout << "1.Programmer 2.Team Lead 3.Asst Project Manager 4.Project Manager: ";
    cin >> ch;

    if (ch == 1) {
        Programmer e;
        e.get();
        e.pay();
    } else if (ch == 2) {
        TeamLead e;
        e.get();
        e.pay();
    } else if (ch == 3) {
        AsstManager e;
        e.get();
        e.pay();
    } else {
        Manager e;
        e.get();
        e.pay();
    }

    return 0;
}

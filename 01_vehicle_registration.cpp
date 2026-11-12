#include <iostream>

using namespace std;

class Vehicle {
    string regNo, owner, type;

public:
    Vehicle() {
        regNo = "NA";
        owner = "NA";
        type = "NA";
    }

    Vehicle(string r, string o) {
        regNo = r;
        owner = o;
        type = "Car";
    }

    Vehicle(string r, string o, string t) {
        regNo = r;
        owner = o;
        type = t;
    }

    void show() {
        cout << regNo << " " << owner << " " << type << endl;
    }

    ~Vehicle() {
        cout << "Removed " << regNo << endl;
    }
};

int main() {
    string r, o, t;

    cout << "Enter reg no, owner, type: ";
    cin >> r >> o >> t;

    Vehicle v1, v2("MH12AB1234", "Riya"), v3(r, o, t);
    v1.show();
    v2.show();
    v3.show();

    return 0;
}

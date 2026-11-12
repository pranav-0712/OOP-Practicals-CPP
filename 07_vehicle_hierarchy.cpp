#include <iostream>

using namespace std;

class Vehicle {
protected:
    string brand, model;

public:
    Vehicle(string b, string m) {
        brand = b;
        model = m;
    }
};

class Car : public Vehicle {
protected:
    int seats;
    string fuel;

public:
    Car(string b, string m, int s, string f) : Vehicle(b, m) {
        seats = s;
        fuel = f;
    }
};

class ElectricCar : public Car {
    int battery;
    float chargeTime;

public:
    ElectricCar(string b, string m, int s, int bat, float ct) : Car(b, m, s, "Electric") {
        battery = bat;
        chargeTime = ct;
    }

    void show() {
        cout << "From Vehicle: " << brand << " " << model << endl;
        cout << "From Car: " << seats << " seats, " << fuel << endl;
        cout << "Own: " << battery << " kWh, " << chargeTime << " hours to charge" << endl;
    }
};

int main() {
    ElectricCar e("Tata", "Nexon", 5, 40, 6.5);
    e.show();

    return 0;
}

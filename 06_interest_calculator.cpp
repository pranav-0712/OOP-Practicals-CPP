#include <iostream>

using namespace std;

class InterestCalculator {
public:
    float calculateInterest(float p, float r, float t) {
        return p * r * t / 100;
    }

    float calculateInterest(float p, float r) {
        return p * r * 1 / 100;
    }

    float calculateInterest(float p) {
        return p * 5 * 1 / 100;
    }
};

int main() {
    InterestCalculator ic;
    float p, r, t;

    cout << "Enter principal, rate, time: ";
    cin >> p >> r >> t;
    cout << "Principal, rate, time: " << ic.calculateInterest(p, r, t) << endl;
    cout << "Principal, rate (1 year): " << ic.calculateInterest(p, r) << endl;
    cout << "Principal only (5%, 1 year): " << ic.calculateInterest(p) << endl;

    return 0;
}

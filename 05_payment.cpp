#include <iostream>

using namespace std;

class Payment {
public:
    virtual void pay(float amt) = 0;

    virtual ~Payment() {}
};

class CreditCard : public Payment {
public:
    void pay(float amt) {
        cout << "Paid " << amt << " by Credit Card\n";
    }
};

class UPI : public Payment {
public:
    void pay(float amt) {
        cout << "Paid " << amt << " by UPI\n";
    }
};

class NetBanking : public Payment {
public:
    void pay(float amt) {
        cout << "Paid " << amt << " by Net Banking\n";
    }
};

int main() {
    int ch;
    float amt;

    cout << "1.Credit Card 2.UPI 3.Net Banking: ";
    cin >> ch;
    cout << "Amount: ";
    cin >> amt;

    Payment *p;

    if (ch == 1)
        p = new CreditCard;
    else if (ch == 2)
        p = new UPI;
    else
        p = new NetBanking;

    p->pay(amt);
    delete p;

    return 0;
}

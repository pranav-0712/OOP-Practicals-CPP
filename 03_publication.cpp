#include <iostream>

using namespace std;

class Publication {
protected:
    string title;
    float price;
    int copies, sold;

public:
    Publication(string t, float p, int c) {
        title = t;
        price = p;
        copies = c;
        sold = 0;
    }

    void saleCopy(int n) {
        if (n > copies) {
            cout << "Not enough copies of " << title << endl;
            return;
        }

        copies -= n;
        sold += n;
    }

    float sales() {
        return sold * price;
    }

    virtual void show() = 0;

    virtual ~Publication() {}
};

class Book : public Publication {
    string author;

public:
    Book(string t, float p, int c, string a) : Publication(t, p, c) {
        author = a;
    }

    void orderCopies(int n) {
        copies += n;
    }

    void show() {
        cout << "Book " << title << " by " << author << ": " << copies << " left, sales " << sales() << endl;
    }
};

class Magazine : public Publication {
    int orderQty;

public:
    Magazine(string t, float p, int c, int q) : Publication(t, p, c) {
        orderQty = q;
    }

    void receiveIssue() {
        copies += orderQty;
    }

    void show() {
        cout << "Magazine " << title << ": " << copies << " left, sales " << sales() << endl;
    }
};

int main() {
    Book b("CPP", 500, 10, "Rao");
    Magazine m("TechToday", 100, 5, 20);
    int n;

    cout << "Book copies to order: ";
    cin >> n;

    b.orderCopies(n);
    m.receiveIssue();
    b.saleCopy(4);
    m.saleCopy(10);
    Publication *p[2] = {&b, &m};
    float total = 0;

    for (int i = 0; i < 2; i++) {
        p[i]->show();
        total += p[i]->sales();
    }

    cout << "Total publication sales: " << total << endl;

    return 0;
}

# Object Oriented Programming Practicals (C++)

Seven lab practicals for the Object Oriented Programming part of the OOPCG laboratory. Each program is a single C++ file that compiles on its own with `g++`.

## Practicals

| No. | Practical | Concept | File |
| --- | --- | --- | --- |
| 1 | Vehicle registration system | Parameterized constructor, constructor overloading, destructor | [01_vehicle_registration.cpp](01_vehicle_registration.cpp) |
| 2 | Employee payroll system | Inheritance | [02_employee_payroll.cpp](02_employee_payroll.cpp) |
| 3 | Publication, Book and Magazine | Run-time polymorphism | [03_publication.cpp](03_publication.cpp) |
| 4 | Student as Learner and Participant | Multiple inheritance | [04_learner_participant.cpp](04_learner_participant.cpp) |
| 5 | E-commerce payment methods | Dynamic binding | [05_payment.cpp](05_payment.cpp) |
| 6 | Bank interest calculator | Method overloading (compile-time polymorphism) | [06_interest_calculator.cpp](06_interest_calculator.cpp) |
| 7 | Vehicle, Car and ElectricCar | Multilevel inheritance | [07_vehicle_hierarchy.cpp](07_vehicle_hierarchy.cpp) |

## How to run

Any C++11 compiler works. The programs were compiled with g++ 13.3 using `-std=c++11 -Wall` and give no warnings.

```
g++ 01_vehicle_registration.cpp -o practical
./practical
```

On Windows, run `practical.exe` instead of `./practical`. Give one word for each input value, for example `Pune`, because `cin >>` stops reading at a space.

---

## 1. Vehicle registration system

**Problem statement:** Implement a vehicle registration system. When a vehicle is registered, its registration number, owner name and type are stored using a parameterized constructor. Use constructor overloading and a destructor.

**How it works**

- `Vehicle` has three constructors: no arguments (default values), two arguments (type defaults to Car) and three arguments (everything supplied). This is constructor overloading.
- The compiler chooses the constructor from the number of arguments given when the object is created.
- The destructor `~Vehicle()` runs automatically when each object goes out of scope, in the reverse order of creation.

**Sample run**

```
Enter reg no, owner, type: MH14CD5678 Aman Bike
NA NA NA
MH12AB1234 Riya Car
MH14CD5678 Aman Bike
Removed MH14CD5678
Removed MH12AB1234
Removed NA
```

## 2. Employee payroll system

**Problem statement:** Implement an `Employee` class with name, id, address, mail id and mobile number. Inherit `Programmer`, `Team Lead`, `Assistant Project Manager` and `Project Manager` from it. Add basic pay and calculate DA (95%), HRA (10%), PF (12%) and other allowances (0.2%) to generate a salary slip.

**How it works**

- `Employee` is the base class. It stores the common details and has `slip()`, which calculates and prints the salary slip.
- The four designation classes inherit from `Employee` with `public` inheritance and add only their own basic pay.
- Gross salary = basic + DA + HRA + other allowances. Net salary = gross - PF.

**Sample run**

```
1.Programmer 2.Team Lead 3.Asst Project Manager 4.Project Manager: 2
Name, id, address, mail, mobile: Neha 101 Pune neha@example.com 9876543210
Basic pay: 50000

--- Salary Slip ---
Post: Team Lead
Name: Neha
Id: 101
Address: Pune
Mail: neha@example.com
Mobile: 9876543210
Basic: 50000
DA: 47500
HRA: 5000
Other: 100
PF: 6000
Gross: 102600
Net: 96600
```

## 3. Publication, Book and Magazine

**Problem statement:** Identify what `Publication`, `Book` and `Magazine` have in common. Use title, price and copies as common attributes and `saleCopy()` as a common method. Add author and `orderCopies()` to `Book`, and order quantity and `receiveIssue()` to `Magazine`. Order book copies and display the total publication sales using run-time polymorphism.

**How it works**

- `Publication` is an abstract base class: it has the common data, `saleCopy()`, and a pure virtual function `show()`.
- `Book` and `Magazine` each override `show()`.
- `main()` stores both objects in an array of `Publication*`. Calling `p[i]->show()` runs the `Book` or `Magazine` version depending on the actual object. That decision is made while the program runs.

**Sample run**

```
Book copies to order: 5
Book CPP by Rao: 11 left, sales 2000
Magazine TechToday: 15 left, sales 1000
Total publication sales: 3000
```

## 4. Student as Learner and Participant

**Problem statement:** A student in a university is both a Learner (attends classes, studies) and a Participant (joins clubs, events). Show how multiple inheritance is achieved: `Student` implements both, and a student object shows behaviours from both classes.

**How it works**

- `Learner` provides `study()` and `Participant` provides `join()`.
- `Student` inherits from both: `class Student : public Learner, public Participant`.
- One `Student` object can call `study()` and `join()`.

**Sample run**

```
Enter name, course, club: Amit IT Coding
Student: Amit
Attends classes and studies IT
Joins events of Coding club
```

## 5. E-commerce payment methods

**Problem statement:** Develop an e-commerce application that supports multiple payment methods. The exact method is chosen at run time. Apply dynamic binding to decide which `pay()` executes. Parent class `Payment`; child classes `CreditCard`, `UPI`, `NetBanking`; overridden method `pay()`.

**How it works**

- `Payment` declares `pay()` as a pure virtual function.
- Each child class overrides `pay()`.
- `main()` creates the child object the user selects and stores it in a `Payment*`. The call `p->pay(amt)` is bound to the correct child function at run time (dynamic binding).

**Sample run**

```
1.Credit Card 2.UPI 3.Net Banking: 2
Amount: 499.5
Paid 499.5 by UPI
```

## 6. Bank interest calculator

**Problem statement:** Design a banking application where `InterestCalculator` uses method overloading. Overload `calculateInterest()` to compute simple interest using (principal, rate, time), (principal, rate) with time = 1 year, and (principal) with default rate and time. Illustrate compile-time polymorphism.

**How it works**

- Three functions share the name `calculateInterest` and differ in the number of parameters.
- The compiler selects the function from the arguments in the call, before the program runs.
- Simple interest = principal × rate × time / 100. The default rate is 5% and the default time is 1 year.

**Sample run**

```
Enter principal, rate, time: 10000 8 3
Principal, rate, time: 2400
Principal, rate (1 year): 800
Principal only (5%, 1 year): 500
```

## 7. Vehicle, Car and ElectricCar

**Problem statement:** Use multilevel inheritance to represent a vehicle hierarchy. `Vehicle` holds brand and model. `Car` extends `Vehicle` and adds seating capacity and fuel type. `ElectricCar` extends `Car` and adds battery capacity and charging time. Show that an `ElectricCar` object inherits from both `Vehicle` and `Car`.

**How it works**

- The classes form a chain: `Vehicle` → `Car` → `ElectricCar`.
- Each constructor passes values to its parent through the initializer list, for example `: Car(b, m, s, "Electric")`.
- `ElectricCar::show()` prints members from all three levels.

**Sample run**

```
From Vehicle: Tata Nexon
From Car: 5 seats, Electric
Own: 40 kWh, 6.5 hours to charge
```

---

## Author

Pranav Joshi ([@pranav-0712](https://github.com/pranav-0712))

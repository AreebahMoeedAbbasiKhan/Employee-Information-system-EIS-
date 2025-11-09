#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char* name;
    int id;
    float salary;
    static int count;
    static const string companyName;

public:
    // Constructor using initializer list
    Employee(const char* n = "NoName", int i = 0, float s = 0.0f) : id(i), salary(s) {
        name = nullptr;
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        count++;
    }

    // Deep Copy Constructor
    Employee(const Employee& e) {
        name = nullptr;
        name = new char[strlen(e.name) + 1];
        strcpy_s(name, strlen(e.name) + 1, e.name);
        id = e.id;
        salary = e.salary;
        count++;
    }

    // Destructor
    ~Employee() {
        if (name != nullptr) {
            delete[] name;
            name = nullptr;
        }
        if (count > 0)
            count--;
    }

    // Friend functions 
    friend void setEmployeeData(Employee& e, const char* n, int i, float s);
    friend void displayEmployee(const Employee& e);
    friend void modifySalary(Employee& e, float newSalary);

    // Const member function
    void showData() const {
        cout << "Name: " << name
            << "\nID: " << id
            << "\nSalary: $" << salary
            << "\nCompany: " << companyName << "\n"
            << endl;
    }

    // Static function
    static void showCount() {
        cout << "Total Employees: " << count << endl;
    }

    // Return object 
    Employee duplicateRecord() {
        Employee temp(*this);
        return temp;
    }
};

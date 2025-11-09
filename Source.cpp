#include "Header.h"

int Employee::count = 0;
const string Employee::companyName = "TechSolutions";

// Friend functions
void setEmployeeData(Employee& e, const char* n, int i, float s) {
    if (e.name != nullptr) {
        delete[] e.name;
        e.name = nullptr;
    }
    e.name = new char[strlen(n) + 1];
    strcpy_s(e.name, strlen(n) + 1, n);
    e.id = i;
    e.salary = s;
}

void displayEmployee(const Employee& e) {
    e.showData();
}

void modifySalary(Employee& e, float newSalary) {
    e.salary = newSalary;
}

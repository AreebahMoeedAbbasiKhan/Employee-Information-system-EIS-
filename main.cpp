#include "Header.h"
using namespace std;

// Demonstration of object handling and features
void objectHandlingDemo() {
    cout << "\n--- Object Handling Demonstration ---\n";

    Employee emp1("Ashique", 101, 50000);
    Employee emp2("Basheer", 102, 55000);

    displayEmployee(emp1);
    displayEmployee(emp2);

    // Dynamic object alloc
    Employee* empPtr = new Employee("Cheema", 103, 60000);
    cout << "Dynamic Object:\n";
    displayEmployee(*empPtr);

    // Passing object as argument
    modifySalary(emp1, 52000);
    cout << "After Salary Modification (Employee 1):\n";
    displayEmployee(emp1);


    // Returning object
    Employee empCopy = emp1.duplicateRecord();
    cout << "Duplicate (Deep Copy):\n";
    displayEmployee(empCopy);

    // Modify original to show diff
    modifySalary(emp1, 70000);
    cout << "After modifying original Employee 1 salary:\n";
    cout << "Original:\n";
    displayEmployee(emp1);
    cout << "Copy:\n";
    displayEmployee(empCopy);

    delete empPtr;
}

int main() {
    cout << "=== TechSolutions Employee Management System ===\n";
	cout << "Disclaimer!!!" << endl << "Please follow the instructions carefully while entering data to avoid any runtime errors." << endl;
	cout << "____----____----____----____----____----____----____----____----____----____----____----____----____----____----____----____" << endl;
    int n;
    cout << "Enter number of employees:(numeric digits) ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; i++) {
        char name[50];
        int id;
        float salary;
        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        cout << "Name:(Alphabets) ";
        cin >> name;
        cout << "ID:(numbers) ";
        cin >> id;
        cout << "Salary:(numbers) ";
        cin >> salary;
        setEmployeeData(employees[i], name, id, salary);
    }

    cout << "\n---___ Employee Records ---___\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        displayEmployee(employees[i]);
    }

    Employee::showCount();
    objectHandlingDemo();

    delete[] employees;
    return 0;
}

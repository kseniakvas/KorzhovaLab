#include "Employee.h"

Employee::Employee(int id, string pos, double sal)
    : employeeID(id), position(pos), salary(sal) {
    cout << "Employee has been created" << endl;
}

Employee::Employee() : employeeID(0), position("Unknown"), salary(0.0) {
    cout << "Employee with empty constructor has been created" << endl;
}

Employee::~Employee() {
    cout << "Employee has been destroyed" << endl;
}

void Employee::setEmployeeID(int id) {
    employeeID = id;
}

void Employee::setPosition(string pos) {
    position = pos;
}

void Employee::setSalary(double sal) {
    salary = sal;
}

int Employee::getEmployeeID() {
    return employeeID;
}

string Employee::getPosition() {
    return position;
}

double Employee::getSalary() {
    return salary;
}
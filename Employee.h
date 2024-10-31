#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeID;
protected:
    double salary;
public:
    string position;

    Employee(int id, string pos, double sal);
    Employee();

    ~Employee();

    // Методи
    void setEmployeeID(int id);
    void setPosition(string pos);
    void setSalary(double sal);
    int getEmployeeID();
    string getPosition();
    double getSalary();
    void displayInfo();
};

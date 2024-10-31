#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Employee.h"

using namespace std;

class Manager : public Person, public Employee {
private:
    string department;  
    int managedTeams;  

public:
    Manager(string firstName, string lastName, string gender, int age,
        int employeeID, string position, double salary,
        string dept, int teams);
    Manager();
    ~Manager();

    using Person::getFirstName; 
    using Person::getLastName;
    void setDepartment(string dept);
    void setManagedTeams(int teams);
    string getDepartment();
    int getManagedTeams();
    void displayInfo(); 
};
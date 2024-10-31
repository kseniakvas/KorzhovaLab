#include "Manager.h"

Manager::Manager(string firstName, string lastName, string gender, int age,
    int employeeID, string position, double salary,
    string dept, int teams)
    : Person(firstName, lastName, gender, age), 
    Employee(employeeID, position, salary), 
    department(dept),
    managedTeams(teams) {
    cout << "Manager " << firstName << " " << lastName << " has been created." << endl;
}

Manager::Manager() : managedTeams(0) {
    cout << "Manager with default constructor has been created." << endl;
}

Manager::~Manager() {
    cout << "Manager " << getFirstName() << " " << getLastName() << " has been destroyed." << endl;
}

void Manager::setDepartment(string dept) {
    department = dept;
}

void Manager::setManagedTeams(int teams) {
    managedTeams = teams;
}

string Manager::getDepartment()  {
    return department;
}

int Manager::getManagedTeams()  {
    return managedTeams;
}

void Manager::displayInfo()  {
    cout << "Manager: " << getFirstName() << " " << getLastName() << endl;
    cout << "Department: " << department << endl;
    cout << "Managed Teams: " << managedTeams << endl;
}

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string firstName;
    string lastName;
private: 
    int age;
public:
    string gender;
    Person();
    Person(string firstName, string lastName, string gender, int age);
    ~Person();
    string getFirstName() const;
    void setFirstName(string firstName);
    string getLastName() const;
    void setLastName(string lastName);
    string getGender() const;
    void setGender(string gender);
    int getAge () const;
    void setAge(int age);
    void displayInfo();
};

#include "Person.h"

Person::Person() : firstName(""), lastName(""), gender(""), age(0) {
    cout << "Person with empty constructor has been created" << endl;
}

// Конструктор з параметрами
Person::Person(string firstName, string lastName, string gender, int age)
    : firstName(firstName), lastName(lastName), gender(gender), age(age) {
    cout << "Person has been created" << endl;
}

Person::~Person() {
    cout << "Person has been destroyed" << endl;
}

string Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(string firstName) {
    this->firstName = firstName;
}

string Person::getLastName() const {
    return lastName;
}

void Person::setLastName(string lastName) {
    this->lastName = lastName;
}

string Person::getGender() const {
    return gender;
}

void Person::setGender(string gender) {
    this->gender = gender;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    if (age >= 0) {
        this->age = age;
    }
    else {
        cout << "Age cannot be negative." << endl;
    }
}

void Person::displayInfo() {
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
}
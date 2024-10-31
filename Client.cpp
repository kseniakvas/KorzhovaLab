#include "Client.h"

Client::Client(string first, string last, string gender, int age, double bal, int pass)
    : Person(first, last, gender, age),
    clientID(100 + rand() % 100), 
    balance(bal),
    passportNumber(pass) {
    cout << "Client has been created with full parameters" << endl;
}

Client::Client(string first, string last, string gender, int age)
    : Person(first, last, gender, age), 
    clientID(100 + rand() % 100), 
    balance(0),
    passportNumber(0) {
    cout << "Client with not full parameters has been created" << endl;
}

Client::Client()
    : Person("Unknown", "Unknown", "Unkown", 0),
    clientID(100 + rand() % 100), 
    balance(0),
    passportNumber(0) {
    cout << "Client with empty constructor has been created" << endl;
}

Client::Client(const Client& cl)
    : Person(cl.getFirstName(), cl.getLastName(), cl.gender, cl.getAge()),
    clientID(cl.clientID),
    balance(cl.balance),
    passportNumber(cl.passportNumber),
    companyVisa(cl.companyVisa),
    insurance(cl.insurance),
    TS(cl.TS) {
    cout << "Client has been copied" << endl;
}

Client::~Client() {
    cout << "Client has been destructed" << endl; 
}

void Client::printClient() {
    Client::Person::displayInfo();
}

int Client::getClientID() const {
    return clientID;
}

string Client::getFirstName() const {
    return firstName;
}

string Client::getLastName() const  {
    return lastName;
}

double Client::getBalance() const {
    return balance;
}

int Client::getPassportNumber() const {
    return passportNumber;
}

bool Client::getCompanyVisa() const {
    return companyVisa;
}

bool Client::getInsurance() const {
    return insurance;
}

void Client::setFirstName(string first) {
    firstName = first;
}

void Client::setLastName(string last) {
    lastName = last;
}

void Client::setBalance(double bal) {
    balance = bal;
}

void Client::setPassportNumber(int passport) {
    passportNumber = passport;
}

void Client::setCompanyVisa(bool visa) {
    companyVisa = visa;
}

void Client::setInsurance(bool insur) {
    insurance = insur;
}

void Client::setTouristSpecifications(string country, string city, string date) {
    TS.country = country;
    TS.city = city;
    TS.date = date;
}

string Client::getCountry() {
    return TS.country;
}

string Client::getCity() {
    return TS.city;
}

string Client::getDate() {
    return TS.date;
}
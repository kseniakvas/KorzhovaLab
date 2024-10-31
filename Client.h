#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

struct TouristSpecifications {
	string country;
	string city;
	string date;
};

class Client : private Person 
{
private:
	int clientID;
	double balance = 0;
	int passportNumber;

public: 
	TouristSpecifications TS;
	bool companyVisa = false;
	bool insurance = false;


	Client(string first, string last, string gender, int age, double balance, int pass);
	Client(string first, string last, string gender, int age);
	Client();
	Client(const Client& cl);
	~Client();

	using Person::getAge;
	void printClient();

	/* GetSet */
	int getClientID() const;
	string getLastName() const;
	string getFirstName() const;
	double getBalance() const;
	int getPassportNumber() const;
	bool getCompanyVisa() const;
	bool getInsurance() const;

	void setFirstName(string first);
	void setLastName(string last);
	void setBalance(double bal);
	void setPassportNumber(int passport);
	void setCompanyVisa(bool visa);
	void setInsurance(bool insur);
	void setTouristSpecifications(string country, string city, string date);
	string getCountry();
	string getCity();
	string getDate();
};


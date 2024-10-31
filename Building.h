#pragma once
#include <iostream>
#include <string>

using namespace std;

class Building {
private:
    string address;
    int numberOfFloors;
    double area; 

public:
    Building(string addr, int floors, double areaSize);
    Building();
    ~Building();

    string getAddress() const;
    int getNumberOfFloors() const;
    double getArea() const;

    void setAddress(string addr);
    void setNumberOfFloors(int floors);
    void setArea(double areaSize);

    void displayInfo() const;
};
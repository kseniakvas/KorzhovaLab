#include "Building.h"

Building::Building(string addr, int floors, double areaSize)
    : address(addr), numberOfFloors(floors), area(areaSize) {
    cout << "Building has been created" << endl;
}

Building::Building() : address("Unknown"), numberOfFloors(1), area(0.0) {
    cout << "Building with empty constructor has been created" << endl;
}

Building::~Building() {
    cout << "Building has been destroyed" << endl;
}

string Building::getAddress() const {
    return address;
}

int Building::getNumberOfFloors() const {
    return numberOfFloors;
}

double Building::getArea() const {
    return area;
}

void Building::setAddress(string addr) {
    address = addr;
}

void Building::setNumberOfFloors(int floors) {
    numberOfFloors = floors;
}

void Building::setArea(double areaSize) {
    area = areaSize;
}

void Building::displayInfo() const {
    cout << "Building Address: " << address << endl;
    cout << "Number of Floors: " << numberOfFloors << endl;
    cout << "Area: " << area << " sq.m." << endl;
}
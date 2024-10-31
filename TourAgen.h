#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Client.h"
#include "Manager.h"
#include "Building.h"
#include <vector>

using namespace std;

class TourAgen : private Building
{
private:
    string agencyName;
    string email;
    string phoneNumber;
    const int something = 2;

public:
    class Tours {
    public:
        string country; 
        string city;
        string date;
        double cost;
        int size;
        bool visa;

        Tours(const string& cnt, const string& cty, const string& dt, double c, int sz, bool v);
        Tours();
    };

    static int currentClients;
    vector<Client> clientsList;
    vector<Tours> toursOffered;
    vector<Manager> managers;

    TourAgen(string agnm, string dog, string num, int something, string addr, int floors, double areaSize);
    TourAgen(const TourAgen& touragen, int something);
    TourAgen();
    ~TourAgen();

    static void printCountClients();
    void buyTickets(const Manager &man);
    void registerManager(const Manager& man);
    void registerClient(const Client& cli);
    void registerClient();
    void printTours();
    void FillTours();
    void WriteToFile(vector<Tours>& toursOffered);
    vector<Tours> ReadFromFile();

    /* GetSet */
};

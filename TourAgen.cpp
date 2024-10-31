#define _CRT_SECURE_NO_WARNINGS
#include "TourAgen.h"

int TourAgen::currentClients = 0;

TourAgen::Tours::Tours(const string& cnt, const string& cty, const string& dt, double c, int sz, bool v)
    : country(cnt), city(cty), date(dt), cost(c), size(sz), visa(v) {}

TourAgen::Tours::Tours() {}

TourAgen::TourAgen(string agnm, string dog, string num, int something, string addr, int floors, double areaSize)
    : Building(addr, floors, areaSize), agencyName(agnm), email(dog), phoneNumber(num)  {
    toursOffered = ReadFromFile();
    cout << "Tour Agency has been created" << endl;
}

TourAgen::TourAgen(const TourAgen& other, int smth) : Building(other.getAddress(), other.getNumberOfFloors(), other.getArea()), agencyName(other.agencyName), email(other.email),
    phoneNumber(other.phoneNumber), clientsList(other.clientsList), toursOffered(other.toursOffered), something(smth) {
    cout << "Tour Agency has been created" << endl;
}

TourAgen::TourAgen() : something(0) {
    cout << "Tour Agency has been created" << endl;
}

TourAgen::~TourAgen() {
    cout << "Tour Agency has been destructed" << endl;
}

void TourAgen::registerClient(const Client& cli) {
    clientsList.push_back(cli);
    cout << "Client " << cli.getFirstName() << " " << cli.getLastName() << " was registered in the system." << endl << "\n";
    currentClients++;
}

void TourAgen::registerManager(const Manager& man) {
    managers.push_back(man);
    cout << "Manager " << man.getFirstName() << " " << man.getLastName() << " was registered in the system." << endl << "\n";
}

void TourAgen::registerClient() {
    string firstName, lastName;
    double balance;
    int phoneNumber;
    cout << "Enter first name, lastname, balance and phone number: ";
    cin >> firstName >> lastName >> balance >> phoneNumber;
    Client client(firstName, lastName, "Unknown", 50, balance, phoneNumber);
    clientsList.push_back(client);
    cout << "Client " << firstName << " " << lastName << " was registred in the system." << endl ;
    currentClients++;
}

void TourAgen::buyTickets(const Manager& man) {
    for (auto& client : clientsList)
    {
        int whatTicket = rand() % toursOffered.size();
        cout << "Client " << client.getFirstName() << " want to take tour to " << toursOffered[whatTicket].country << ", " << toursOffered[whatTicket].city << endl;
        if (client.getBalance() < toursOffered[whatTicket].cost) {
            cout << "Unfortunately client doesnt have enough money to afford it..." << endl;
            continue;
        }
        cout << "Manager " << man.getFirstName() << " got to work to sell tickets" << endl;
        client.setBalance(client.getBalance() - toursOffered[whatTicket].cost);
        if (rand() % 2 == 1) {
            cout << "Client " << client.getFirstName() << " want to make insurance" << endl;
            client.setBalance(client.getBalance() - 50);
            client.setInsurance(true);
        }
        if (toursOffered[whatTicket].visa) {
            if (rand() % 2 == 1) {
                cout << "Client " << client.getFirstName() << " want to use our visa service" << endl;
                client.setBalance(client.getBalance() - 100);
                client.setCompanyVisa(true);
            }
            else {
                cout << "Client " << client.getFirstName() << " will make visa in another way" << endl;
            }
        }
        client.setTouristSpecifications(toursOffered[whatTicket].country, toursOffered[whatTicket].city, toursOffered[whatTicket].date);
        toursOffered[whatTicket].size -= 1;
        cout << "Client " << client.getFirstName() << " succsesfully bought the tour to " << client.getCountry() << ", " << client.getCity() << " on "
            << client.getDate() << endl;
        cout << "Manager " << man.getFirstName() << " make it task" << endl << "\n";
    }

}

void TourAgen::printTours() {
    cout << "We offer this tourist list: " << endl;
    for (Tours& tour : toursOffered) {
        cout << tour.country << " " << tour.city << " " << tour.cost << "$ Only " << tour.size << " tickets left" << endl;
    }
}

void TourAgen::WriteToFile(vector<Tours>& toursOffered) {
    ofstream file("toursOffered.txt"); 
    size_t size = toursOffered.size();
    file << size << endl;
    for (const Tours& tour : toursOffered) {
        file << tour.country << ","     
            << tour.city << ","
            << tour.date << ","
            << tour.cost << ","
            << tour.size << ","
            << tour.visa << endl; 
    }
    file.close();
}


vector<TourAgen::Tours> TourAgen::ReadFromFile() {
    vector<Tours> toursTemp;
    ifstream file("toursOffered.txt"); 

    size_t size;
    file >> size;
    file.ignore(); 

    for (size_t i = 0; i < size; ++i) {
        Tours temp("", "", "", 0.0, 0, false);
        string visaStr; 

        getline(file, temp.country, ','); 
        getline(file, temp.city, ',');    
        getline(file, temp.date, ',');   
        file >> temp.cost;                  
        file.ignore();                   
        file >> temp.size;                
        file.ignore();                     
        getline(file, visaStr);             
        temp.visa = (visaStr == "1");
        toursTemp.push_back(temp); 
    }

    file.close();
    return toursTemp; 
}


void TourAgen::FillTours() {
    Tours tour1("Italy", "Rome", "2024-11-15", 1500.50, 20, true);
    Tours tour2("Japan", "Tokyo", "2024-12-10", 2000.75, 15, false);
    Tours tour3("France", "Paris", "2024-09-30", 1800.00, 25, true);

    toursOffered.push_back(tour1);
    toursOffered.push_back(tour2);
    toursOffered.push_back(tour3);
}


void TourAgen::printCountClients() {
    cout << "In that moment there are " << currentClients << " clients" << endl;
}
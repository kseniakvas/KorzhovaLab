#include <iostream>
#include <string>
#include <cstdlib>
#include "TourAgen.h"
#include "Client.h"
#include "Manager.h"

using namespace std;

int main() {
	srand(time(NULL));
	TourAgen::printCountClients();
	TourAgen TourismAgency("TourismAgency", "tourism@mail.net", "098548232", 1, "Something-City, Nowhere str.", 2, 100.5);
	// TourismAgency.FillTours(); TourismAgency.WriteToFile(TourismAgency.toursOffered);
	Manager manager("Test1", "Test1", "Unknown", 25, 155, "Manager", 25000, "Tourism", 3);
	TourismAgency.registerManager(manager);
	Client clients[5];
	Client *clients2 = new Client[5];
	for (int i = 0; i < 5; i++) {
		string clientfn = to_string(i+1), clientln = to_string(i + 11);
		clients[i] = Client(clientfn, clientfn, "Unknown", (18 + rand() % 83), (30000 + (rand() % 50000)), (100000 + rand() % 10000));
		TourismAgency.registerClient(clients[i]);
		clientfn = to_string(i+10), clientln = to_string(i + 21);
		clients2[i] = Client(clientfn, clientfn, "Unknown", (18 + rand() % 83), (30000 + (rand() % 50000)), (100000 + rand() % 10000));
		TourismAgency.registerClient(clients2[i]);
	}
	// TourismAgency.registerClient();
	TourismAgency.printTours();
	TourismAgency.buyTickets(TourismAgency.managers[0]);
	TourismAgency.printTours();

	// Lab4
	Client clienttest(clients[0]);
	clienttest.printClient();
	return 0;
}
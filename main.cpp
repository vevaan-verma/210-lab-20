// COMSC-210 | Lab 20 | Vevaan Verma
using namespace std;
#include <iostream>
#include <iomanip>

/* CONSTANTS */
const int SIZE = 3;

class Chair {

private:
	int legs;
	double* prices;

public:
	// constructors
	Chair() {

		prices = new double[SIZE];
		legs = (rand() % 2 == 0) ? 3 : 4; // randomly assign 3 or 4 legs

		const int MIN = 10000, MAX = 99999;

		for (int i = 0; i < SIZE; i++)
			prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double) 100;

	}

	Chair(int l, double pricesArr[]) {

		this->prices = pricesArr; // point to the passed array
		legs = l;

	}

	// getters and setters
	void setLegs(int l) { legs = l; }

	int getLegs() { return legs; }

	void setPrices(double p1, double p2, double p3) {

		prices[0] = p1;
		prices[1] = p2;
		prices[2] = p3;

	}

	double getAveragePrices() {

		double sum = 0;

		for (int i = 0; i < SIZE; i++)
			sum += prices[i];

		return sum / SIZE;

	}

	void print() {

		cout << "CHAIR DATA:" << endl;
		cout << "Legs: " << legs << endl;
		cout << "Price History: ";

		for (int i = 0; i < SIZE; i++)
			cout << prices[i] << " ";

		cout << endl << "Historical Average Price: " << getAveragePrices();
		cout << endl << "-------------------------------------" << endl << endl;

	}
};

int main() {

	srand(time(0)); // seed random number generator with current time to get different random numbers each time
	cout << fixed << setprecision(2);

	// creating pointer to first chair object (uses default constructor)
	Chair* chair1 = new Chair;
	chair1->print();
	delete chair1; // deallocate memory
	chair1 = nullptr;

	// creating pointer to second chair object (uses parameterized constructor)
	double chair2Prices[SIZE] = { 525.25, 434.34, 252.52 };
	Chair* chair2 = new Chair(3, chair2Prices);
	chair2->print();
	delete chair2; // deallocate memory
	chair2 = nullptr;

	// creating dynamic array of chair objects
	Chair* chairCollection = new Chair[SIZE];

	// the first element uses the default constructor

	// the second element uses the parameterized constructor
	double chair4Prices[SIZE] = { 484.84, 959.59, 868.68 };
	chairCollection[1] = Chair(4, chair4Prices);

	// the third element uses the default constructor and setter methods
	chairCollection[2].setLegs(4);
	chairCollection[2].setPrices(626.26, 515.15, 757.57);

	for (int i = 0; i < SIZE; i++)
		chairCollection[i].print();

	delete[] chairCollection; // deallocate memory
	chairCollection = nullptr;

	return 0;

}

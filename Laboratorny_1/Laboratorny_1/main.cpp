#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
char bufRus[256];
char* Rus(const char* text) {
	CharToOemA(text, bufRus);
	return bufRus;
}




using namespace std;

class Operator
{
public:

	Operator() : name("Noname"), abonentsCount(0), price(0) {};
	Operator(string n, int c, double p) {
		name = n;
		if (c < 0) {
			abonentsCount = 0;
		}
		else {
			abonentsCount = c;
		}
		if (p < 0) {
			price = 0;
		}
		else
		{
			price = p;
		}
	};
	double getRevenue() {
		return price * abonentsCount;
	}
	
	string getName() {
		return name;
	}

	void setAbonentsCount(int count) {
		if (count < 0) {
			abonentsCount = 0;
		}
		else {
			abonentsCount = count;
		}
	}

	void setPrice(double p) {
		if (p < 0) {
			price = 0;
		}
		else
		{
			price = p;
		}
	}

	void setName(string n) {
		name = n;
	}

private:
	string name;
	double price;
	int abonentsCount;

};




int main(){
	Operator MTS("MTS", 10, 15);
	printf(Rus("Выручка компании %s: %f"),MTS.getName().c_str(), MTS.getRevenue());
	return 0;
}
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace System;
using namespace System::Collections::Generic;


public ref class Customer
{
private:
	String^ name;
	int cost;
	int trafic;
	int limit = 100;


public:
	Customer();
	Customer(String^, int t);
	Customer(String^ n, int t, int traf);
	//Customer(string n, Tarif t, int tr) : name(n), tarif(t), trafic(tr), id(countUsers++) { }
	~Customer() { ; }

	
	property double Summa {
			double get() {
				if (trafic <= limit) {
					return cost;
				}
				else {
					return cost + (trafic - limit);
				}
			}
	}

	property int Trafic {
		int get() { return trafic; }
		void set(int n) { trafic = n; }
	}

	
	
	/*nt getCost() { return cost; }
	int getTrafic() { return trafic; }


	void setTrafic(int newTrafic) { trafic = newTrafic; }

	void setCost(int c) { cost = c; }*/
	

	
	property int Cost {
		int get() { return cost; }
		void set(int n) { cost = n; }
	}
	property String^ Name {
		String^ get() { return name; }
		void set(String^ n) { name = n; }
	}
	
	void changeInformation(String^ newName, int newCost, int newTrafic);
};




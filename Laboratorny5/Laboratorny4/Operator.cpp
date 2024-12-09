#include "Operator.h"



Customer::Customer() {};
Customer::Customer(String^ n, int t) : name(n), cost(t), trafic(0) { };
Customer::Customer(String^ n, int t, int traf) : name(n), cost(t), trafic(traf) { };
void Customer::changeInformation(String^ newName, int newCost, int newTrafic) {
	name = newName;
	cost = newCost;
	trafic = newTrafic;
}
//property double Customer::Summa{
//	if (trafic <= limit) {
//		return cost;
//	}
//	else {
//		return cost + (trafic - limit);
//	}
//}


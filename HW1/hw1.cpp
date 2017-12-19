/*
*Austin Keelin
*ajk0033
*hw1.cpp
*Compiled using g++ compiler
*/
#include <iostream>
using namespace std;

const double RATIO = 0.001;

int main()
{
	double lethal_amount_mouse, mouse_weight, dieter_weight, lethal_amount_dieter;
	cout << "What is the amount of artificial sweetener needed to kill a mouse: ";
	cin >> lethal_amount_mouse;
	cout << "\nWhat is the weight of the mouse: ";
	cin >> mouse_weight;
	cout << "\nWhat is the weight of the dieter: ";
	cin >> dieter_weight;
	lethal_amount_dieter = lethal_amount_mouse / RATIO * dieter_weight / mouse_weight;
	cout << "\nYou can drink " << lethal_amount_dieter << " diet soda without dying as a result." << endl;
	return 0;
}

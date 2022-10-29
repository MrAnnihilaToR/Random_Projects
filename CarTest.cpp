/*
(C++) A car dealer for VW needs a system for configuring different attributes of a car. The dealer can propose to the
end customer a number of options:

Engine:
1.0 TSI BMT – 115 hp – added price per month 339
1.5 TSI EVO BM – 130 hp – added price per month 359
1.5 TSI EVO BMT – 150 hp – added price per month 362

Color:
Urano Grey – added price per month 0
Tornado Red – added price per month 2.51
Lapiz Blue Metallic – added price per month 8.11
Oryx White Perlmutteffect – added price per month 16.72

Security & Technologies
Lane Assist – added price per month 9.74
Rear View – added price per month 4.51
LED Lights – added price per month 28.06
Park Assistant – added price per month 9.33

Media & Infotainment
App Connect – added price per month 3.13
Navigational System – added price per month 9.39

The dealer wants to receive a Car object configured as needed and then invoke the price() method which will return the
price of the configured car (per month leasing). Take into consideration that new option might be added into the future.

Example:
Customer wants a car with 1.5 TSI engine 130 hp, Tornado Red color, Lane Assist & Park Assistant and last but not least
App Connect. The dealer should construct the car based on the customer’s requirements and provide the price per month.
In this specific case: 383.71.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


class Car {
	string name , engine , color;
	vector<string> S_and_T; /// security and technologies
	vector<string> media;
	double totalPrice = 0;
public:
	Car();


	void input();
	void output();

	void chooseEngine();
	void chooseColor();
	void chooseSnT();
	void chooseMedia();
	void price();
};

void Car::chooseMedia() {
	int choice = 0;
	cout << "Please choose security & technologies, which you want to be integrated in your vehicle : " << endl;


	cout << "1 -> App Connect - added price per month 3.13" << endl;
	cout << "2 -> Navigational System - added price per month 9.39" << endl;
	cout << "3 -> CONTINUE" << endl;

	while (true) {
		cin >> choice;
		switch (choice) {
		case 1:
			if (find(this->media.begin(), this->media.end(), "App Connect") == this->media.end()) /// proverka , dali go nqma elementa .
			{
				this->media.push_back("App Connect");
				this->totalPrice += 3.13;
				choice = 0;
				continue;
			}
			else {
				cout << "Already Selected!" << endl;
				continue;
			}
		case 2:
			if (find(this->media.begin(), this->media.end(), "Navigational System") == this->media.end()) /// proverka , dali go nqma elementa .
			{
				this->media.push_back("Navigational System");
				this->totalPrice += 9.39;
				choice = 0;
				continue;
			}
			else {
				cout << "Already Selected!" << endl;
				choice = 0;
				continue;
			}
		case 3:break;
		default:
			cout << "INVALID INPUT" << endl;
			choice = 0;
			continue;
		}
		break;
	}
}
void Car::chooseSnT() {
	int choice = 0;
	cout << "Please choose security & technologies, which you want to be integrated in your vehicle : " << endl;


	cout << "1 -> Lane Assist - added price per month 9.74" << endl;
	cout << "2 -> Rear View - added price per month 4.51" << endl;
	cout << "3 -> LED Lights - added price per month 28.06" << endl;
	cout << "4 -> Park Assistant - added price per month 9.33" << endl;
	cout << "5 -> CONTINUE" << endl;

	while (true) {
		cin >> choice;
		switch (choice) {
		case 1: 
			if(find(this->S_and_T.begin(), this->S_and_T.end(), "Lane Assist")== this->S_and_T.end()) /// proverka , dali go nqma elementa .
			{
				this->S_and_T.push_back("Lane Assist");
				this->totalPrice += 9.74;
				choice = 0;
				continue;
		    }
			else {
				cout << "Already Selected!" << endl;
				choice = 0;
				continue;
			}
		case 2:
			if (find(this->S_and_T.begin(), this->S_and_T.end(), "Rear View") == this->S_and_T.end()) /// proverka , dali go nqma elementa .
			{
				this->S_and_T.push_back("Rear View");
				this->totalPrice += 4.51;
				choice = 0;
				continue;
			}
			else {
				cout << "Already Selected!" << endl;
				choice = 0;
				continue;
			}
		case 3:
			if (find(this->S_and_T.begin(), this->S_and_T.end(), "LED Lights") == this->S_and_T.end()) /// proverka , dali go nqma elementa .
			{
				this->S_and_T.push_back("LED Lights");
				this->totalPrice += 28.06;
				choice = 0;
				continue;
			}
			else {
				cout << "Already Selected!" << endl;
				choice = 0;
				continue;
			}
		case 4:
			if (find(this->S_and_T.begin(), this->S_and_T.end(), "Park Assistant") == this->S_and_T.end()) /// proverka , dali go nqma elementa .
			{
				this->S_and_T.push_back("Park Assistant");
				this->totalPrice += 9.33;
				choice = 0;
				continue;
			}
			else {
				cout << "Already Selected!" << endl;
				choice = 0;
				continue;
			}
		case 5:break;
		default:
			cout << "INVALID INPUT" << endl;
			choice = 0;
			continue;

		}
		break;
	}
	
}
void Car::chooseColor() {
	int choice = 0;
	cout << "Please, choose a color for the car: " << endl;


	cout << "1 -> Urano Grey - added price per month 0" << endl;
	cout << "2 -> Tornado Red - added price per month 2.51" << endl;
	cout << "3 -> Lapiz Blue Metallic - added price per month 8.11" << endl;
	cout << "4 -> Oryx White Perlmutteffect - added price per month 16.72" << endl;


	
	while (true) {
		cin >> choice;
		switch (choice) {
		case 1: this->color = "Urano Grey";break;
		case 2: this->color = "Tornado Red";
			this->totalPrice += 2.51;
			break;
		case 3: this->color = "Lapiz Blue Metallic";
			this->totalPrice += 8.11;
			break;
		case 4: this->color = "Oryx White Perlmutteffect";
			this->totalPrice += 16.72;
			break;
		default:cout << "INVALID INPUT" << endl;
			continue;
		}
		break;
	}
}
void Car::chooseEngine() {
	int choice = 0;
	cout << "Please, choose an engine for the car: " << endl;

	cout << "1 -> 1.0 TSI BMT - 115 hp - added price per month 339" << endl;
	cout << "2 -> 1.5 TSI EVO BM - 130 hp - added price per month 359" << endl;
	cout << "3 -> 1.5 TSI EVO BMT - 150 hp - added price per month 362" << endl;
	

	
	while (true) {
		cin >> choice;
		switch (choice) {
		case 1: this->engine = "1.0 TSI BMT - 115 hp";
			this->totalPrice += 339;
			break;
		case 2: this->engine = "1.5 TSI EVO BM - 130 hp";
			this->totalPrice += 359;
			break;
		case 3: this->engine = "1.5 TSI EVO BMT - 150 hp";
			this->totalPrice += 362;
			break;
		default:cout << "INVALID INPUT" << endl;
			continue;
		}
		
		break;
	}
	
}


Car::Car() {
	input();
	output();
	price();
}

void Car::input() {
	cout << "Please, enter a name for the car: "; getline(cin >> ws , name);

	cout << '\n';

	chooseEngine();

	cout << '\n';

	chooseColor();

	cout << '\n';

	chooseSnT(); //// Here is the problem

	cout << '\n';

	chooseMedia();
	
	cout << '\n';

	output();

}

void Car::output() {
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout << '\n';
	cout << "Name of the car: "<<this->name<<endl;
	cout << '\n';
	cout << "Engine of the car: " << this->engine << endl;
	cout << '\n';
	cout << "Color of the car: " << this->color << endl;
	cout << '\n';
	cout << "Security and technologies of the car : "<<endl;
	if (!S_and_T.empty()) {
		int i = 1;
		for (string a : S_and_T)
		{
			cout << i << ". " << a << endl;
			i++;
		}
	}

	cout << '\n';

	cout << "Media and infotainment of the car : " << endl;
	if (!media.empty()) {
		int i = 1;
		for (string s : media)
		{
			cout << i << ". " << s << endl;
			i++;
		}
		cout << '\n';
	}
}

void Car::price() {
	cout << '\n';
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout << "The selected vehicle has price per month : " << this->totalPrice << '$' << endl;
	cout << '\n';
	cout << "The price per year will be : " << this->totalPrice * 12 << '$' << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
}

int main() {
	Car obj1;

	return 0;
}
#include <stdio.h>;
#include <stdlib.h>;
#include <iostream>;
#include <time.h>;
#include <vector>;
using namespace std;

void reserveTicket();
void firstClass();
void economy();
void printBoardingPass();

vector<bool> firstClassSeats;
int firstClassSeatsCount = 0;
vector<bool> economySeats;
int economySeatsCount = 0;

int mySeat;
string mySeatType;

int main()
{
	reserveTicket();
	system("pause");
	return 0;
}

void reserveTicket() {
	if (economySeatsCount == 5 && firstClassSeatsCount == 5) {
		cout << "\nAll seats have been taken\n";
		return;
	}
	int answer;
	cout << "Please type 1 for \"first class\" \nPlease type 2 for \"economy\" \nPlease type 3 to exit." << endl;
	cin >> answer;
	if (answer == 1) {
		firstClass();
	}else if (answer == 2) {
		economy();
	}else {
		exit(0);
	}
	reserveTicket();
}

void firstClass() {
	if (firstClassSeatsCount < 5) {
		firstClassSeats.push_back(true);
		firstClassSeatsCount++;
		mySeat = firstClassSeatsCount;
		mySeatType = "First Class";
	}else{
		cout << "The first class section is full. Would you like to change to economy? (y/n)" << endl;
		char answer;
		cin >> answer;
		if (answer == 'y') {
			economy();
		}else{
			cout << "Next flight leaves in 3 hours." << endl;
		}
	}
	printBoardingPass();
}

void economy() {
	if (economySeatsCount < 5) {
		economySeats.push_back(true);
		economySeatsCount++;
		mySeat = 5 + economySeatsCount;
		mySeatType = "Economy";
	}else{
		cout << "The economy section is full. Would you like to change to first class? (y/n)" << endl;
		char answer;
		cin >> answer;
		if (answer == 'y') {
			firstClass();
		}else{
			cout << "Next flight leaves in 3 hours." << endl;
		}
	}
	printBoardingPass();
}

void printBoardingPass() {
	cout << "\n" << 5 - firstClassSeatsCount << " seats availble in the first class." << endl;
	cout << "\n" << 5 - economySeatsCount << " seats availble in the first class." << endl;
	cout << "\nYour seat number is " << mySeat << endl << endl;
}
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Machine
{
	string name;
	double cost;
	int available;
};

void initialize();
void printAll();
void printOne(Machine param);
void getDrink();
void buyDrink(int i);

Machine machine[4];

int main()
{
	initialize();
	getDrink();
	system("pause");
	return 0;
}

void initialize() {
	machine[0].name = "Cola";
	machine[0].cost = 5;
	machine[0].available = 5;

	machine[1].name = "Pepsi";
	machine[1].cost = 5;
	machine[1].available = 5;

	machine[2].name = "Lemon-Lime";
	machine[2].cost = 2.5;
	machine[2].available = 5;

	machine[3].name = "Grape-Soda";
	machine[3].cost = 2.75;
	machine[3].available = 5;

	machine[4].name = "Cream-Soda";
	machine[4].cost = 3;
	machine[4].available = 5;
}

void printAll() {
	cout << endl;
	cout << "Drink name:" << setw(20);
	cout << "\tCost (L.E.):" << setw(4);
	cout << "\tNumber Available in Machine: " << fixed << setprecision(3);
	cout << endl;
	for(int i = 0; i < 5; i++) {
		printOne(machine[i]);
	}
}

void printOne(Machine param) {
	cout << param.name << setw(31 - param.name.length());
	cout << param.cost << setw(20);
	cout << param.available << fixed << setprecision(3);
	cout << endl;
}

void getDrink() {
	printAll();
	string answer;
	cout << "\nChoose a drink or type 'exit' to end the program" << endl;
	cin >> answer;
	if(answer == "exit") {
		exit(0);
	}else{
		int index = -1;
		for (int i = 0; i < 5; i++) {
			if(machine[i].name == answer) {
				index = i;
			}
		}
		if(index != -1) {
			cout << "\nYou have choosen: " << endl;
			printOne(machine[index]);
			if(machine[index].available == 0) {
				cout << "\nItem is not available.\n";
				getDrink();
			}else{
				buyDrink(index);
				getDrink();
			}
		}else{
			cout << "\nNo Match Found.";
			getDrink();
		}
	}
}

void buyDrink(int i) {
	cout << "\nHow much money did you pay (1 to 10 L.E.)? ";
	int amount;
	cin >> amount;
	if (amount < 1 || amount > 10 || amount < machine[i].cost) {
		cout << "\nUnacceptable amount, please try again\n";
		buyDrink(i);
	}else{
		cout << "\nYour change is " << amount - machine[i].cost << endl;
		machine[i].available--;
	}
}
#include <iostream>
#include <time.h>
#include <stdio.h>;
#include <stdlib.h>;

using namespace std;

int comp;
int compPoints = 0;
int player;
int playerPoints = 0;

void getCompChoice();
void getPlayerChoice();
void newGame();
void evaluate();

int main() {
	srand ( (unsigned int)time(NULL) );

	newGame();

	system("pause");
	return 0;
}

void newGame() {
	getPlayerChoice();
	getCompChoice();
	evaluate();
}

void getPlayerChoice() {
	cout << endl;
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "0. Exit\n";
    cin >> player;
	if (player == 0) {
		cout << "You won " << playerPoints << " times." << endl;
		cout << "Computer won " << compPoints << " times." << endl;

		if (playerPoints > compPoints) {
			cout << "Player's total points win" << endl;
		}else if (compPoints > playerPoints) {
			cout << "Computer's total points win" << endl;
		}else{
			cout << "Draw" << endl;
		}

		system("pause");
		exit(0);
	}else if(player == 1 || player == 2 || player == 3) {

	}else{
		getPlayerChoice();
	}
}

void getCompChoice() {
	comp = (rand() % 3) + 1;
}


void evaluate() {
	if (player == comp) {
		cout << "\nSame choice, no one wins\n";
		newGame();
	}
	if(player == 1) {
		if (comp == 2) {
			cout << "Computer wins";
			compPoints++;
		}
		if (comp == 3) {
			cout << "You win";
			playerPoints++;
		}
	}

	if(player == 2) {
		if (comp == 1) {
			cout << "You win";
			playerPoints++;
		}
		if (comp == 3) {
			cout << "Computer wins";
			compPoints++;
		}
	}

	// rock = 1     paper = 2    siccors = 3
	if(player == 3) {
		if (comp == 1) {
			cout << "Computer wins";
			compPoints++;
		}
		if (comp == 2) {
			cout << "You win";
			playerPoints++;
		}
	}

	newGame();
}
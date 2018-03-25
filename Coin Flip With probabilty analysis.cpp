#include <stdio.h>;
#include <stdlib.h>;
#include <iostream>;
#include <time.h>
using namespace std;

bool flip(float prop);

int main()
{
	srand ( (unsigned int)time(NULL) );

	int headA = 0;
	int tailA = 0;

	for (int i = 1; i <= 100; i++) {
		bool flag = flip(0.5);
		if (flag) {
			headA++;
		}else{
			tailA++;
		}
	}

	cout << "Head is called " << headA << " times, and tail is called " << tailA << " times." << endl;

	int headB = 0;
	int tailB = 0;

	for (int i = 1; i <= 100; i++) {
		if (flip(0.3)) {
			headB++;
		}else{
			tailB++;
		}
	}

	cout << "Head is called " << headB << " times, and tail is called " << tailB << " times." << endl;
	system("pause");
	return 0;
}

bool flip(float prop) {
	float coin = rand() % 10;
	bool flag;
	float p = prop*10;
	if (coin < p) {
		flag = true;
	}else{
		flag = false;
	}
	return flag;
}
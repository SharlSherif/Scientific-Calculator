#include <iostream>
using namespace std;

enum Operations {
	Subtraction = 1,
	Addition = 2,
	Multiplication = 3,
};


int Menu() {
	cout << "Choose the operation:"<< endl;
	cout << "1 - Subtraction"<< endl;
	cout << "2 - Addition"<<endl;
	cout << "3 - Multiplication"<<endl;
	
	float choice = -1;
	do {
		cout << "Your choice:" << endl;
		cin >> choice;
	} while (choice != Subtraction && choice != Addition && choice != Multiplication);

	return choice;
}


class Calc {

	void run(int Op) {
		float x[2] = { 0.3, 0.1 };
		float result;
		switch (Op) {
			case Addition:
				result = this.addition(x, 2);
				break;
			case Multiplication:
				result = this.multiplication(x, 2);
				break;
		}
		printf("%f", result);
	}

	float addition(float n[], int size) {
		float sum=0;
		for (int i = 0; i < size; i++) sum += n[i];
		return sum;
	}
	float multiplication(float n[], int size) {
		float mult = 0;
		for (int i = 0; i < size; i++) mult += n[i];
		return mult;
	}
};

int main()
{
	float choice = Menu();
	// test
}
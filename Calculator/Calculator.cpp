#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
enum Operations {
	Subtraction = 1,
	Addition = 2,
	Multiplication = 3,
	Division = 4,
	Power = 5
};


int Menu() {
	cout << "Choose the operation:"<< endl;
	cout << "1 - Subtraction"<< endl;
	cout << "2 - Addition"<<endl;
	cout << "3 - Multiplication" << endl;
	cout << "4 - Division" << endl;
	cout << "5 - Power"<<endl;
	
	float choice = -1;
	do {
		cout << "Your choice:" << endl;
		cin >> choice;
	} while (choice != Subtraction && choice != Power && choice != Division && choice != Addition && choice != Multiplication);

	return choice;
}
int askHowManyNumbers() {
	int result = 0;
	cout << "How many numbers?"<<endl;
	cin >> result;
	return result;
}

float* parseInput(int n) {
	float *numbers;
	numbers = (float *) malloc(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	return numbers;
}

class Calc {

	public:
		void run(int Op, float* numbers, int size) {
			float result = -1.0;
			switch (Op) {
				case Addition:
					result = addition(numbers, size);
					break;
				case Subtraction:
					result = subtraction(numbers, size);
					break;
				case Multiplication:
					result = multiplication(numbers, size);
					break;
				case Division:
					result = division(numbers, size);
					break;
				case Power:
					result = power(numbers);
					break;
			}
			cout << result<< endl;
		}

		float addition(float* n, int size = 2) {
			float sum = 0.0;
			for (int i = 0; i < size; i++) sum += n[i];
			return sum;
		}
		float subtraction(float* n, int size = 2) {
			float sub = n[0];
			for (int i = 1; i < size; i++) sub -= n[i];
			return sub;
		}
		float multiplication(float* n, int size=2) {
			float mult = 1.0;
			for (int i = 0; i < size; i++) mult = mult * n[i];
			return mult;
		}
		float division(float* n, int size = 2) {
			float div = 1.00;
			for (int i = 0; i < size; i++) div = div/ n[i];
			return div;
		}

		// we subtract 1 from the power because it already starts the first multiplication using the number given.
		// so if number = 5, power = 2. it should equal 25 but instead it would be more because it multiplies 5 by itself 3 times
		float power(float* n) {
			float number = n[0];
			float power = n[1];
			float powerQuery[2] = { n[1], 1 };
			float powerMinusOne = subtraction(powerQuery);

			float result = number;
			
			for (int i = 0; i < powerMinusOne; i++) {
				float multiplyNumberByItself[2] = { result, number };
				result = multiplication(multiplyNumberByItself);
			}
			return result;
		}

		float root(float* n) {

		}
} calc;

int main()
{
	float choice = Menu();
	int inputsize = askHowManyNumbers();
	float* input = parseInput(inputsize);
	calc.run(choice, input, inputsize);
}
#include <iostream>
using namespace std;

typedef struct Poly {
	float a = 0;
	float b = 0;
	float c = 0;
}Poly;

typedef struct Answer {
	float x1 = 0;
	float x2 = 0;
	float Error = 0;
}Answer;

Poly GetPoly() {
	struct Poly poly;

	cin >> poly.a >> poly.b >> poly.c;

	return poly;
}

float Discriminant(Poly poly) {
	return (poly.b * poly.b) - (4 * poly.a * poly.c);
}

void PrintAnswer(Answer answer) {
	if (answer.Error == 0) {
		if (answer.x1 != answer.x2) {
			cout << "X1 = " << answer.x1 << endl << "X2 = " << answer.x2;
		}
		else {
			cout << "X = " << answer.x1;
		}
	}
	else {
		cout << "Error : " << answer.Error;
	}
}

Answer QuadraticEquation(Poly poly) {
	Answer answer;

	if (poly.a == 0) {
		if (poly.b == 0) {
			if (poly.c == 0) {
				answer.Error = 1;
				return answer;
			}
			else {
				answer.Error = 2;
				return answer;
			}
		}
		else {
			if (poly.c != 0) {
				answer.x1 = -poly.c / poly.b;
				answer.x2 = answer.x1;
			}
		}
	}
	else {
		if (Discriminant(poly) < 0) {
			answer.Error = 3;
		}
		else if (Discriminant(poly) == 0) {
			answer.x1 = (-poly.b) / (2 * poly.a);
			answer.x2 = answer.x1;
		}
		else {
			answer.x1 = (-poly.b + sqrt(Discriminant(poly))) / (2 * poly.a);
			answer.x2 = (-poly.b - sqrt(Discriminant(poly))) / (2 * poly.a);
		}
	}

	return answer;
}

int main(void) {
	cout << "Enter coefficents a, b, c of ax^2 + bx + c = 0 through space" << endl;
	PrintAnswer(QuadraticEquation(GetPoly()));

	return 0;
}
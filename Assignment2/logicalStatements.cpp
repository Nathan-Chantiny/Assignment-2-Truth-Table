#include <iostream>

using namespace std;

string TorF;

bool A;
bool B;
bool C;
bool ABC[8][3] = {
	{0,0,0},
	{0,0,1},
	{0,1,0},
	{0,1,1},
	{1,0,0},
	{1,0,1},
	{1,1,0},
	{1,1,1}
};

void boolsAndStatements(int row, int position) {
	A = ABC[row][0];
	B = ABC[row][1];
	C = ABC[row][2];

	if (position == 0 && ((A && B) || (A && C))) {
		TorF = "True";
	}
	else if (position == 1 && ((A && C) && (B && !C))) {
		TorF = "True";
	}
	else if (position == 2 && ((A || B) && !(B || C))) {
		TorF = "True";
	}
	else if (position == 3 && ((A || (B && C)) && (!A && !B))) {
		TorF = "True";
	}
	else if (position == 4 && (((B && C) || (C && A)) && (!(A || B) && C))) {
		TorF = "True";
	}
	else {
		TorF = "False";
	}
	cout << A << "    " << B << "    " << C << "    " << TorF << endl;
}

int main() {
	cout << "(A and B) or (A and C)" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 0);
	}

	cout << "\n(A and C) and (B and !C)" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 1);
	}

	cout << "\n(A or B) and !(B or C)" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 2);
	}

	cout << "\n(A or (B and C)) and (!A and !B)" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 3);
	}

	cout << "\n((B and C) or (C and A)) and (!(A or B) and C)" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 4);
	}
}
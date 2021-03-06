// CorrectedLab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#define n 5


using namespace std;

class Matrix {
private:
	int a[n][n];
	int line, col, summation, mean;

public:
	void MatrixInput();
	void MatrixOutput();
	void InsertionSorting();
	void SumAndGeometricMean();
};

void Matrix::MatrixInput() {
	for (line = 0; line < n; line++) {
		for (col = 0; col < n; col++) {
			cout << "Enter the element [" << line + 1 << ";" << col + 1 << "]";
			cin >> a[line][col];
			cout << endl;
		}
	}
}

void Matrix::MatrixOutput() {
	for (line = 0; line < n; line++) {
		for (col = 0; col < n; col++) {
			if (col == 0) cout << endl;
			cout << a[line][col] << "\t";
		}
	}
}

void Matrix::InsertionSorting() {
	int x = 0;
	int current;

	for (int col = 0; col < 5; col++) {
		for (int line = 1; line < 5; line++) {
			x = a[line][col];
			current = line - 1;
			while (current >= 0 && a[current][col] > x) {
				a[current + 1][col] = a[current][col];
				current = current - 1;
			}
			a[current + 1][col] = x;
		}
	}
}

void Matrix::SumAndGeometricMean() {
	for (int line = 0; line < n; line++) {
		int element = 0;
		int summation = 1;
		int sum = 0;

		for (int col = 0; col < n; col++) {
			if (line < col) {
				element = element + 1;
				sum = sum + a[line][col];
			}
		}
		cout << "\n";
		summation = summation*sum;
		cout << "\t" << "Sum of " << line + 1 << " line above the main diagonal = " << sum;
	}

	mean = pow(summation, 0.2);
	cout << "\n" << "Geometric mean = " << mean << "  \n   ";
}

int main() {
	Matrix S;
	S.MatrixInput();
	cout << endl;
	cout << "Entered matrix:\n";
	S.MatrixOutput();
	cout << endl;
	S.InsertionSorting();
	cout << "\n New matrix:\n";
	S.MatrixOutput();
	cout << endl;
	cout << "\n Summation:\n";
	S.SumAndGeometricMean();
	cout << endl;
}



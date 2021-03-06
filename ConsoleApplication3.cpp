// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#define n 5


using namespace std;

class Matrix
{
private:
	int a[n][n];
	int i, j, k, c, s, g_m;

public:
	void MatrixInput();
	void MatrixOutput();
	void Sorting();
	void SumAndGeometricMean();
};

void Matrix::MatrixInput()
{
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << "Please, enter the element [" << i + 1 << ";" << j + 1 << "]";
			cin >> a[i][j];
			cout << endl;
		}
	}
}

void Matrix::MatrixOutput()
{
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (j == 0) cout << endl;
			cout << a[i][j] << "\t";
		}
	}
}

void Matrix::Sorting()
{
	int c = 0;

	for (int j = 0; j<5; j++) {
		for (int i = 1; i<5; i++) {
			c = a[i][j];
			k = i - 1;
			while (k >= 0 && a[k][j] > c)
			{
				a[k + 1][j] = a[k][j];
				k = k - 1;
			}
			a[k + 1][j] = c;
		}
	}
}

void Matrix::SumAndGeometricMean()
{
	for (int i = 0; i < n; i++) {
		int q = 0;
		int sum = 0;
		int s = 1;

		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				q = q + 1;
				sum = sum + a[i][j];
			}

		}

		cout << "\n";
		s = s*sum;
		cout << "\t" << "sum of " << i + 1 << " line = " << sum;

	}

	g_m = pow(s, 0.2);
	cout << "\n" << "geometric mean = " << g_m << "  \n   ";
	system("pause");

}

int main()
{
	Matrix S;
	S.MatrixInput();
	cout << endl;
	cout << "Entered matrix:\n";
	S.MatrixOutput();
	cout << endl;
	S.Sorting();
	cout << "\n New matrix:\n";
	S.MatrixOutput();
	cout << endl;
	cout << "\n Summation:\n";
	S.SumAndGeometricMean();
	cout << endl;
}



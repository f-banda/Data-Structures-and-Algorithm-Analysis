/* 	Francisco Banda (Z1912220)
	Matrix Multiplication
	CSCI 340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/


#include "matrix.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
using namespace std;


/*
Opens two data files for reading and creates the input streams is1 and is2.
If either file fails to open, it prints an error message on stderr and
aborts the program with a non-zero exit value.
*/
void open_files(ifstream &is1, ifstream &is2) {
	is1.open(FILE1);
	is2.open(FILE2);
	//Print error message if can't open
	if (!is1 || !is2) {
		cerr << "Failed to open a file, aborting program...";
		exit(1);
	}
}

/*
Reads the input values from the input stream is and stores them in matrix m,
which is defined as a two-dimensional vector of integers.
*/
void read_data(ifstream &is, vector<vector<int>> &m) {
	for (size_t i = 0; i < m.size(); i++)
	{
		for (size_t j = 0; j < m[i].size(); j++)
		{
			is >> m[i][j];
		}
	}
}
/*
Prints the contents of on stdout by allocating ITEM_W spaces for each integer
value, which is defined in the header file matrix.h.
*/
void print_data(const vector<vector<int>> &m) {
	cout << m.size() << " x " << m[0].size() << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < m.size(); i++) {
		for (size_t j = 0; j < m[i].size(); j++) {
			cout << right << setw(ITEM_W) << m[i][j];
		}
		cout << "\n";
	}
}

/*
multiples the values in the matrices A and B and stores the results in the matrix C.
*/
void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) {
	for (size_t i = 0; i < A.size(); i++) {
		for (size_t j = 0; j < B[0].size(); j++) {
			C[i][j] = 0;
			//If C(i, j) is the value of C in row i and column j of C, then C(i, j) += A(i, k) * B(k, j) for all index values of k
			for (size_t k = 0; k < A[0].size(); k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
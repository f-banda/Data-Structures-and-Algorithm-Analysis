/* 	Francisco Banda (Z1912220)
	Introduction
	CSCI 340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include "rgi.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

using std::endl;
using std::cout;
using std::vector;

constexpr int SEED = 1;
constexpr int LOW = 1, HIGH = 10000;
int NO_ITEMS = 12;


void genRndNums(vector<int> &v) {

	srand(SEED);

	for (int i = 0; i < 200; ++i)
	{
		int num = rand()%(HIGH-LOW+1)+LOW;
		v.push_back(num);
	}

}
void printVec(const vector<int> &v) {
	for (int i = 1; i <= 200; ++i)
	{
		cout << std::setw(5) << v[i - 1];
		if (i % 12 == 0)
		{
			cout << endl;
		}
		if (i >= 200)
		{
			cout << endl;
		}
	}
}

int main() {

	vector<int> v;

	genRndNums(v);

	sort(v.begin(), v.end());

	printVec(v);

    return 0;
}



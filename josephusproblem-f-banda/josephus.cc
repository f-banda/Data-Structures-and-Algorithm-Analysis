/* 	Francisco Banda (Z1912220)
	The Josephus Problem
	CSCI 340-3
	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include "josephus.h"
#include <list>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

void init_vals(vector<string> &L, unsigned int &N)
{
	typedef vector<string>::iterator iter;

	//Resize to N
	L.resize(N);

	//Loop iterator 
	iter loop = L.begin(); iter begin = L.begin(); iter end = L.end();

	//Fill the names of people in list L
	for (; loop != L.end(); loop++)
	{
		generate(begin, end, SEQ(N));
	}

}

void print_list(const vector<string> &L, const unsigned int & cnt)
{
	cout << endl;

	typedef vector<string>::const_iterator iter;
	if (cnt == 0)
	{
		cout << "Initial group of people" << endl;
		cout << "-----------------------" << endl;
	}
	else
	{
		cout << "After eliminating " << cnt << "th person" << endl;
		if (cnt < 10) {
			cout << "----------------------------" << endl;
		}
		if (cnt > 9 && cnt < 100) {
			cout << "-----------------------------" << endl;
		}
		if (cnt > 99) {
			cout << "------------------------------" << endl;
		}
		if (cnt > 999) {
			cout << "-------------------------------" << endl;
		}
	}

	int count = 0;
	iter loop = L.cbegin();

	for (; loop != L.cend(); ++loop){
		cout << *loop << " "; count++;

		if ((count % NO_ITEMS) == 0){
			cout << endl;
		}
	}
	cout << endl;
}

int main()
{
	typedef vector<string>::iterator iter;

	//Hold will.. hold test data
	vector<string> hold;

	unsigned int n; //Number of initial people
	unsigned int m; //Count to eliminate person
	unsigned int k; //Print frequency

	//Initialize cnt to 0
	unsigned int cnt = 0;

	cin >> n;
	cin >> m;
	cin >> k;

	cout << "Number of people? " << n << endl;
	cout << "Index for elimination? " << m << endl;
	cout << "Index for printing? " << k << endl;

	//Call init_vals to fill with values
	init_vals(hold, n);

	//Call print_list to... print values
	print_list(hold, cnt);

	//Loop iterator
	iter loop = hold.begin();

	//Set starting position
	unsigned int i = 1;

	//Loop until size is 1
	while (hold.size() > 1)
	{
		//Loop for M times
		while (i < m){
			//When loop reaches the end, reset
			if (loop == hold.end()){
				loop = hold.begin();
			}
			//Increment each loop
			loop = loop + 1;
			//Increment until i reaches M
			i++;

		}
		//If loop reaches the end, reset
		if (loop == hold.end()){
			loop = hold.begin();
		}
		//Delete the current value being pointed to
		loop = hold.erase(loop);

		//Reset counter
		i = 1;
		cnt++;
		
		//Call print_list when the end is reached
		if ((cnt % k) == 0){
			print_list(hold, cnt);
		}

	}

	print_list(hold, cnt);

	return 0;
}
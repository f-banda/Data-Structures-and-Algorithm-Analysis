/* 	Francisco Banda (Z1912220)
	Sieve of Eratosthenes
	CSCI 340-3
	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include <iostream>
#include <iomanip>
#include <set>

using std::set;

// Routine to apply the Sieve of Eratosthenes algorithm to remove all nonprime numbers from the integer set
void sieve(set<int>& s, int n)
{
	bool *binary = new bool[n]; //Setting bool value of 0
	set<int>::iterator  iter;
	for (int i = 2; i * i <= n; i++) { // Test m * m rather than computing sqrt
		if (binary[i] == 0) { //Check if prime
			for (int j = 2; i*j <= n; j++) {
				binary[i*j] = 1; //Changing to true
				iter = s.find(i * j); //Locate num
				if (iter != s.end()) { 
					s.erase(iter);
				}
			}
		}
	}
	delete[] binary;
}


// routine used to print the elements in the integer set
void print_primes(const set<int>& s)
{
	set<int>::iterator i;
	int nums = 0;
	for (i = s.begin(); i != s.end(); i++) {
		nums++;
		std::cout << std::right << std::setw(5) << *i;
		if (nums == 16) {
			std::cout << std::endl;
			nums = 0;
		}
	}
	std::cout << std::endl;
}

int main() {
	int n;
	std::cin >> n; //Take user input
	std::cout << "Upper limit for the set of primes: " << n;
	std::cout << std::endl << std::endl;
	//Insert numbers from 2 to n into the set
	set<int> set;
	for (int i = 2; i <= n; i++) {
		set.insert(i);
	}
	//Calling routines
	sieve(set, n);
	print_primes(set);
	
	return 0;
}

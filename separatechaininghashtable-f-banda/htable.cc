/* 	Francisco Banda (Z1912220)
    Hashing with Separate Chaining and Indirect Sorting
    CSCI 340-3
    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/

#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters
bool inc = true;

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...

//Constructor
HT::HT(const unsigned &hs) : hsize(hs), hTable(hs){}

//Destructor
HT::~HT() {
	for (unsigned i = 0; i < hTable.size(); i++) {
		hTable[i].clear();
	}
	hTable.clear();
	pTable.clear();
}


/*
Inserts the record of the item e:(key, desc, num) in the hash table.
If the key already exists in the table, then the function prints an error message
*/
void HT::insert(const Entry &e) {
	int i = hash(e.key);

	list<Entry>& l = hTable[i];

	auto p = find_if(l.cbegin(), l.cend(), [e](const Entry& x) {
		return e.key == x.key;
	});
	
	if (p != l.cend())
	{
		cout << " not inserted - duplicate key!!!" << endl;
	}
	else
	{
		cout << " entry =  " << i << endl;
		l.push_front(e);
		pTable.push_back(&l.front());
	}
}

/*
Searches the hash table for a record with key
*/
void HT::search(const string & key) {
	auto i = hash(key);

	list < Entry >& l = hTable[i];

	auto p = find_if(l.cbegin(), l.cend(), [key](Entry x) { 
		return key == x.key;
	});
	
	if (p != l.cend())
	{
		cout << " ==> number: " << right << setw(4) << (*p).num << " - item:" << left << setw(24) << (*p).desc;
	}
	else
	{
		cout << " not in table!!";
	}
	cout << endl;
}

/*
Prints the subscript and the contents of all (and only) the active records in the hash table
*/
void HT::hTable_print() {
	
	for (unsigned i = 0; i < hTable.size(); i++)
	{
		for (auto a : hTable[i])
		{
			cout << endl;
			if(inc){
				cout << right << setw(4) << i << ":" << setw(5) << a.key << "  - " << setw(5) << a.num << "  -  " << left << setw(24) << a.desc;
			}
			else {
				cout << left << setw(4) << i << ":" << left << setw(5) << a.key << "  - " << setw(5) << a.num << "  -  " << left << setw(24) << a.desc;
			}
			
		}
		
	}
	cout << endl;
	inc = !inc;
}


/*
If key values of two entries, return smaller entry
*/
bool two(Entry* e1, Entry* e2)
{
	return e1->key < e2->key;
}


/*
Prints the contents of all (and only) the active records in the hash table
*/
void HT::pTable_print() {
	sort(pTable.begin(), pTable.end(), two);
		for (unsigned int i = 0; i < pTable.size(); i++)
		{
			cout << "   " << pTable[i]->key << "  -  " << right << setw(4) << pTable[i]->num << "  -  " << left << setw(24) << pTable[i]->desc << endl;
		}

}
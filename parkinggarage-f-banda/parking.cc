/* 	Francisco Banda (Z1912220)
	Parking Garage
	CSCI 340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include <string>
#include <iostream>
#include <deque> 
#include <stack>

using namespace std;

class car
{
public:
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the numbner of times the car has been moved.
    void move() { ++num_moves; }

    /// @return the number of times that the car has been moved.
    int get_num_moves() const { return num_moves; }

    /// @return A reference to the license for this car.
    const std::string &get_license() const { return license; }

    /// Overload the << so this can print itself.
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs)
    {
        lhs << "Car " << rhs.id << " with license plate \"" << rhs.license << "\"";
        return lhs;
    }

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};

class garage
{
public:
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.                                                           
        void arrival(const std::string &license);

        /// @param license The license of the car that has departed.                                                          
        void departure(const std::string &license);

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};

int cnt = 1;

/*
Function that extracts the individual components from the input line line,
 where act indicates if the line corresponds to an arrival or a departure event,
 and license is the license plate number of the arriving/departing car.
*/
void get_input_vals(const string &line, char &act, string &license) {
	
	// delim on ":"
	string delim = ":";

	// Substring from 0 to delim
	string actTwo = line.substr(0, line.find(delim));
	
	// Substring from delim+1 to next delim
	string templicense = line.substr(line.find(delim) + 1);

	// Delete
	templicense.pop_back();

	// Convert
	license = templicense;

	// Replace
	act = actTwo[0];
}

typedef struct
{
	int id; //Car ID
	string license; //License plate
	int num_moves; //Number of times a car has moved
}
PARKING_LOT;

void arrival(const PARKING_LOT &parking, deque<PARKING_LOT> &D) {

	cout << "Car " << parking.id << " with license plate " << "\"" << parking.license << "\"" << " has arrived." << endl;
	
	// Check if garage is full of cars (parking_lot_limit)
	if (D.size() < 10) {
		D.push_front(parking);
		cout << endl;
	}
	// Garage is full, and departure check is no longer necessary
	else
	{
		cout << "    But the garage is full!" << endl << endl;
	}
}

/*
Check each of the car elements in the parking_lot deque to see if any of them have the given license. If no such car is found then print a message stating that "the garage is full"
*/
void departure(const string &license, deque<PARKING_LOT> &D, stack<PARKING_LOT> &S) {

	int position = 0;
	bool exists = false;

	for (auto i : D) {
		// If license exists
		if (i.license == license) {
			exists = true;
			break;
		}
		// Increment position
		position++;
	}
	
	// If license doesn't exist, car was probably stolen
	if (exists == false) {
		cout << "No car with license plate " << "\"" << license << "\"" << " is in the garage." << endl << endl;
		return;
	}
	
	// Increment cars ahead
	for (unsigned int i = position; i < D.size(); i++) {
		D[i].num_moves++;
	}
	
	// Push cars into stack
	for (auto i : D) {
		S.push(i);
	}

	// Flush deque
	D.clear();
	
	// Re-add cars to deque
	while (!S.empty()) {
		D.push_front(S.top());
		S.pop();
	}

	cout << "Car " << D[position].id << " with license plate " << "\"" << D[position].license << "\"" << " has departed," << endl;
	if(D[position].num_moves == 1){
		cout << "    car was moved " << D[position].num_moves << " time in the garage." << endl << endl;
	}
	else{
		cout << "    car was moved " << D[position].num_moves << " times in the garage." << endl << endl;
	}
	
	// Remove from deque
	D.erase(D.begin() + position);

}

int main() {
	
	stack<PARKING_LOT> S;
	deque<PARKING_LOT> D;
	string line;
	string license;
	char actTwo;

	// Input
	while (getline(cin, line)) {
		
		get_input_vals(line, actTwo, license);
		
		// "'X': invalid action!" check
		if (actTwo != 'D' && actTwo != 'A') {
			cout << "'X': invalid action!" << endl << endl;
			continue;
		}

		PARKING_LOT arr;
		arr.id = cnt;

		// Declaration for car exists, initially not
		bool exists = false;
		
		// Check if license is in the garage, if so, break
		for(auto i:D) {
			if(i.license == license) {
				exists = true;
				break;
			}
		}
		
		// If the license does not exist, then increment ID and add
		if (exists == false) {
			cnt++;
		}

		arr.license = license;
		arr.num_moves = 0;
		
		// Arriving
		if (actTwo == 'A') {
			arrival(arr, D);
		}
		// Departing
		else {
			departure(arr.license, D, S);
		}

	}
}
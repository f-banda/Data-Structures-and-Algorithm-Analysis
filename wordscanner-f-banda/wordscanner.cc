/* 	Francisco Banda (Z1912220)
    WordScanner
    CSCI 340-3

    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;
const int NO_ITEMS = 4;
const int ITEM_W = 14;

//Declare map
typedef map<string, int>::const_iterator it_type;

//Character is alphanumeric
bool isChar(const char& c){
    return isalnum(c);
}

//Character is not alphanumeric
bool notChar(const char& c){
    return !isalnum(c);
}

//Convert character(c) to lowercase
void lower(char& c){
    c = tolower(c);
    return;
}

//Final list of words and their frequencies
//Also prints the number of nonempty words and 
//the number of distinct words in the input stream
void print_words(const map <string, int>& map){

    int number = 0;
    int counter = 0;

    //Iterate through map
    for(it_type it = map.begin(); it != map.end(); ++it)
    {
        //If NO_ITEMS is reached
        if (counter == NO_ITEMS)
        {
            //restart counter
            counter = 0;

            //New line
            cout << endl;
        }
        number += (*it).second;

        //Print
        cout << setw(ITEM_W) << left << (*it).first << ":" << setw(2) << (*it).second << " ";

        //Increment
        counter++;
    }
    //Nonempty/Distinct words
    cout << endl << endl;
    cout << "no of words in input stream   :" << number << endl;
    cout << "no of words in output stream  :" << map.size();
    cout << endl;
}

//Cleans a word from its punctuation marks,
//the first argument is the original word in
//the input stream and the second argument 
//contains the same word after cleaning
void clean_entry(const string& first, string& second)
{
    int front = 0;
    int back = 0;
    bool punctuation = false, start = false, end = false;

    for (int count = 0; count < (int)first.length(); count++){
        if (notChar(first[count])){
            punctuation = true;
        }
 
        if (isChar(first[count]) && start == false){
            start = true;
            front = count;
        }
        
        if (start == true){
            if (notChar(first[count])){
                end = true;
                back = count;
            }
        }

        if (end == true){
            break;
        }
    }
    //Apply fixes to word2
    second = first.substr(front, back - front);

    //Convert to lowercase
    for_each(second.begin(), second.end(), lower);

    //If no punch, then just set equal to
    if (punctuation == false){
        second = first;

        //But still convert to lowercase
        for_each(second.begin(), second.end(), lower);
    }
}

//Gets a word from the input stream and removes its
//punctuation marks also calls the clean_entry function
//to clean the words then updates the map
void get_words(map<string, int>& map, ifstream& input)
{
    string processing, word;

    //While words are still processing
    while (input >> processing)
    {
        //Continue with processing the word
        clean_entry(processing, word);

        //Adjust map
        if (word.length() > 0){
            map[word]++;
        }
    }
    //End of file reached
    if (input.eof()){
        return;
    }
}

int main()
{
    //Input stream
    ifstream input("wordscanner.in");

    //Declare map
    map<string, int> m;

    //Calls get_words, which internally cleans words
    get_words(m, input);

    //End stream
    input.close();

    //Print contents
    print_words(m);

    return 0;

}
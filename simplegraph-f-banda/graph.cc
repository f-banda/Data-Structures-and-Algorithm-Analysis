/* 	Francisco Banda (Z1912220)
    Simple Graph
    CSCI 340-3
    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#include "graph.h"

using namespace std;

Graph::Graph(const char* filename){
	ifstream input;
    input.open(filename);

    input >> size;
    char prev[100];
    input.getline(prev, 1);
    input.getline(prev, 100);
    {
        string line(prev);
        string::iterator end = remove_if(line.begin(), line.end(), static_cast<int(*)(int)> (isspace));
        line.erase(end, line.end());
        for(size_t i = 0; i < line.size(); i++)
                labels.push_back('A' + i);
    }

    while(input){
        list<int> contents;

        input.getline(prev, 100);
        string line(prev);
		
        if(line.size() == 0){
			break;
		}
		
        line.erase(remove_if(line.begin(), line.end(), static_cast<int(*)(int)>(isspace)), line.end());
		
        for(size_t i = 1; i < line.size(); i++){
            if(line[i] == '1'){
            contents.push_back(i-1);
			}
        }
		
        adj_list.push_back(contents);
		
    }
	
}

int * num;
string s;

void Graph::Depthfirst(int v) 
{
	num[v]++;
	
	cout << labels[v] << " ";
	
	for(int i : adj_list[v])
		if(num[i] == 0){
			s = s + '(' + labels[v] + ',' + ' ' + labels[i] + ')' + ' ';
			Depthfirst(i);
		}
}

void Graph::Traverse() 
{
    s = "";
	
    cout << "\n------- traverse of graph ------" << endl;
	
    num = new int[size];
	
    for(int i = 0 ; i< size; i++){
            num[i] = 0;
	}

    for(int i = 0; i < size; i++)
            if(num[i] == 0){
                    Depthfirst(i);
			}
    cout << endl << s << endl;
	
    delete num;
	
    cout << "--------- end of traverse -------\n" << endl;
}

void Graph::Print() const 
{
    int i = 0;
	
    cout << "\nNumber of vertices in the graph: " << size << endl;
	
    cout << "\n-------- graph -------" << endl;
	
    for(list<int> l : adj_list){
            cout << (char) ('A' + i++) << ": ";
            for(int c : l)
                    cout << labels[c] << ", ";
            cout << endl;
    }
	
    cout << "------- end of graph ------" << endl;
}

Graph::~Graph()
{

}

int Graph::Getsize() const 
{ 
  return size;
}
#include<iostream>
#include<fstream>

#include "auxillary.h"

using namespace std;

void get_code() {
	cout << "Enter the path to a file: \n";
	string fpath;
	getline(cin, fpath);

	ifstream file(fpath);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			width = line.length();
			height++;
			code += line;
		}
	} else {
		cerr << "!!ERROR: [" + fpath + "] could not be loaded!";
	}
}

int get_standing_instruction() {
	return code[y*width + x];
}

std::pair<int,int> get_ab(std::deque<int>* stack) {
	int a = stack->front();
	stack->pop_front();
	int b = stack->front();
	stack->pop_front();
	return std::make_pair(a, b); //first, second. So push the values backwards!
}

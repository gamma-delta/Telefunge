//Compiler

#include<iostream>

#include "auxillary.h"
#include "interpreter.h"

using namespace std;

extern string code = "";

extern deque<int> turtle_stack(STACK_SIZE, 0); //ALWAYS push pop to the front!
extern deque<int> aux_stack(STACK_SIZE, 0);

extern unsigned int width = 0;
extern unsigned int height = 0;

extern unsigned int x = 0;
extern unsigned int y = 0;
extern unsigned int d = UP;
extern int previous = '\0';
extern bool is_reading_text = false;
extern bool is_reading_ints = false;
extern bool is_hex_mode = true;
extern bool quit = false;

int main() {
	bool env_quit = false;
	while (!env_quit) {
		if ( interpret() ) {
			cout << endl << "Another file? [y/n] ";
			string str;
			getline(cin, str);
			if (str != "y") {
				cout << "Ending..." << endl;
				env_quit = true;
			}
		} else {
			return 1;
		}
	}

	return 0;
}

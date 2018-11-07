#include "interpreter.h"
#include "auxillary.h"
#include "turtle_control.h"

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

#include<cstdlib>
#include<ctime>

using namespace std;

bool interpret() {
	get_code();
	if (code.empty())
		return false;

	//init turtle position
	int turtle_start = code.find('@');
	x = turtle_start % width;
	y = turtle_start / width;

	//seed random
	srand(time(NULL));

	//the main loop!
	while (!quit) {
		//cout << x << ' ' << y << endl; //debug disp
		step();
		int instruction = get_standing_instruction();

		if (is_reading_text) { //I'm between two quotes
			if (instruction == '\\') { //ooh, special characters
				char special_char = '\0';
				bool is_special = true;
				switch (previous) {
				default:
					is_special = false;
					break;
				case 'n':
					special_char = '\n';
					break;
				case '"':
					special_char = '"';
					break;
				}
				if (is_special) {
					turtle_stack.pop_front();
					turtle_stack.push_front(special_char);
				} else
					turtle_stack.push_front(instruction);
			} else if (instruction == '"') //close
				is_reading_text = false;
			else turtle_stack.push_front(instruction);
		} else if (is_reading_ints) {
			if (instruction == '#')
				is_reading_ints = false;
			else
				turtle_stack.push_front(strtol((char*) &instruction, NULL, 16));
		} else { //normal commands
			switch (instruction) {
			default:
				//do nothing
				break;
				//TURNING
			case '.':
				quit = true;
				break;
			case '^':
				d = UP;
				break;
			case '>':
				d = RIGHT;
				break;
			case 'V':
				d = DOWN;
				break;
			case '<':
				d = LEFT;
				break;
			case '|':
				if (turtle_stack.front())
					d = UP;
				else
					d = DOWN;
				break;
			case '_':
				if (turtle_stack.front())
					d = LEFT;
				else
					d = RIGHT;
				break;
			case '?':
				d = rand() % 4; //I'm too lazy to do it properly
				break;
				//IO
			case '"':
				is_reading_text = true;
				break;
			case '#':
				is_reading_ints = true;
				break;
			case '$': {
				string input;
				getline(cin, input);
				reverse(input.begin(), input.end());
				for (auto c: input) if (c != '\0') turtle_stack.push_front(c);
				break;
			}

			case ':':
				cout << (char) turtle_stack.front();
				turtle_stack.pop_front();
				break;
			case ';':
				if (is_hex_mode)
					cout << hex << uppercase << turtle_stack.front();
				else
					cout << dec << nouppercase << turtle_stack.front();
				turtle_stack.pop_front();
				break;
				//MATH
			case '+': { //the worst c++ ever probably right here.
				pair<int, int> ab = get_ab(&turtle_stack);
				turtle_stack.push_front(ab.first + ab.second);
				break;
			}
			case '-': {
				pair<int, int> ab = get_ab(&turtle_stack);
				turtle_stack.push_front(ab.first - ab.second);
				break;
			}
			case '*': {
				pair<int, int> ab = get_ab(&turtle_stack);
				turtle_stack.push_front(ab.first * ab.second);
				break;
			}
			case '/': {
				pair<int, int> ab = get_ab(&turtle_stack);
				turtle_stack.push_front(ab.first / ab.second); //auto-flooring!
				break;
			}
			case '%': {
				pair<int, int> ab = get_ab(&turtle_stack);
				turtle_stack.push_front(ab.first % ab.second);
				break;
			}
			case 'R':
				turtle_stack.front()++;
			break;
			case 'L':
				turtle_stack.front()--;
			break;
			//POPPING AND SWAPPING
			case 'P':
				turtle_stack.pop_front();
			break;
			case 'p':
				aux_stack.pop_front();
			break;
			case 'S':
				aux_stack.push_front(turtle_stack.front());
				turtle_stack.pop_front();
			break;
			case 's':
				turtle_stack.push_front(aux_stack.front());
				aux_stack.pop_front();
			break;
			case 'C':
				aux_stack.push_front(turtle_stack.front());
			break;
			case 'c':
				turtle_stack.push_front(aux_stack.front());
			break;
			case 'W': {
				int temp = turtle_stack.front();
				turtle_stack.pop_front();
				turtle_stack.push_front(aux_stack.front());
				aux_stack.pop_front();
				aux_stack.push_front(temp);
				break;
			}
			//TELEPORTING
			case 'T': {
				pair<int, int> ab = get_ab(&turtle_stack);
				x = ab.first;
				y = ab.second;
				break;
			}
			case 't': {
				pair<int, int> ab = get_ab(&aux_stack);
				x = ab.first;
				y = ab.second;
				break;
			}
			case 'X':
				is_hex_mode = true;
			break;
			case 'x':
				is_hex_mode = false;
			break;

			//the debug one
			case '~':
				for (auto c : turtle_stack) {
					cout << c;
				}
				cout << endl;
			break;
			}
		}
		x %= width;
		y %= height;
		previous = instruction;
	}
	return true;
}

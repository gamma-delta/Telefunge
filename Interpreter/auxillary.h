#ifndef AUXILLARY_H//probably not required but
#define AUXILLARY_H //still good practice

#include<deque>
#include<vector>
#include<string>
#include<utility>

const unsigned int STACK_SIZE = 1000; //make infinite for turing-completeness

extern std::string code;

//2 stacks initialized to a lot of 0
extern std::deque<int> turtle_stack;
extern std::deque<int> aux_stack;

enum directions {
	UP = 0,
	LEFT,
	RIGHT,
	DOWN
};

extern unsigned int width;
extern unsigned int height;

extern unsigned int x;
extern unsigned int y;
extern unsigned int d; //direction
extern int previous; //the previous char. Useful for newlines
extern bool is_reading_text;
extern bool is_reading_ints;
extern bool is_hex_mode;
extern bool quit; //becomes true upon finding .


void get_code(); //returns the code, nicely formatted
int get_standing_instruction();
std::pair<int,int> get_ab(std::deque<int>* stack);

#endif

#include "turtle_control.h"
#include "auxillary.h"

void step() {
	switch (d) {
	case UP:
		y--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	}
	x %= width;
	y %= height;
}

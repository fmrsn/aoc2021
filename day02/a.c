#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

int
main(void)
{
	int position = 0;
	int depth = 0;
	char command;
	int units;
	while (scanf(" %c%*s %d", &command, &units) != EOF) {
		switch (command) {
		case 'f': // forward
			position += units;
			break;
		case 'd': // down
			depth += units;
			break;
		case 'u': // up
			depth -= units;
			break;
		default:
			die("%c: unrecognized command\n", command);
		}
	}
	printf("%d\n", position * depth);
}

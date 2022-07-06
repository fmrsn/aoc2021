#include "../common.h"

int
main(void)
{
	int position = 0;
	int depth = 0;
	int aim = 0;
	char command;
	int units;
	while (scanf(" %c%*s %d", &command, &units) != EOF) {
		switch (command) {
		case 'f': // forward
			position += units;
			depth += aim * units;
			break;
		case 'd': // down
			aim += units;
			break;
		case 'u': // up
			aim -= units;
			break;
		default:
			die("%c: unrecognized command\n", command);
		}
	}
	printf("%d\n", position * depth);
}

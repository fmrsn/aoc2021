#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

int
main(void)
{
	int window[3];
	if (scanf("%d %d %d", &window[0], &window[1], &window[2]) == EOF) {
		die("malformed input\n");
	}
	int prev = window[0] + window[1] + window[2];
	int count = 0;
	int i = 0;
	while (scanf("%d", &window[i]) != EOF) {
		int next = window[0] + window[1] + window[2];
		count += (next > prev) != 0;
		prev = next;
		i = (i + 1) % 3;
	}
	printf("%d\n", count);
}

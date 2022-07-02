#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

int
main(void)
{
	int prev;
	if (scanf("%d", &prev) == EOF) {
		die("malformed input\n");
	}
	int next;
	int count = 0;
	while (scanf("%d", &next) != EOF) {
		count += (next > prev);
		prev = next;
	}
	printf("%d\n", count);
}

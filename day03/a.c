#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
	unsigned gamma, epsilon;
	char buf[sizeof gamma * CHAR_BIT] = {0};
	int count[sizeof buf] = {0};
	int threshold = 0;

	while (scanf(" %s", buf) != EOF) {
		size_t i = 0;
		char *s = buf;
		while (*s != '\0') {
			count[i++] += (*s++ == '1');
		}
		++threshold;
	}
	threshold /= 2;

	gamma = 0;
	size_t len = strlen(buf);
	for (size_t i = 0; i < len; ++i) {
		gamma |= ((count[i] > threshold) != 0) << (len - i - 1);
	}
	epsilon = (~gamma) & ((1u << len) - 1u);

	printf("%u\n", gamma * epsilon);
}

#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common.h"

#define bit_set(n, i) ((n) & (1 << (i)))

static int
compare(const void *a, const void *b)
{
	return (*(unsigned short *)a - *(unsigned short *)b);
}

static unsigned
find_rating(unsigned short *nums, size_t nums_count, size_t pattern_len, int criterium)
{
	size_t shift = criterium ? 1 : 0;
	size_t begin = 0;
	size_t end = nums_count - 1;
	size_t *e1 = criterium ? &begin : &end;
	size_t *e2 = criterium ? &end : &begin;
	size_t i = pattern_len;
	while (begin < end && i-- > 0) {
		size_t c = begin + (end - begin + 1) / 2;
		if (bit_set(nums[c], i)) {
			// 1 is most common
			while (c-- > begin && bit_set(nums[c], i)) {
				continue;
			}
			*e1 = c + shift;
		} else {
			// 0 is most common
			while (c++ < end && !bit_set(nums[c], i)) {
				continue;
			}
			*e2 = c - shift;
		}
	}
	return nums[begin];
}

int
main(void)
{
	unsigned short nums[1024];
	unsigned short *n = nums;

	char buf[64];
	while (scanf(" %s", buf) != EOF) {
		if (n >= nums + array_size(nums)) {
			die("didn't expect more than %zu numbers\n", array_size(nums));
		}
		char *end;
		errno = 0;
		*n++ = strtoul(buf, &end, 2);
		if (errno != 0 || *end != '\0') {
			die("%s: not a binary number\n", buf);
		}
	}
	size_t nums_count = n - nums;
	if (nums_count == 0) {
		die("expected some input\n");
	}

	qsort(nums, nums_count, sizeof(nums[0]), compare);
	size_t pattern_len = strlen(buf);
	unsigned o = find_rating(nums, nums_count, pattern_len, 1);
	unsigned co2 = find_rating(nums, nums_count, pattern_len, 0);

	printf("%u\n", o * co2);
}

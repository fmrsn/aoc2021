#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size(a) (sizeof (a) / sizeof (a)[0])

static inline void
die(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}

static inline int
must_strtol(const char *s, int base)
{
	char *end;
	errno = 0;
	long l = strtol(s, &end, base);
	if (errno != 0) {
		die("%s: %s\n", s, strerror(errno));
	} else if (*end != '\0') {
		die("%s: not a number\n", s);
	}
	return l;
}


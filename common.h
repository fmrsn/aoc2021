#define array_size(a) (sizeof (a) / sizeof (a)[0])

static inline void
die(char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}

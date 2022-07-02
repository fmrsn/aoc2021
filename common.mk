CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -O -g
LDFLAGS =

TARGETS = a b

all: $(TARGETS)

check: FORCE $(TARGETS)
	@for x in $(TARGETS); do printf %s "$$x: "; ./$$x <input; done

.SUFFIXES:
.SUFFIXES: .c
.c:
	@$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean: FORCE
	@rm -f $(TARGETS)

FORCE: ;

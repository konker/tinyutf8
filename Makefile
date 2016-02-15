CC = gcc
CFLAGS = -Wall -g -fno-builtin -fsigned-char
EXTRA_FLAGS = -L. -ltinyutf8
utilObjs = tinyutf8.o

example: example.c libtinyutf8.a
	$(CC) $(CFLAGS) -o $@ $< $(EXTRA_FLAGS)

libtinyutf8.a: $(utilObjs)
	ar rc $@ $(utilObjs)
	ranlib $@

$(utilObjs): tinyutf8.c tinyutf8.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o libtinyutf8.a example

all: example
.PHONY: all clean

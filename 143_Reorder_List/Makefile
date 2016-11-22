CC = gcc
CFLAGS = -O0 -Wall -std=gnu99

EXEC = leetcode
SRC_FILES = main.c function.c

all: $(EXEC)

leetcode: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

debug: $(SRC_FILES)
	$(CC) $(CFLAGS) -DDEBUG -o $(EXEC)_$@ $^

run: $(EXEC)
	./leetcode

clean:
	$(RM) $(EXEC) $(EXEC)_debug *.o

.PHONY: debug run clean

CC = gcc
CFLAGS = -O0 -Wall -std=gnu99

EXEC = leetcode
SRC_FILES = main.c function.c

all: $(EXEC)

leetcode: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

recusive: main.c function.recusive.c
	$(CC) $(CFLAGS) -o leetcode $^


debug: $(SRC_FILES)
	$(CC) $(CFLAGS) -DDEBUG -o $(EXEC)_$@ $^

run: $(EXEC)
	for i in `seq 0 1 44`; do echo -n "[$$i] "; ./leetcode $$i; done

clean:
	$(RM) $(EXEC) $(EXEC)_debug *.o

.PHONY: debug clean

CC = gcc
CFLAGS = -O0 -Wall -std=gnu99

EXEC = comLongPrefix
SRC_FILES = main.c function.c

all: $(EXEC)

comLongPrefix: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

debug: $(SRC_FILES)
	$(CC) $(CFLAGS) -DDEBUG -o $(EXEC)_$@ $^

clean:
	$(RM) $(EXEC) $(EXEC)_debug *.o

.PHONY: debug clean

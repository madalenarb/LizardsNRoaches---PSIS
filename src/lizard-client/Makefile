CC = gcc
CFLAGS = -g -Wall -std=c99
LIBS = -lzmq -lncurses

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

TARGET = lizard-client

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: $(SRC_DIR)/%.c	
	$(CC) $(CFLAGS) -c -o $@ $<

clean:	
	rm -f $(TARGET) $(OBJ_FILES)
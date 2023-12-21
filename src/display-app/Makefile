SRC_FILES = $(wildcard *.c ../../common/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
LDFLAGS = -lzmq

TARGET = display-app

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
    $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c	
    $(CC) $(CFLAGS) -c -o $@ $<

clean:	
    rm -f $(TARGET) $(OBJ_FILES)
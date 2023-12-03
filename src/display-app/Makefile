include ../../common/common.mk


SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

TARGET = display-app

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: $(SRC_DIR)/%.c	
	$(CC) $(CFLAGS) -c -o $@ $<

clean:	
	rm -f $(TARGET) $(OBJ_FILES)
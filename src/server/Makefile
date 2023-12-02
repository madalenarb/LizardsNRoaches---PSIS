CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -pedantic -std=c99 -g -lzmq -lncurses

all: lizardsNroaches-server


lizardsNroaches-server: lizardsNroaches-server.c
	$(CC) lizardsNroaches-server.c server_funcs.c -o lizardsNroaches-server $(CFLAGS)
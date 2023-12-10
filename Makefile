# LizardsNRoaches/Makefile

all: protocol server lizard-client roach-client 

protocol:
	@$(MAKE) -C common

server: 
	@$(MAKE) -C src/server

lizard-client:
	@$(MAKE) -C src/lizard-client 

roach-client:
	@$(MAKE) -C src/roaches-client

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes all

getPid:
	lsof -i :5555


clean:
	@$(MAKE) -C common clean
	@$(MAKE) -C src/server clean
	@$(MAKE) -C src/lizard-client clean
	@$(MAKE) -C src/roaches-client clean
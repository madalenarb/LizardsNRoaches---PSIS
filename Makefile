# LizardsNRoaches/Makefile

all: server lizard-client roach-client 

server: 
	@$(MAKE) -C src/server

lizard-client:
	@$(MAKE) -C src/lizard-client

roach-client:
	@$(MAKE) -C src/roaches-client

clean:


clean:
	@$(MAKE) -C src/server clean
	@$(MAKE) -C src/lizard-client clean
	@$(MAKE) -C src/roaches-client clean
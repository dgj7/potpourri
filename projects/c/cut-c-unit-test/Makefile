# compile
CC = gcc
CFLAGS = -Wall -g

# targets
BUILDDIR = target
PROGRAM = $(BUILDDIR)/main.exe
MAINSRC := $(shell find src -name "*.c")

build: $(PROGRAM)

$(PROGRAM): $(MAINSRC)
	@echo -n compiling $^ $@ ...
	@$(CC) $(CFLAGS) -o $@ $^ && echo done!

clean:
	@echo -n cleaning...
	@rm -rf $(PROGRAM)
	@echo done!

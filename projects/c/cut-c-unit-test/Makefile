# compile
CC = gcc
CFLAGS = -Wall -g

# targets
BUILDDIR := target
PROGRAM  := $(BUILDDIR)/main.exe
LIBSRC   := $(filter-out src/main.c, $(shell find src -name "*.c"))
MAINSRC  := $(shell find src -name "*.c")
TEST     := $(BUILDDIR)/test.exe
TESTSRC  := $(LIBSRC) $(shell find test -name "*.c")

build: $(PROGRAM)

test: $(TEST)

$(TEST): $(TESTSRC)
	@echo -n compiling tests $^ $@ ...
	@$(CC) $(CFLAGS) -o $@ $^ && echo done!
	@test.exe

$(PROGRAM): $(MAINSRC)
	@echo -n compiling $^ $@ ...
	@$(CC) $(CFLAGS) -o $@ $^ && echo done!

clean:
	@echo -n cleaning...
	@rm -rf $(PROGRAM)
	@rm -rf $(TEST)
	@echo done!

print:
	@echo BUILDDIR: $(BUILDDIR)
	@echo PROGRAM: $(PROGRAM)
	@echo MAINSRC: $(MAINSRC)
	@echo LIBSRC: $(LIBSRC)
	@echo TEST: $(TEST)
	@echo TESTSRC: $(TESTSRC)

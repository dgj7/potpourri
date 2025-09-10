# compile
CC = gcc
CFLAGS = -Wall -g

# variables
BUILDDIR := target
PROGRAM  := $(BUILDDIR)/main.exe
LIBSRC   := $(filter-out src/main.c, $(shell find src -name "*.c"))
MAINSRC  := $(shell find src -name "*.c")
TEST     := $(BUILDDIR)/test.exe
TESTSRC  := $(LIBSRC) $(shell find test -name "*.c")

# 'build' target
build: $(PROGRAM)

# 'test' target
test: $(TEST)

# build and run the test program; exits if any tests fail
$(TEST): $(TESTSRC)
	@echo -n compiling tests $^ $@ ...
	@$(CC) $(CFLAGS) -o $@ $^ && echo done!
	@$(TEST)

# build the main program
$(PROGRAM): $(MAINSRC)
	@echo -n compiling $^ $@ ...
	@$(CC) $(CFLAGS) -o $@ $^ && echo done!

# 'clean' target
clean:
	@echo -n cleaning...
	@rm -rf $(PROGRAM)
	@rm -rf $(TEST)
	@echo done!

# 'print' target; meant for debugging/understanding
print:
	@echo BUILDDIR: $(BUILDDIR)
	@echo PROGRAM: $(PROGRAM)
	@echo MAINSRC: $(MAINSRC)
	@echo LIBSRC: $(LIBSRC)
	@echo TEST: $(TEST)
	@echo TESTSRC: $(TESTSRC)

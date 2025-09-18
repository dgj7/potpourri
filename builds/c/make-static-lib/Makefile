# compile
CC = gcc
CFLAGS = -Wall -g

# build variables
LIBSRCDIR:= src
LIBSRC   := $(shell find src -name "*.c")
LIBOBJS  := $(patsubst %.c,target/%.o,$(notdir $(LIBSRC)))
TESTSRC  := $(LIBSRC) $(shell find test -name "*.c")
DEMOSRC  := $(shell find examples -name "*.c")
DEMONAMES:= $(notdir $(basename $(DEMOSRC)))
DEMOPROGS:= $(patsubst %,target/%.exe,$(DEMONAMES))
BUILDDIR := target
LIBNAME  := addition
LIBRARY  := $(BUILDDIR)/lib$(LIBNAME).a
TEST     := $(BUILDDIR)/test.exe

# tasks that aren't files
.PHONY: all build test clean print

# 'all' tasks
all: clean test build

# 'build' task
build: $(LIBOBJS) $(LIBRARY) $(DEMOPROGS)

# 'test' task
test: $(TEST)

# build and run the test program; exits if any tests fail
$(TEST): $(TESTSRC)
	@echo -n compiling: $@ [$^] ...
	@$(CC) $(CFLAGS) -o $@ $^ -I $(LIBSRCDIR) && echo done!
	@$(TEST)

# build object files
$(LIBOBJS): $(LIBSRC)
	@echo -n compiling: $@ ...
	@$(CC) $(CFLAGS) -c $< -o $@ && echo done!

# build the library
$(LIBRARY): $(LIBOBJS)
	@echo -n compiling: $@ [$^] ...
	@ar rcs $@ $^ && echo done!

# build the demos
$(DEMOPROGS): $(DEMOSRC)
	@echo compiling: $@ [examples/$(notdir $(basename $@)).c] ...
	@$(CC) -o $@ -I $(LIBSRCDIR) examples/$(notdir $(basename $@)).c -L$(BUILDDIR) -l$(LIBNAME)

# 'clean' task
clean:
	@echo -n cleaning...
	@rm -rf $(LIBRARY)
	@rm -rf $(TEST)
	@rm -rf $(LIBOBJS)
	@rm -rf $(DEMOPROGS)
	@echo done!
	@echo -n creating target directory ...
	@mkdir -p target && echo done!

# 'print' task; meant for debugging/understanding
print:
	@echo BUILDDIR:  $(BUILDDIR)
	@echo LIBSRCDIR: $(LIBSRCDIR)
	@echo LIBNAME:   $(LIBNAME)
	@echo LIBRARY:   $(LIBRARY)
	@echo LIBSRC:    $(LIBSRC)
	@echo LIBOBJS:   $(LIBOBJS)
	@echo DEMOSRC:   $(DEMOSRC)
	@echo DEMONAMES: $(DEMONAMES)
	@echo DEMOPROGS: $(DEMOPROGS)
	@echo TEST:      $(TEST)
	@echo TESTSRC:   $(TESTSRC)
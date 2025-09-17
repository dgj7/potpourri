# compile
CC = gcc
CFLAGS = -Wall -g

# build variables
MAINSRC  := $(shell find src -name "*.c")
BUILDDIR := target
PROGRAM  := $(BUILDDIR)/main.exe
HEADER   := src/version.h

# versioning
MAJOR    := 0
MINOR    := 0
PATCH    := 1
GITHASH  := $(shell git rev-parse HEAD)
VERSION  := $(MAJOR).$(MINOR).$(PATCH).$(GITHASH)

# tasks that aren't files
.PHONY: vh build clean print

# 'build' task
build: $(PROGRAM)

# 'vh' task, creates version header
vh: $(HEADER)

# build the main program
$(PROGRAM): $(MAINSRC) $(HEADER)
	@echo -n creating target directory ...
	@mkdir -p target && echo done!
	@echo -n compiling main: $^ $@ ...
	@$(CC) $(CFLAGS) -o $@ $^ && echo done!

# create version header file
$(HEADER):
	@echo -n creating version header file ...
	@echo '#ifndef VERSION__HEADER__DG__H__' > $(HEADER)
	@echo '#define VERSION__HEADER__DG__H__' >> $(HEADER)
	@echo '#ifdef __cplusplus' >> $(HEADER)
	@echo 'extern "C" {' >> $(HEADER)
	@echo '#endif' >> $(HEADER)
	@echo '' >> $(HEADER)
	@echo '#define VERSION "$(VERSION)"' >> $(HEADER)
	@echo '' >> $(HEADER)
	@echo '#ifdef __cplusplus' >> $(HEADER)
	@echo '}' >> $(HEADER)
	@echo '#endif' >> $(HEADER)
	@echo '#endif' >> $(HEADER)
	@echo done!

# 'clean' task
clean:
	@echo -n cleaning...
	@rm -rf $(PROGRAM)
	@rm -rf $(HEADER)
	@echo done!

# 'print' task; meant for debugging/understanding
print:
	@echo BUILDDIR: $(BUILDDIR)
	@echo PROGRAM: $(PROGRAM)
	@echo MAINSRC: $(MAINSRC)
	@echo MAJOR: $(MAJOR)
	@echo MINOR: $(MINOR)
	@echo PATCH: $(PATCH)
	@echo GITHASH: [$(GITHASH)]
	@echo VERSION: [$(VERSION)]
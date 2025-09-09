CC = gcc
CFLAGS = -Wall -g
BUILDDIR = target
OBJDIR = $(BUILDDIR)/obj
TARGET = $(BUILDDIR)/cut.exe
SOURCES := $(shell find src -name "*.c")
OBJECTS := $(SOURCES:%.c=$(OBJDIR)/%.o)

build: $(TARGET)

$(TARGET): $(SOURCES)
	@echo compiling $^...
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo -n cleaning...
	@rm -rf $(OBJDIR)
	@rm -rf $(TARGET)
	@echo done!

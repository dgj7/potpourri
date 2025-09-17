# variables
SOURCES := $(shell find src -name "*.src")
TESTS := $(shell find test -name "*.src")
TESTPROGRAM := target/testprogram.x
TESTIND := target/tests.ind
PROGRAM := target/program.x

# default run
.PHONY: all clean
all: clean $(TESTPROGRAM) $(TESTIND) $(PROGRAM) $(PROGRAM)

# compile the test sources
$(TESTPROGRAM): $(TESTS)
	@echo -n "compiling tests [$(TESTS)]..."
	@mkdir -p target
	@echo "nothing" > $(TESTPROGRAM)
	@echo success!

$(TESTIND): $(TESTPROGRAM)
	@echo -n running tests...
	@echo "nothing" > $(TESTIND)
	@echo success!

# compile the main program
$(PROGRAM): $(TESTIND) $(SOURCES)
	@echo -n "compiling sources [$(SOURCES)]..."
	@mkdir -p target
	@echo "nothing" > $(PROGRAM)
	@echo success!

# cleanup
clean:
	@echo -n "cleaning..."
	@rm -rf target/*
	@echo "done!"

# Comprehensive Makefile for CS162
# This will automatically compile any .cpp files in the current directory.
# Some of the syntax was adapted from:
# https://gist.github.com/Wenchy/64db1636845a3da0c4c7
# http://nuclear.mutantstargoat.com/articles/make/

CC = g++
CFLAGS = -std=c++11

exe_file = output
TAR_NAME = assignment4

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g -Wall
else
	CFLAGS += -DNDEBUG -O3
endif

SRCDIR = .
SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS = $(SOURCES:.cpp=.o)
DEP = $(OBJECTS:.o=.d)

$(exe_file): $(OBJECTS)
	$(CC) $^ -o $(exe_file)

-include $(DEP)

%.d: %.$(SRCEXT)
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.out *.o *.d $(exe_file)

tar:
	tar -cvf $(TAR_NAME).tar Makefile *.cpp *.hpp *.txt

.PHONY: clean
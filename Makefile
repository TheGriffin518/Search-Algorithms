CC=g++
DEBUG= -g -O0 -pedantic-errors
CFLAGS= -Wall -std=c++11 $(DEBUG)
LFLAGS= -Wall $(DEBUG)
COMPILE=$(CC) $(CFLAGS) -c
LINK= $(CC) $(LFLAGS)
RM=rm -f

.PHONY: clean all

all: driver

driver.o:driver.cpp
	$(COMPILE) driver.cpp

driver:driver.o
	$(LINK) -o driver driver.o

clean:
	rm -f driver
	rm -f driver.o
	rm -f Results.txt
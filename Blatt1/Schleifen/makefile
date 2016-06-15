all: Aufgabe_01_2a.out Aufgabe_01_2b.out Aufgabe_01_2c.out

projname = Aufgabe_01_2 
compile = g++

CPP_FILES := $(wildcard ./*.cpp)
CC_FLAGS := -O3 -Wall

Aufgabe_01_2a.out: Aufgabe_01_2a.cpp
	$(compile) $(CC_FLAGS) $^ -o $@

Aufgabe_01_2b.out: Aufgabe_01_2b.cpp
	$(compile) $(CC_FLAGS) $^ -o $@

Aufgabe_01_2c.out: Aufgabe_01_2c.cpp
	$(compile) $(CC_FLAGS) $^ -o $@

clean:
	rm -f Aufgabe_01_2*.out

all: Aufgabe_01_3a.out Aufgabe_01_3b.out 

projname = Aufgabe_01_3
compile = g++

CPP_FILES := $(wildcard ./*.cpp)
CC_FLAGS := -O3 -Wall

Aufgabe_01_3a.out: Aufgabe_01_3a.cpp
	$(compile) $(CC_FLAGS) $^ -o $@

Aufgabe_01_3b.out: Aufgabe_01_3b.cpp arrayMagic.cpp
	$(compile) $(CC_FLAGS) $^ -o $@

clean:
	rm -f Aufgabe_01_3*.out

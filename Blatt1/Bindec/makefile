all: main

projname = bindec.out
compile = g++

CPP_FILES := $(wildcard ./*.cpp)
CC_FLAGS := -O3 -Wall

main: $(CPP_FILES)
	$(compile) $(CC_FLAGS) $(CPP_FILES) -o $(projname)

clean: 
	rm -f $(projname)

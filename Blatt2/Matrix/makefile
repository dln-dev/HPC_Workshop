all: main

projname = matrix.out
compile = icpc 

CPP_FILES := $(wildcard ./*/*.cpp)
CC_FLAGS  := -O3 -std=c++11 -wd3802 -Wall -DMKL_LP64 -mkl=sequential
PROF_FLAGS := $(CC_FLAGS) -fargument-noalias -fno-inline -pg -g
L_FLAGS   := -lmkl_lapack95_lp64

main: $(CPP_FILES)
	$(compile) $(CC_FLAGS) $(L_FLAGS) $(CPP_FILES) -o $(projname)

profile:
	$(compile) $(PROF_FLAGS) $(L_FLAGS) $(CPP_FILES) -o $(projname)

clean:
	rm -f $(projname)

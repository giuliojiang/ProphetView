CXXFLAGS = -std=c++11 -Werror -Wall -pedantic -O3 -g -I src/
CXX = g++
CC = g++

# .............................................................................
# globals

all: testsuite-all


# .............................................................................
# testsuite executables

testsuite-all: src/testsuite/vec3test

src/testsuite/vec3test: src/testsuite/vec3test.o


# .............................................................................
# testsuite objects

src/testsuite/vec3test.o: src/geometry/vec3.h src/testsuite/testutils.h

# .............................................................................
# objects


# .............................................................................
# clean

clean:
	find . -name "*.o" -type f -delete
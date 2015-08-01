CXXFLAGS = -std=c++11 -Werror -Wall -pedantic -O3 -g -I src/
CXX = g++
CC = g++

# .............................................................................
# globals

all: testsuite-all


# .............................................................................
# testsuite executables

testsuite-all: src/testsuite/vec3test src/testsuite/spheretest

src/testsuite/vec3test: src/testsuite/vec3test.o

src/testsuite/spheretest: src/testsuite/spheretest.o src/mesh/sphere.o


# .............................................................................
# testsuite objects

src/testsuite/vec3test.o: src/geometry/vec3.hpp src/testsuite/testutils.hpp

src/testsuite/spheretest.o: src/geometry/vec3.hpp src/testsuite/testutils.hpp \
	src/mesh/sphere.o

# .............................................................................
# objects

src/mesh/sphere.o: src/geometry/vec3.hpp src/mesh/sphere.hpp


# .............................................................................
# clean

clean:
	find . -name "*.o" -type f -delete
	rm src/testsuite/vec3test
	rm src/testsuite/spheretest
CXXFLAGS = -std=c++11 -Werror -Wall -pedantic -O3 -g -I src/
CXX = g++
CC = g++

OBJECTS= src/mesh/sphere.o src/integrator/directspheres.o \
	src/camera/cameraPerspective.o src/geometry/vec3.o

# .............................................................................
# globals

all: testsuite-all

# .............................................................................
# testsuite executables

testsuite-all: src/testsuite/vec3test src/testsuite/spheretest \
	src/testsuite/spheresRenderMain \
	src/testsuite/cameraPerspectiveTest

src/testsuite/vec3test: src/testsuite/vec3test.cpp $(OBJECTS)

src/testsuite/spheretest: src/testsuite/spheretest.cpp src/geometry/vec3.hpp \
	src/mesh/sphere.hpp src/testsuite/testutils.hpp $(OBJECTS)

src/testsuite/spheresRenderMain: src/testsuite/spheresRenderMain.cpp $(OBJECTS)

src/testsuite/cameraPerspectiveTest: src/testsuite/cameraPerspectiveTest.cpp $(OBJECTS)

# .............................................................................
# objects

src/geometry/vec3.o: src/geometry/vec3.hpp src/geometry/vec3.cpp

src/mesh/sphere.o: src/geometry/vec3.hpp src/mesh/sphere.hpp

src/integrator/directspheres.o: src/geometry/vec3.hpp \
	src/mesh/sphere.hpp \
	src/integrator/directspheres.hpp

src/camera/cameraPerspective.o: src/camera/cameraPerspective.hpp

# .............................................................................
# clean

clean:
	- find . -name "*.o" -type f -delete
	- rm src/testsuite/vec3test
	- rm src/testsuite/spheretest
	- rm src/testsuite/spheresRenderMain
	- rm src/testsuite/untitled.ppm untitled.ppm
	- rm src/testsuite/cameraPerspectiveTest

# .............................................................................
# tests

test: testsuite-all
	./src/testsuite/vec3test && echo
	./src/testsuite/spheretest && echo
	./src/testsuite/cameraPerspectiveTest && echo
	./src/testsuite/spheresRenderMain && echo

.PHONY: clean test
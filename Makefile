CXXFLAGS = -std=c++11 -Werror -Wall -pedantic -O3 -g -I src/
CXX = g++
CC = g++

# .............................................................................
# globals

all: testsuite-all


# .............................................................................
# testsuite executables

testsuite-all: src/testsuite/vec3test src/testsuite/spheretest \
	src/testsuite/spheresRenderMain \
	src/testsuite/cameraPerspectiveTest

src/testsuite/vec3test: src/testsuite/vec3test.o

src/testsuite/spheretest: src/testsuite/spheretest.o src/mesh/sphere.o

src/testsuite/spheresRenderMain: src/mesh/sphere.o \
	src/integrator/directspheres.o \
	src/testsuite/spheresRenderMain.o

src/testsuite/cameraPerspectiveTest: src/camera/cameraPerspective.o src/testsuite/cameraPerspectiveTest.o

# .............................................................................
# testsuite objects

src/testsuite/vec3test.o: src/geometry/vec3.hpp src/testsuite/testutils.hpp

src/testsuite/spheretest.o: src/geometry/vec3.hpp \
	src/testsuite/testutils.hpp \
	src/mesh/sphere.o

src/testsuite/spheresRenderMain.o: src/geometry/vec3.hpp \
	src/mesh/sphere.hpp \
	src/testsuite/testutils.hpp\
	src/integrator/directspheres.hpp

src/testsuite/cameraPerspectiveTest.o: src/camera/cameraPerspective.hpp

# .............................................................................
# objects

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
	- rm src/testsuite/untitled.ppm
	- rm src/testsuite/cameraPerspectiveTest
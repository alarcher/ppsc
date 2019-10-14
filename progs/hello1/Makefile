# This Makefile is still simple and the compilations lines are just duplicated.
# This is suboptimal but good enough for this case.
CXX=g++
TARGET=hello
SRC=hello.cpp main.cpp

# Notice that the prerequisites can be stored in a variable. 
all:	$(SRC)
	$(CXX) -c hello.cpp
	$(CXX) -c main.cpp
	$(CXX) -o $(TARGET) hello.o main.o 

clean:
	rm -f *.o $(TARGET)

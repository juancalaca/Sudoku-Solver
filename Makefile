CXXFLAGS = -Wall -Werror

all: board.o main.o
  g++ $(CXXFLAGS) board.o main.o -o main
  
board.o: d_matrix.h d_except.h board.cpp board.h
  g++ $(CXXFLAGS) board.cpp -o board.o
  
main.o: main.cpp board.cpp board.h d_matrix.h d_except.h
  g++ $(CXXFLAGS) main.cpp -o main.o
  
default: all

clean:
  rm *.o main

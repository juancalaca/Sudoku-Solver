CXXFLAGS = -Wall -Werror

all: board.o main.o
<<<<<<< HEAD
	g++ board.o main.o -o main
  
board.o: d_matrix.h d_except.h board.cpp board.h
	g++ $(CXXFLAGS) -c board.cpp -o board.o
  
main.o: main.cpp board.cpp board.h d_matrix.h d_except.h
	g++ $(CXXFLAGS) -c main.cpp -o main.o
=======
  g++ board.o main.o -o main
  
board.o: d_matrix.h d_except.h board.cpp board.h
  g++ $(CXXFLAGS) -c board.cpp -o board.o
  
main.o: main.cpp board.cpp board.h d_matrix.h d_except.h
  g++ $(CXXFLAGS) -c main.cpp -o main.o
>>>>>>> origin/master
  
default: all

clean:
<<<<<<< HEAD
	rm *.o main
=======
  rm *.o main
>>>>>>> origin/master

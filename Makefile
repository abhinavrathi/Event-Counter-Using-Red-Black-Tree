all: ads

ads: main.o  red_black_tree.o
	g++ main.o red_black_tree.o -o bbst

main.o: main.cpp
	g++ -c main.cpp

red_black_tree.o: red_black_tree.cpp
	g++ -c red_black_tree.cpp

cl:
	rm -f *.o bbst
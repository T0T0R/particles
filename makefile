 
main: src/* src/Particles/*
	g++ -Wall -Wextra -std=c++11  -o main src/*.cpp src/Particles/*.cpp

mrproper:
	rm -f main

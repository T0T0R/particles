 
main: src/* src/Particles/* src/Tools/*
	g++ -Wall -Wextra -std=c++11  -o main src/*.cpp src/Particles/*.cpp src/Tools/*.cpp

mrproper:
	rm -f main

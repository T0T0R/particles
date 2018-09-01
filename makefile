main: src/* src/Particles/*
	g++ -Wall -Wextra -o main src/*.cpp src/Particles/*.cpp

mrproper:
	rm -f main

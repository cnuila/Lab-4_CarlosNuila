nombre_exe:main.o
	g++ main.o -o nombre_exe

main.o:main.cpp
	g++ -c main.cpp


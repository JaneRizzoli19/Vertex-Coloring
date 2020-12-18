main: main.o
		g++ main.o -o vertexColor


main.o: main.cpp
		g++ -c main.cpp

clean:
		rm *.o vertexColor

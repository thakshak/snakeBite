SnakeBite: Grid.o Snake.o Food.o
	g++ -o Snake Grid.o Snake.o Food.o

Grid.o: Grid.cpp Snake.h Food.h
	g++ -c Grid.cpp

Snake.o: Snake.cpp Snake.h Food.h
	g++ -c Snake.cpp

Food.o: Food.cpp Food.h
	g++ -c Food.cpp

clean:
	rm *.o Snake

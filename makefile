myapp:	 	main.o functions.o
		g++ -o myapp main.o functions.o; rm *.o

functions.o: 	functions.cpp functions.h
		g++ -Wall -c functions.cpp

main.o: 	main.cpp functions.h
		g++ -Wall -c main.cpp

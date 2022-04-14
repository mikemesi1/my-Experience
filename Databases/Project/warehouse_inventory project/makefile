main: main.cpp orders.cpp admin.cpp inventory.cpp warehouse.cpp crInterface.cpp parts.cpp parts.h orders.h admin.h inventory.h warehouse.h crinterface.h
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o main.o main.cpp
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o warehouse.o warehouse.cpp
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o inventory.o inventory.cpp
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o orders.o orders.cpp
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o admin.o admin.cpp
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o parts.o parts.cpp
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -c -o crinterface.o crInterface.cpp
	g++ -g -ansi -pedantic -Wall -Werror -std=c++14 -o main main.o orders.o inventory.o admin.o parts.o warehouse.o crinterface.o

clean:
	rm -f *.o main
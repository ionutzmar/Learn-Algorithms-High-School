polinoms:
	gcc polinoms.cpp -o "polinoms" -lstdc++ -Wall
strcpy:
	g++ polinoms.cpp -o "polinoms" -lstdc++ -Wall
.PHONY: all polinoms clean
.PHONY: all list clean
topologicSort:
	gcc topologicSort.cpp -o "topSort" -lstdc++ -Wall
minesweeper:
	gcc minesweeper.cpp -o "minesweeper" -lstdc++ -Wall
list:
	gcc list.cpp -o "list" -lstdc++ -fpermissive -Wall
run:
	./polinoms
letter:
	gcc CapitalLetters.cpp  -o "CapitalLetters" -lstdc++ -Wall
prime:
	gcc prime.cpp -o "prime" -lstdc++ -fpermissive -Wall
pointer:
	gcc Pointers.cpp -o "Pointers" -lstdc++ -fpermissive -Wall

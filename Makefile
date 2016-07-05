cycles:
	gcc cycles.cpp -o "cycles" -lstdc++ -Wall
dijkstra:
	gcc dijkstra.cpp -o "dijkstra" -lstdc++ -Wall
fibonacci:
	gcc fibonacci.cpp -o "fibonacci" -lstdc++ -Wall
prim:
	gcc prim.cpp -o "prim" -lstdc++ -Wall
royFloyd:
	gcc royFloyd.cpp -o "royFloyd" -lstdc++ -Wall
triangle:
	gcc triangle.cpp -o "triangle" -lstdc++ -Wall
aranjament:
	gcc aranjament.cpp -o "aranjament" -lstdc++ -Wall
graphics:
	gcc backTracking.cpp -o "backTracking" -lstdc++ -Wall
hanoi:
	gcc hanoi.cpp -o "hanoi" -lstdc++ -Wall
cuts:
	gcc cuts.cpp -o "cuts" -lstdc++ -Wall
polinoms:
	gcc polinoms.cpp -o "polinoms" -lstdc++ -Wall
strcpy:
	g++ polinoms.cpp -o "polinoms" -lstdc++ -Wall
.PHONY: all polinoms clean
.PHONY: all list clean
.PHONY: all cuts clean
.PHONY: all aranjament clean
topologicSort:
	gcc topologicSort.cpp -o "topSort" -lstdc++ -Wall
list:
	gcc list.cpp -o "list" -lstdc++ -fpermissive -Wall
run:
	./aranjament
prime:
	gcc prime.cpp -o "prime" -lstdc++ -fpermissive -Wall

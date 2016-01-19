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

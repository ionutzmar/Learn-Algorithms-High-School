build:
	gcc list.cpp -o "list" -lstdc++ -fpermissive -Wall
run:
	list.exe
letter:
	gcc CapitalLetters.cpp  -o "CapitalLetters" -lstdc++ -Wall
prime:
	gcc prime.cpp -o "prime" -lstdc++ -fpermissive -Wall
pointer:
	gcc Pointers.cpp -o "Pointers" -lstdc++ -fpermissive -Wall
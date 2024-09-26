
explode: main.o lab1.o
	gcc -o explode main.o lab1.o
main.o: main.c
	gcc -c main.c 
lab1.o: lab1.c
	gcc -c lab1.c
	
all : kdtree
kdtree : main.o kdtree.o search.o 
	cc main.o kdtree.o search.o  -o run -lm
main.o : main.c search.h
	cc -c main.c
kdtree.o : kdtree.c kdtree.h
	cc -c kdtree.c
search.o : search.c search.h
	cc -c search.c



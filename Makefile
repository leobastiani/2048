OBJS = main.o animation.o screen.o logic.o variables.o input.o

all: 2048

exec: 2048
	./2048

2048: $(OBJS)
	gcc $(OBJS) -o 2048

main.o: main.c
	gcc -c main.c -o main.o

animation.o: animation.c
	gcc -c animation.c -o animation.o

screen.o: screen.c
	gcc -c screen.c -o screen.o

logic.o: logic.c
	gcc -c logic.c -o logic.o

variables.o: variables.c
	gcc -c variables.c -o variables.o

input.o: input.c
	gcc -c input.c -o input.o

clear:
	rm *.o 2048

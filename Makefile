all:
	gcc -Wall -Wextra p320.c -o task0 -lpthread
	gcc -Wall -Wextra p420.c -o task1 -lpthread
	gcc -Wall -Wextra p421.c -o task2 -lpthread

test:
	@printf "\nRUNNING task0...\n"
	./task0

	@printf "\nRUNNING task1...\n"
	./task1

	@printf "\nRUNNING task2...\n"
	./task2 134 235 98 3 35

clean:
	rm task0 task1 task2
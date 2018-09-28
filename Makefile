all:
	gcc -Wall -Wextra p320.c -o task0 -lpthread
	gcc -Wall -Wextra p420.c -o p420 -lpthread
	gcc -Wall -Wextra p421.c -o p421 -lpthread

test:
	@printf "\nRUNNING p420...\n"
	./p420 100

	@printf "\nRUNNING p421...\n"
	./p421 134 235 98 3 35

clean:
	rm task0 p420 p421
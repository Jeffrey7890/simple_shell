shell: shell.o tokenize.o error.o fork.o
	gcc build/shell.o build/tokenize.o build/error.o build/fork.o -o bin/shell

shell.o: shell.c shell.h
	gcc -c shell.c -o build/shell.o

tokenize.o: tokenizer.c shell.h
	gcc -c tokenizer.c -o build/tokenize.o

error.o: error.c shell.h
	gcc -c error.c -o build/error.o

fork.o: fork.c shell.h
	gcc -c fork.c -o build/fork.o



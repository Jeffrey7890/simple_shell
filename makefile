shell: shell.o tokenize.o error.o fork.o paths.o
	gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 build/shell.o build/paths.o build/tokenize.o build/error.o build/fork.o -o bin/shell

shell.o: shell.c shell.h
	gcc -g -c -Wall -Werror -Wextra -pedantic -std=gnu89 shell.c -o build/shell.o


tokenize.o: tokenizer.c shell.h
	gcc -g -c -Wall -Werror -Wextra -pedantic -std=gnu89 tokenizer.c -o build/tokenize.o

error.o: error.c shell.h
	gcc -g -c -Wall -Werror -Wextra -pedantic -std=gnu89 error.c -o build/error.o

fork.o: fork.c shell.h
	gcc -g -c -Wall -Werror -Wextra -pedantic -std=gnu89 fork.c -o build/fork.o


paths.o: paths.c paths.h
	gcc -g -c -Wall -Werror -Wextra -pedantic -std=gnu89 paths.c -o build/paths.o

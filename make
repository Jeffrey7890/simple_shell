shell.o: shell.c shell.h cmdparse.c fork.c 
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c obj/shell.c

cmdparse.o: shell.h cmdparse.c
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89  -c obj/cmdparse.c
fork.o: shell.h fork.c
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c obj/fork.c

shell: shell.o cmdparse.o fork.o
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 shell.o cmdparse.o -o shell

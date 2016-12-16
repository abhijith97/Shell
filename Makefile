# shell : main.o
# 	gcc main.o -o shell

shell: input_parsing.o prompt.o signal_handlers.o system_commands.o pipeHandler.o listjobs.o sendsig.o movetofg.o killallbg.o execute.o builtin_commands.o main.o header.h
	gcc $^ -o shell

input_parsing.o : input_parsing.c
	gcc -c input_parsing.c

prompt.o : prompt.c
	gcc -c prompt.c

signal_handlers.o : signal_handlers.c
	gcc -c signal_handlers.c

system_commands.o : system_commands.c
	gcc -c system_commands.c


pipeHandler.o : pipeHandler.c
	gcc -c pipeHandler.c

execute.o : execute.c
	gcc -c execute.c

builtin_commands.o : builtin_commands.c
	gcc -c builtin_commands.c

main.o : main.c
	gcc -c main.c

listjobs.o : listjobs.c
	gcc -c listjobs.c

sendsig.o : sendsig.c
	gcc -c sendsig.c

movetofg.o : movetofg.c
	gcc -c movetofg.c

killallbg.o : killallbg.c
	gcc -c killallbg.c

clean:
	rm -rf shell input_parsing.o prompt.o signal_handlers.o system_commands.o pipeHandler.o listjobs.o sendsig.o movetofg.o killallbg.o execute.o builtin_commands.o main.o	
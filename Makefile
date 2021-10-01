#target: dependencies
#	action

program:	program.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.o -o program
	
program.o:	program.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o
	
nameTest:	nameTest.o customers.o somefunctions.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra nameTest.o customers.o somefunctions.o -o nameTest
	
nameTest.o:	nameTest.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c nameTest.c -o nameTest.o
	
customer.o:	customer.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c customer.c -o customer.o
	
somefunctions.o:	somefunctions.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c somefunctions.c -o somefunctions.o

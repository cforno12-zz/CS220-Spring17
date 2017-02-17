test : numLetters
	./numLetters 343
	./numLetters 115
	./numLetters 11618808
	./numLetters 11393389
	./numLetters 94307194
	./numLetters 550670

numLetters : numLetters.c
	gcc -Wall -g -o numLetters numLetters.c

clean :
	-rm numLetters hw04_$(USER).tar.gz
	rm -r numLetters.dSYM

submit: numLetters.c
	mkdir hw04_$(USER)
	cp numLetters.c hw04_$(USER)
	tar -cvzf hw04_$(USER).tar.gz hw04_$(USER)
	rm -r hw04_$(USER)
	echo Turn in hw04_$(USER).tar.gz on myCourses under content, Homework Submissions

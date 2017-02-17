test : numLetters
	./numLetters 343
	echo 343 == 22
	./numLetters 115
	echo 115 == 17
	./numLetters 11618808
	echo 11618808 == 56
	./numLetters 11393389
	echo 11393389 == 66
	./numLetters 94307194
	echo 94307194 == 62
	./numLetters 550670
	echo 550670 == 41
	./numLetters 98
	echo 98 == 11
	./numLetters 100
	echo 100 == 10
	./numLetters 10
	echo 10 == 3
	./numLetters 0
	echo 0 == 4
	./numLetters 8256
	echo 8256 == 31

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

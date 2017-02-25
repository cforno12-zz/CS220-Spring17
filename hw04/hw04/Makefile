test : numLetters
	./numLetters 342
	./numLetters 115

grade : numLetters
	./numLetters 342 > results.txt
	./numLetters 115 >> results.txt
	./numLetters 0 >> results.txt
	./numLetters 1000000000 >>results.txt
	./numLetters  777777777 >>results.txt
	./numLetters 18000015 >>results.txt

numLetters : numLetters.c
	gcc -Wall -g -o numLetters numLetters.c

writeNumbers : writeNumbers.c
	gcc -Wall -g -o writeNumbers writeNumbers.c

clean :
	-rm numLetters writeNumbers hw04_$(USER).tar.gz
	rm -r numLetters.dSYM

submit: numLetters.c
	mkdir hw04_$(USER)
	cp numLetters.c hw04_$(USER)
	tar -cvzf hw04_$(USER).tar.gz hw04_$(USER)
	rm -r hw04_$(USER)
	echo Turn in hw04_$(USER).tar.gz on myCourses under content, Homework Submissions

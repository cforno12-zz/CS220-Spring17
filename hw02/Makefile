test : test_factorial test_primeFactor

test_factorial : factorial
	./factorial

test_primeFactor : primeFactor
	#Original: 35460
	./primeFactor 35460

factorial : factorial.c
	gcc -Wall -g -o factorial factorial.c

primeFactor : primeFactor.c
	gcc -Wall -g -o primeFactor primeFactor.c

clean :
	-rm primeFactor factorial

submit: factorial.c primeFactor.c
	mkdir hw02_cforno1
	cp factorial.c primeFactor.c hw02_cforno1
	tar -cvzf hw02_cforno1.tar.gz hw02_cforno1
	rm -r hw02_cforno1
	echo Turn in hw02_cforno1.tar.gz on myCourses under content, Homework Submissions

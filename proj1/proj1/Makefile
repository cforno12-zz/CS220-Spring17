SRC_FILES = warehouse.c slots.c slots.h Makefile

test : warehouse
	./warehouse <order3.txt

debug : warehouse
	gdb warehouse

warehouse : warehouse.c slots.h slots.c
	gcc -Wall -g -o warehouse warehouse.c slots.c

submit : $(SRC_FILES)
	mkdir proj1_cforno1
	cp $(SRC_FILES) proj1_cforno1
	tar -cvzf proj1_cforno1.tar.gz proj1_cforno1
	rm -r proj1_cforno1

clean :
	-rm warehouse proj1_cforno1.tar.gz

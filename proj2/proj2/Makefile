SRC_FILES = floatx.c floatx.h main.c
ITEM = proj2

 test: floatx
	./floatx 32 8 <test1.txt

floatx:  	main.c floatx.c floatx.h
		gcc  -g -Wall -std=c99 -lm  -o floatx main.c floatx.c

clean:
		-rm floatx $(ITEM)_cforno1.tar.gz
		rm -r floatx.dSYM

submit : $(SRC_FILES)
	mkdir $(ITEM)_cforno1
	cp $(SRC_FILES) $(ITEM)_cforno1
	tar -cvzf $(ITEM)_cforno1.tar.gz $(ITEM)_cforno1
	rm -r $(ITEM)_cforno1

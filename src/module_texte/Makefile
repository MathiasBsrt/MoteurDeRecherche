test1 : mot/mot.c mot/mot.h pile/pile_dynamique.c pile/pile_dynamique.h xml_tokenizer.c Header.h
	gcc -c mot/mot.c
	gcc -c pile/pile_dynamique.c
	gcc -c xml_tokenizer.c
	gcc -o test1.out mot.o pile_dynamique.o xml_tokenizer.o
	./test1.out

test2 : xml_cleaner.c Header.h
	gcc -c xml_cleaner.c 
	gcc -o test2.out xml_cleaner.o
	./test2.out
	
clean:
	rm -f *.o core
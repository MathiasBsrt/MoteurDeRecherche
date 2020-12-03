test_audio : histogramme.c histogramme.h files_handler.c files_handler.h descripteur.c descripteur.h test_audio.c
	gcc -c histogramme.c
	gcc -c files_handler.c
	gcc -c descripteur.c
	gcc -c test_audio.c
	gcc -o test_audio.out histogramme.o files_handler.o descripteur.o test_audio.o -lm
	./test_audio.out
	
test_audio : histogramme.c histogramme.h files_handler.c files_handler.h descripteur.c descripteur.h test_audio.c
	gcc -c histogramme.c
	gcc -c files_handler.c
	gcc -c descripteur.c
	gcc -c test_audio.c
	gcc -o test_audio.out histogramme.o files_handler.o descripteur.o test_audio.o -lm
	./test_audio.out ./TEST_SON/corpus_fi.txt 10 15

creer_histo_txt : histogramme.c histogramme.h files_handler.c files_handler.h main_histo_text.c
	gcc -c histogramme.c
	gcc -c files_handler.c
	gcc -c main_histo_text.c
	gcc -o main_histo_text.out histogramme.o files_handler.o main_histo_text.o -lm
	
test_audio : histogramme.c histogramme.h descripteur.c descripteur.h pile_dynamique.h pile_dynamique.c base_descripteur.h base_descripteur.c test_audio.c
	gcc -c histogramme.c
	gcc -c descripteur.c
	gcc -c base_descripteur.c
	gcc -c pile_dynamique.c
	gcc -c test_audio.c
	gcc -o test_audio.out histogramme.o descripteur.o pile_dynamique.o base_descripteur.o test_audio.o -lm
	./test_audio.out

main_histo : histogramme.c histogramme.h main_histo.c
	gcc -c histogramme.c
	gcc -c main_histo.c
	gcc -o main_histo.out histogramme.o main_histo.o -lm

clean:
	rm -f *.o *.out
	
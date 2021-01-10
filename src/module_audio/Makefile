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

test_wav_helper : wav_file_helper.c wav_file_helper.h test_wav_helper.c
	gcc -c wav_file_helper.c
	gcc -c test_wav_helper.c
	gcc -o test_wav_helper.out wav_file_helper.o test_wav_helper.o
	./test_wav_helper.out

clean:
	rm -f *.o *.out
	
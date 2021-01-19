indexation : ../src/module_audio/histogramme.c ../src/module_audio/histogramme.h ../src/module_audio/wav_file_helper.c ../src/module_audio/wav_file_helper.h ../src/module_audio/descripteur.c ../src/module_audio/descripteur.h ../src/module_audio/pile_dynamique.h ../src/module_audio/pile_dynamique.c ../src/module_audio/base_descripteur.h ../src/module_audio/base_descripteur.c indexation.c
	gcc -c ../src/module_audio/histogramme.c
	gcc -c ../src/module_audio/wav_file_helper.c
	gcc -c ../src/module_audio/descripteur.c
	gcc -c ../src/module_audio/base_descripteur.c
	gcc -c ../src/module_audio/pile_dynamique.c
	gcc -c indexation.c
	gcc -o indexation.out histogramme.o wav_file_helper.o descripteur.o pile_dynamique.o base_descripteur.o indexation.o -lm

recherche : ../src/module_audio/histogramme.c ../src/module_audio/histogramme.h ../src/module_audio/wav_file_helper.c ../src/module_audio/wav_file_helper.h ../src/module_audio/descripteur.c ../src/module_audio/descripteur.h ../src/module_audio/pile_dynamique.h ../src/module_audio/pile_dynamique.c ../src/module_audio/base_descripteur.h ../src/module_audio/base_descripteur.c recherche.c
	gcc -c ../src/module_audio/histogramme.c
	gcc -c ../src/module_audio/wav_file_helper.c
	gcc -c ../src/module_audio/descripteur.c
	gcc -c ../src/module_audio/base_descripteur.c
	gcc -c ../src/module_audio/pile_dynamique.c
	gcc -c recherche.c
	gcc -o recherche.out histogramme.o wav_file_helper.o descripteur.o pile_dynamique.o base_descripteur.o recherche.o -lm


clean:
	rm -f *.o *.out
	
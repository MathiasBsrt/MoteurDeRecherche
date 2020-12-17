indexation : ../src/module_audio/histogramme.c ../src/module_audio/histogramme.h ../src/module_audio/descripteur.c ../src/module_audio/descripteur.h ../src/module_audio/pile_dynamique.h ../src/module_audio/pile_dynamique.c ../src/module_audio/base_descripteur.h ../src/module_audio/base_descripteur.c indexation.c
	gcc -c ../src/module_audio/histogramme.c
	gcc -c ../src/module_audio/descripteur.c
	gcc -c ../src/module_audio/base_descripteur.c
	gcc -c ../src/module_audio/pile_dynamique.c
	gcc -c indexation.c
	gcc -o indexation.out histogramme.o descripteur.o pile_dynamique.o base_descripteur.o indexation.o -lm
	./indexation.out

clean:
	rm -f *.o *.out
	
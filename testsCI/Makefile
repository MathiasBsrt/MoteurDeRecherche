indexationSon : ../src/module_audio/histogramme.c ../src/module_audio/histogramme.h ../src/module_audio/descripteur.c ../src/module_audio/descripteur.h ../src/module_audio/pile_dynamique.h ../src/module_audio/pile_dynamique.c ../src/module_audio/base_descripteur.h ../src/module_audio/base_descripteur.c indexationSon.c
	gcc -c ../src/module_audio/histogramme.c
	gcc -c ../src/module_audio/descripteur.c
	gcc -c ../src/module_audio/base_descripteur.c
	gcc -c ../src/module_audio/pile_dynamique.c
	gcc -c indexationSon.c
	gcc -o indexationSon.out histogramme.o descripteur.o pile_dynamique.o base_descripteur.o indexationSon.o -lm


indexationImage : ../src/module_image/pile_dynamique.c ../src/module_image/pile_dynamique.h ../src/module_image/descripteur.c ../src/module_image/descripteur.h ../src/module_image/controle_descripteur.c ../src/module_image/controle_descripteur.h indexationImage.c
	gcc -c -Wall ../src/module_image/pile_dynamique.c -lm -g
	gcc -c -Wall ../src/module_image/descripteur.c -lm -g
	gcc -c -Wall ../src/module_image/controle_descripteur.c -lm -g
	gcc -c -Wall indexationImage.c -lm
	gcc -o indexationImage.out pile_dynamique.o controle_descripteur.o descripteur.o indexationImage.o

clean:
	rm -f *.o *.out
	
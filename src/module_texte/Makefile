EXEC=moduletexte
SRC=index/index.c MOT/mot.c pile/pile_dynamique.c outils.c xml_cleaner.c xml_tokenizer.c xml_index.c
OBJ=$(SRC:.c=.o)

all: $(EXEC)

moduletexte: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

xml_index.o: Header.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

	#module_texte/Textes_UTF8/03-Mimer_un_signal_nerveux_pour_utf8.xml
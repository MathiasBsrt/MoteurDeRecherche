CC=gcc
DEBUG=yes
ifeq ($(DEBUG),yes)
	CFLAGS=-W -Wall -g
	LDFLAGS=-lm
else
	CFLAGS=-W -Wall
	LDFLAGS=-lm
endif

#directories
BIN=../
DIR_TEXTE=$(BIN)module_texte
DIR_AUDIO=$(BIN)module_audio
DIR_IMAGE=$(BIN)module_image

#Menus
SRCM=$(wildcard *.c)
OBJM=$(SRCM:.c=.o)

#module texte
SRCT=$(wildcard $(DIR_TEXTE)/*.c) $(DIR_TEXTE)/index/index.c $(DIR_TEXTE)/MOT/mot.c $(DIR_TEXTE)/pile/pile_dynamique.c
OBJT=$(SRCT:.c=.o)

#module audio
SRCA=$(wildcard $(DIR_AUDIO)/*.c) 
OBJA=$(SRCA:.c=.o)

#module image
SRCI=$(wildcard $(DIR_IMAGE)/*.c) $(DIR_IMAGE)/moteur_recherche/moteur.c
OBJI=$(SRCI:.c=.o)


EXEC=$(BIN)moteur_recherche


all: moteur_recherche

moteur_recherche: 
	@$(MAKE) $(EXEC)

$(EXEC) : $(OBJA) $(OBJI) $(OBJT) $(OBJM)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
    rm -rf $(OBJM) $(OBJT) $(OBJT) $(OBJA)

mrproper: clean
    rm -rf $(EXEC)
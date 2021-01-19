CC=gcc
DEBUG=yes
ifeq ($(DEBUG),yes)
	CFLAGS=-W -Wall -g
	LDFLAGS=
else
	CFLAGS=-W -Wall
	LDFLAGS=
endif

#directories
BIN=../
DIR_TEXTE=../module_texte
DIR_AUDIO=../module_audio
DIR_IMAGE=../module_image

#Menus
SRCM=$(wildcard *.c)
OBJM=$(SRCM:.c=.o)

#module texte
SRCT=$(wildcard $(DIR_TEXTE)/*.c) $(DIR_TEXTE)/index/index.c $(DIR_TEXTE)/MOT/mot.c $(DIR_TEXTE)/pile/pile_dynamique.c
OBJT=$(SRCT:.c=.o)

#module audio
SRCA=
OBJA=$(SRCA.c=.o)

#module image
SRCI=$(wildcard $(DIR_IMAGE)/*.c) $(wildcard $(DIR_IMAGE)/moteur_recherche/*.c)
OBJI=$(SRCI.C=.o)


EXEC=$(BIN)moteur_recherche


all: moteur_recherche

moteur_recherche: 
	@$(MAKE) $(EXEC)

$(EXEC) : $(OBJA) $(OBJI) $(OBJT) $(OBJM)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
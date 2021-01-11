#include <stdio.h>
#include "wav_file_helper.h"

int wav_get_duration(char * chemin)
{
    // Ouverture du fichier
    FILE * file = fopen(chemin, "rb");
    if(file == NULL) return WAV_FILE_DOESNT_EXIST;

    // Direction la bonne partie du header du fichier WAV
    fseek(file, OFFSET_BYTE_PER_SECOND, SEEK_SET);

    // On lit 4 octets (un int) pour récupérer le nombre d'octet par seconde
    int bytePerSecond;
    fread(&bytePerSecond, 4, 1, file);
     
    // On saute 8 octets
    fseek(file, OFFSET_DATA_SIZE, SEEK_SET);

    // On lit 4 octets (un int) pour récupérer le nombre total d'octet
    int dataSize;
    fread(&dataSize, 4, 1, file);

    // On calcul le rapport
    return dataSize / bytePerSecond;
}
# Module Audio

## Description

Ce module audio permet de traiter les différents formats de fichier ci-dessous:

| Extension | Objectif |
|-----------|----------|
| WAV       | Permet d'écouter l'audio |
| BIN       | Permet d'effectuer des traitements sur le fichier audio |
| TXT       | Permet de vérifier la lecture du fichier audio |

Cependant ce module maintient la lecture des trois format pour pouvoir générer un descripteur audio.

## Utilisation

### Tests unitaire

Une compilation pour effectuer des tests unitaires est disponible dans le fichier ``Makefile``, en suivant les instructions suivantes vous serez capables de les éxecuter:

```bash
make test_audio
```

### Génération unique d'un histogramme

Une compilation pour pouvoir générer un executable capable de créer un histogramme à partir d'un fichier .TXT, .BIN ou .WAV est disponible:

```bash
make main_histo
./main_histo <fichier> <n> <m>
```

## TODO

- [ ] Sauvegarde des descripteurs créés
# Projet fil rouge

Projet commun à plusieurs cours de la première année SRI.

Nous avons élaboré un moteur de recherche (image, son, audio).

Veuillez lire le cahier des charges ainsi que le dossier de spécification se trouvant dans le dossier "documentation/"

## Lancement

A l'heure actuelle, les modules sont indépendants et pas fonctionnels à 100%.
Vous pouvez néanmoins les essayer :
### Module Image
```
cd {chemin}/pfr/src/module_image
make test
./test.out tests/TEST_RGB/{nom d'une image.txt}
```
Vous pouvez visualiser les sorties dans les fichiers base_descripteur_image et liste_base_image.
### Module Texte

### Module Audio

Vous pouvez utiliser le fichier de test (encore à completer) avec:
```bash
cd {chemin}/pfr/src/module_audio
make test_audio
```

Vous pouvez créer un histogramme (à partir d'un fichier TXT) à l'aide de:
```bash
cd {chemin}/pfr/src/module_audio
make creer_histo_txt
./main_histo_text <chemin fichier.txt> <k fenêtres d'analyses> <m intervalles>
```

## Ressources

Les guide d'utilisations des outils utiles pour le projet se trouvent dans le dossier "guide/".

La documentation du projet se trouve dans le dossier "documentation/"

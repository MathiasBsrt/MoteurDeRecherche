# Utilisation de git
Git est un outil qui permet de versionner du code et le stocker sur un serveur. Nous utilisons les serveurs de gitlab.
Tous les fichiers  du projet (code, doc, guide) sont stockés dans le répertoire PFR.
On peut y accèder via le menu de gauche, dans "Repository"
## Principe de git

Voici un tuto à suivre pour comprendre git et le système de branche :[Tuto git](https://openclassrooms.com/fr/courses/1233741-gerez-vos-codes-source-avec-git)

## Ligne de commande
La façon la plus commune d'utilise git est en ligne de commande
### Installation

[Installation + bref tuto](https://www.hostinger.fr/tutoriels/tuto-git/)

### Workflow
Nous allons utiliser une branche principale qui devra rester le plus propre possible, c'est celle qui sera accessible par le client.
On travaillera sur des sous branches.
On aura une branche par tâche. Sachant qu'une tâche a un seul développeur. Cela évitera des conflits si 2 développeurs modifient la même branche au même moment.

**Commandes à faire au tout début :**

Pour cloner tous les fichiers du repertoire localement :

`git clone https://gitlab.com/MathiasBsrt/pfr.git `
`cd pfr `

Puis on travaille sur le code.

**Commandes relatives aux branches :**

Pour creer une nouvelle branche (nouvelle tâche) :
`git branch nomTache`

pour changer de branche :
`git checkout nomTache`

**Commandes récurentes :**

Une fois que l'on a fini la tâche ou que l'on veut sauvegarder son travail; il faut l'envoyer sur le git.
On se place dans le dossier pfr/

`git add .` -> ajouter toutes les modifications
`git commit -m "3 mots sur les modifications apportés`
`git push`

Votre travail sera sauvegardé sur le repertoire.

Pour télécharger les modifications on utilise la commande :
`git pull`

Si vous avez changé des choses avant de faire le git pull, vous devez faire la commande suivante avant de faire le git pull :
`git stash`


## Avec interface graphique

Un outil utile pour utiliser git en version graphique est gitKraken : https://www.gitkraken.com/resources/learn-git

Je ne l'ai jamais utilisé mais il est reconnu pour être simple d'utilisation.
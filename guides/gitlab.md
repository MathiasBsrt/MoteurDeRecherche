# Gitlab - Gestion de projet


Gitlab est un outil de gestion de projet en développement logiciel qui permet de stocker le code avec un système de versionage (git).
J'ai détaillé cette partie dans le fichier guides/git.md. La partie gestion de projet de gitlab se prête très bien aux méthodes agiles.

Via l'onglet Issues à gauche, on peut accèder à "Board".

## Organisation
On utilise 2 board : 

- Un pour afficher les fonctionnalités demandées par le client : **board "fonctionnalités"**.
- Un pour afficher les tâches que l'on associera à une fonctionnalité et à un acteur du projet : **board "Development"**.

**Nous allons définir des fonctionnalités que nous allons découper en tâches.**

Dans gitlab, chaque tâche s'appelle une issue. 

**Pour les tâches :**

On utilise le modèle : TO DO - DOING - DONE pour classer les tâches à effectuer.

Ainsi, le board "Development" aura 3 colonnes :
1. TO DO : Les tâches qui ne sont pas encore commencées
2. DOING : Les tâches en cours
3. DONE : La tâche est finie

[https://gitlab.com/MathiasBsrt/pfr/-/raw/master/guides/images/boardDev.png](https://gitlab.com/MathiasBsrt/pfr/-/raw/master/guides/images/boardDev.png)
Une fois testé, la tâche peut être fermée.

Si un bug est découvert. Le testeur doit ouvrir une nouvelle "issue" dans le board Development et décrire le problème dans la description de celle ci avec le développeur puisse la corriger.

**Pour les fonctionnalités :**

On définit une fonctionnalité comme un label. Un label = une colonne.
Dans le board "fonctionnalités" on aura donc autant de colonne que de fonctionnalités.

On place les tâches dans la fonctionnalité correspondante.
Ce board permet de visualiser les tâches par fonctionnalité.

[board](https://gitlab.com/MathiasBsrt/pfr/-/raw/master/guides/images/boardFonct.png)

## Utilisation des boards

Cette partie explique comment effectuer certaines actions dans les baords.

### Ajouter une tâche
Pour ajouter une tâche, il faut créer une issue, il faut appuyer sur le + à côté de open ou tout autre colonne dans laquelle vous voulez la placer.

- Définissez un nom explicite puis valider.
- Une fenêtre s'ouvre à droite, vous pouvez assigner un acteur en cliquant sur edit.
- En cliquant sur le nom vous pouvez accèder au détails et ajouter des commentaires
- Il faut assigner la tâche à un label (fonctionnalité)

### Afficher les détails d'une issue
Pour afficher les détails d'une issue il faut cliquer sur son nom dans le board.

### Déplacer une issue
Pour déplacer une issue d'une colonne à une autre il suffit de glisser déposer l'issue.

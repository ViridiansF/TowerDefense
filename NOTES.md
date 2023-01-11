JAMMET
HIBLOT
SAMSON

# Commentaire général
Très bon investissement de votre part ! Le résultat est très bon, vous avez eu le souci du détail. Le code est dans l'ensemble plutôt propre et organisé. Seul point noir : quelques memory leaks à corriger. (Voir les détails dans NOTES.md)

## Programmation orientée objet
### Héritage $$4
Bonne utilisation avec les classe Entity Effect Enemy Tower et tous leurs classes enfants.
### Encapsulation $$4
Bonne utilisation des mots clefs private et protected
### Fonctions virtuelles $$4
Utilisation à bon escient des fonctions virtuelle et de leur surcharge.
### Utilisation de références et pas de copies inutiles $$3.5
Bonne utilisation dans l'ensemble.

Attention, copie inutile ici :
```c++
virtual void Update(const std::vector<int> TileState, ...);
// Fix:
virtual void Update(const std::vector<int>& TileState, ...);
```
La grande majorité du temps, si un objet est passé en const, il y a tout intérêt à le passer par référence.

## Clarté du code
### Niveau d'abstraction cohérent (updates en cascade) $$4
Game loop très claire à suivre.
### Clarté des nommages (fonctions/variables) $$4
Très bien dans l'ensemble
### Découpage des fichiers cohérent $$4
Bon organisation du projet.

## Fonctionnalités
### Qualité du rendu $$4
Bravo pour avoir ajouter du texte pour la mise en scène et pour l'aide du joueur (au survol de la souri). Beau soucis du détail.
### Absence de warning à la compilation $$5
### Memory leaks $$3
Gros memory leak lorsqu'on quitte le jeu. Il suffit de le lancer et de le quitter pour que ça se produise.
### Crash $$5
Pas de crash remarqué.

## Présentation
### Commentaires $$4
Présents
### Readme $$3.25
On le dit souvent, une image vaut mille mots. Peu de personne vont lire un bloc de texte tel que celui-ci ! Mais je salue l'effort.
### Norme de code $$3.75
Incohérence, dans enemy.hpp, les membres privées commencent par "p", alors que dans le reste c'est par "m".


## Bonus $$4
Ecrans d'aides, textes, et mise en scène.
### Sons $$5
### Format de donnée (niveau, score) $$5
### Editeur de niveau $$4

## Git
### Qualité des messages $$3.25
Hiblot: Mauvais messages de commits, prenez l'habitude de soigner leurs rédaction.

### Régularité des commits $$4
Commits réguliers.

## Gestion de projet
### Utilisation des tâches GitLab $$4.75
Très bonne utilisation des tâches ! Félicitations pour avoir été perséverrant.
### Bonne répartition des tâches $$4.25
D'après les commits et les tâches, il semblerait que la charge de travail ait été bien répartie.

## Code review (divers)

### Bloc de code...
Dans `void Map::Draw()`, utiliser une variable pour stocker les paramètres passés à `DrawAssetTexture`
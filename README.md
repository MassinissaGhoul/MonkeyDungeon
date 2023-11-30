# MonkeyDungeon Le créateur de donjon timide

Ce programme permet la création automatique ou assistée par l'utilisateur de donjons. Il inclut des fonctions pour générer des salles, placer des entités et créer des couloirs entre les salles.

## Installation

Pour utiliser ce programme, suivez ces étapes :

1.  Cloner le Répertoire :

    `git clone https://github.com/votre-nom/dungeon-creation.git`
    `cd dungeon-creation`

2.  Compiler le Programme :
    Installer CMake 
    `make all`

3.  Exécuter le Programme :

    `./monkeydungeon.exe`

## Fonctionnalités

### Structures

#### Structure de Salle (Room)

```C
typedef struct room {
    int longueur;
    int largeur;
    int xPeak;
    int yPeak;
    char** chunks;
} room;
```

#### Structure de Donjon (Dungeon)

```C
typedef struct dungeon {
    int largeur;
    int longueur;
    int nbRoom;
    int nbRoomIN;
    char** chunks;
    room* rooms;
} dungeon;
```

### Fonctions de Création de Donjon

- `void creation()`: Demande si le donjon doit être créé automatiquement ou par l'utilisateur.
- `dungeon creatDungeon(int largeur, int longueur, int nbRoom)`: Crée la structure de base d'un donjon.
- `dungeon askDungeon()`: Demande à l'utilisateur les détails de création du donjon.
- `dungeon insertRoom(dungeon dungeon)`: Demande à l'utilisateur les détails de création d'une salle et l'insère dans le donjon.

### Fonctions de Création de Salle

- `room askRoom()`: Demande à l'utilisateur les détails de création d'une salle.
- `room creatRoom(int xPeak, int yPeak, int largeur, int longueur)`: Crée une salle avec des dimensions spécifiées.
- `room fillRoom(room room)`: Remplit une salle avec des entités.
- `room insertType(room room, char typeCarac)`: Insère des entités d'un type spécifique dans une salle.
- `room insertBoss(room room)`: Place un boss dans une salle générée par l'utilisateur.

### Fonctions de Modification de Donjon

- `dungeon insertRoomAuto(dungeon dungeon, room room)`: Insère automatiquement une salle dans le donjon.
- `dungeon dungeonAutoDoor(dungeon dungeon)`: Place automatiquement des portes d'entrée et de sortie dans un donjon.
- `dungeon dungeonDoor(dungeon dungeon)`: Demande à l'utilisateur l'emplacement des portes dans un donjon.
- `void deletRoom(dungeon dungeon, int i)`: Supprime une salle si elle n'est pas placable.
- `void detectCollision(dungeon dungeon, room room)`: Vérifie si une salle peut être placée dans un donjon.

### Fonctions de Gestion de Fichiers

- `void saveDungeonFile(dungeon dungeon, char* fileName)`: Sauvegarde un donjon dans un fichier texte.
- `void saveRoomFile(dungeon monDungeon, char *fileName, int numRoom)`: Sauvegarde une salle dans un fichier texte.

### Fonctions de Visualisation

- `void printDungeon(dungeon dungeon)`: Affiche un donjon dans la console.
- `void printRoom(room room)`: Affiche une salle dans la console.

### Fonctions de Création de Couloirs

- `dungeon corridorPart(dungeon monDonjon, int i, int j, int number)`:crée les but du couloir.
- `void makeCorridor(dungeon monDonjon, int i, j)`: Crée un couloir dans le donjon.

### Fonctions Diverses

- `int randomNum(int min, int max)`: Génère une valeur numérique aléatoire.

## Utilisation

1.  Exécutez le programme et choisissez si vous souhaitez créer un donjon automatiquement ou manuellement.
2.  Si vous choisissez manuellement, fournissez des détails tels que les dimensions du donjon et le nombre de salles.
3.  Pour chaque salle, spécifiez les dimensions, les entités et les portes.
4.  Crée vos propre couloir
5.  Sauvegardez le donjon dans un fichier pour une utilisation ultérieure.

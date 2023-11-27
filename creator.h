#ifndef DUNGEON_H
#define DUNGEON_H

extern int iteration;

/**
    \file dungeonh


    \brief Ces fonctions permettent la creation d'un donjon automatiquement ou par un utilisateurs

    \author Ghoul Massinissa / Boulogne Yanis
    \version 1
    \date Novembre 2023
*/

/**
    \brief Structure gerant les informations d'une salle

    \typedef struct room

    \longueur: longueur de la salle
    \largeur: largeur de la salle
    \xPeak yPeak: coordonee en haut a gauche de la salle
    \chunks: matrice de caracteres
*/
typedef struct room {
    int longueur;
    int largeur;
    int xPeak;
    int yPeak;
    char** chunks;
}room;

/**
    \brief Structure gerant les informations d'un donjon

    \typedef struct dungeon

    \largeur: largeur du donjon
    \longueur: longueur du donjon
    \nbRoom: nombres de salle d'un donjon (pas sur de le garder)
    \chunks: matrice de caracteres
*/
typedef struct dungeon {
    int largeur;
    int longueur;
    int nbRoom;
    int nbRoomIN;
    char** chunks;
    room* rooms;
}dungeon;

/**
    \brief : Demande si le donjon se créé automatiquement ou pas
 */
void creation();

/**
    \brief : Cette fonction permet la sauvegarde d'un donjon dans un fichier txt

    \param dungeon : dungeon : un donjon
    \param fileName : char* : nom du fichier de sauvegarde
*/
void saveDungeonFile(dungeon dungeon, char* fileName);

/**
    \brief : Libère l'espace mémoire d'une salle

    \param room : room : une salle
*/
void freeRoom(room room);

/**
    \brief : Libère l'espace mémoire d'un donjon

    \param dungeon : dungeon : un donjon
*/
void freeDungeon(dungeon dungeon);

/**
    \brief : insert une salle dans un donjon

    \param dungeon : dungeon : un donjon
    \param room : room : une salle

    \remark : La fonction verifie à ne pas inserer une salle en dehors du donjon

    \return dungeon : renvoie le donjon rempli
 */
dungeon insertRoomAuto(dungeon dungeon, room room);

/**
    \brief : Affiche un donjon dans la console

    \param dungeon : dungeon : un donjon
*/
void printDungeon(dungeon dungeon);

/**
    \brief : Supprime une salle si elle n'est pas placable

    \param dungeon : dungeon : un donjon
    \param i : int : index de la salle
    
    \return dungeon : renvoie le donjon
*/
dungeon deletRoom(dungeon dungeon, int i);

/**
    \brief : Verifie qu'une salle est placable

    \param dungeon : dungeon : un donjon
    \param room : room : une salle

    \return dungeon : renvoie le donjon
*/
dungeon detectCollision(dungeon dungeon, room room);

/**
    \brief : Creer les bordures d'un donjon

    \param largeur : int : largeur du donjon
    \param longueur : int : longueur du donjon
    \param nbRoom : int : nb de salle maximum dans un donjon

    \return dungeon : renvoie le contour du donjon
*/
dungeon creatDungeon(int largeur, int longueur, int nbRoom);

/**
    \brief : Place automatiquement les portes dans un donjon

    \param dungeon : dungeon : un donjon

    \return dungeon : renvoie le donjon avec son entree et sa sortie
*/
dungeon dungeonAutoDoor(dungeon dungeon);

/**
    \brief : Demande l'emplacement des portes dans un donjon

    \param dungeon : dungeon : un donjon

    \return dungeon : renvoie le donjon avec son entree et sa sortie
*/
dungeon dungeonDoor(dungeon dungeon);

/**
    \brief : Affiche une salle dans la console

    \param room : room : une salle
*/
void printRoom(room room);

/**
    \brief : genere une  aleur numerique aleatoire

    \param min : nombre minimum
    \param max : nombre maximum

    \return : un nombre aleatoire entre min et max
*/
int randomNum(int min, int max);

/**
    \brief : Permet de mettre un caractere dans une salle

    \param room : room : une salle
    \param spawnerDisp : int : nombre maximal d'entites a placer
    \param type : char : type de caractere a placer

    \return : une salle avec des entites
*/
room spawner(room room, int spawnerDisp, char type);

/**
    \brief : creer une salle

    \param xPeak : int : coordonee en x du coin haut gauche
    \param yPeak : int : coordonee en y du coin haut gauche
    \param largeur : int : largeur de la salle
    \param longueur : int : longueur de la salle

    \return : une salle
*/
room creatRoom(int xPeak, int yPeak, int largeur, int longueur);

/**
    \brief : met des entites dans une salle

    \param room : room : une salle

    \return : une salle avec des entites
*/
room fillRoom(room room);

/**
    \brief : Demande a l'utilisateur de creer une salle automatiquement ou avec ses propres parametres

    \return : une salle
*/

room askRoom();

/**
    \brief : place des entites dans une salle a des coordonees donnees par l'utilisateur

    \param : room : room : une salle
    \param : typeCarac : char : type de caractere a placer

    \return : une salle avec des entites
*/
room insertType(room room, char typeCarac);

/**
    \brief : Place le boss dans une salle genere par un utilisateur

    \param room : room : une salle

    \return room : renvoie la salle avec le boss
*/
room insertBoss(room room);

/**
    \brief : Change tous les monstres("M") autour d'un piege("P") en depouille("W")

    \param room : room : une salle
    \param i : int : coordonee en x du piège
    \param j : int : coordonee en y du piège

    \return room : renvoie la piece en ayant change les monstres en depouille
*/
room killMob(room room, int i, int j);

/**
    \brief : Demande a l'utilisateur de creer un donjon automatiquement ou avec ses propres parametres

    \return : un donjon
*/
dungeon askDungeon();

/**
    \brief : Demande a l'utilisateur les informations nécessaire a creer une salle pour un donjon

    \param dungeon : dungeon : un donjon

    \return : un donjon
*/
dungeon insertRoom(dungeon dungeon);

/**
    \brief : Demande l'emplacement des portes d'une salle

    \param room : room : une salle

    \return room : renvoie une salle avec son entree et sa sortie
*/
room roomDoor(room room);

/**
    \brief : Place automatiquement les portes d'une salle

    \param room : room : une salle

    \return room : renvoie une salle avec son entree et sa sortie
*/
room roomAutoDoor(room room);

/**
    \brief : Relis les portes par des couloirs

    \param monDonjon : dungeon : un donjon
    \param i : int : coordonee x de l'entree
    \param j : int : coordonee y de l'entree

    \return : un donjon
*/
dungeon autoCouloir(dungeon monDonjon, int i, int j);

dungeon corridorPart(dungeon monDonjon, int i, int j, int number);


#endif
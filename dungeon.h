#ifndef DUNGEON_H
#define DUNGEON_H

/**
    \file dungeon.h


    \brief Ces fonctions permettent la creation d'un donjon automatiquement ou par un utilisateurs.

    \author Ghoul Massinissa /Boulogne Yanis
    \version 1
    \date Novembre 2023
*/

/**
    \brief Structure gerant les informations d'une salle.

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
    \brief Structure gerant les informations d'un donjon.

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
    char** chunks;
}dungeon;

/**
    \brief : Cette fonction permet la sauvegarde d'un donjon dans un fichier txt.

    \param monDungeon : dungeon : un donjon.
    \param fileName : char* : nom du fichier de sauvegarde.
*/
void saveDungeonFile(dungeon monDungeon, char* fileName);

/**
    \brief : Libère l'espace mémoire d'une salle.

    \param maRoom : room : une salle.
*/
void freeRoom(room maRoom);

/**
    \brief : Libère l'espace mémoire d'un donjon.

    \param monDungeon : dungeon : un donjon.
*/
void freeDungeon(dungeon monDungeon);

/**
    \brief : insert une salle dans un donjon.

    \param monDungeon : dungeon : un donjon.
    \param maRoom : room : une salle.

    \remark : La fonction verifie à ne pas inserer une salle en dehors du donjon.

    \return dungeon : renvoie le donjon rempli
 */
dungeon insertRoom(dungeon monDungeon, room maRoom);

/**
    \brief : Affiche un donjon dans la console.

    \param monDungeon : dungeon : un donjon.
*/
void afficherDungeon(dungeon monDungeon);

/**
    \brief : Creer les bordures d'un donjon.

    \param largeur : int : largeur du donjon
    \param longueur : int : longueur du donjon
    \param nbRoom : int : nb de salle maximum dans un donjon

    \return dungeon : renvoie le contour du donjon
*/
dungeon creatDungeon(int largeur, int longueur, int nbRoom);

/**
    \brief : Place les portes dans un donjon.

    \param maRoom : room : une salle.

    \return dungeon : renvoie le donjon avec son entree et sa sortie
*/
dungeon placePorte(dungeon monDongeon);

/**
    \brief : Affiche une salle dans la console.

    \param maRoom : room : une salle.
*/
void afficherRoom(room maRoom);

/**
    \brief : genere un numero aleatoire

    \param min : nombre minimum
    \param max : nombre maximum

    \return : un nombre aleatoire entre min et max
*/
int randomNum(int min, int max);

/**
    \brief : Permet de mettre un caractere dans une salle

    \param maRoom : room : une salle.
    \param spawnerDisp : int : nombre d'entites a placer
    \param type : char : type de caractere a placer

    \return : une salle avec des entites
*/
room Spawner(room maRoom, int spawnerDisp, char type);

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
    
    \param maRoom : room : une salle.

    \return : une salle avec des entites
*/
room fillRoom(room maRoom);

/**
    \brief : Demande a l'utilisateur de creer une salle automatiquement ou avec ses propres parametres

    \return : une salle
*/

room askPlayer();

/**
    \brief : place des entites dans une salle a des coordonees donnees par l'utilisateur
    \param : maRoom : room : une salle.
    \param : typeCarac : char : type de caractere a placer

    \return : une salle avec des entites
*/
room placeCarac(room maRoom, char typeCarac);

/**
    \brief : Place le boss dans une salle genere par un utilisateur.

    \param maRoom : room : une salle.

    \return room : renvoie la salle avec le boss
*/
room bossPlace(room maRoom);

/**
    \brief : Change tous les monstres("M") d'une salle en depouille("W") si ils sont proches d'un piege("P").

    \param maRoom : room : une salle.

    \return room : renvoie la piece en ayant change les monstres en depouille
*/
room killMob(room maRoom);

#endif
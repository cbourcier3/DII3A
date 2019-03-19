#ifndef ROBOT
#define ROBOT
#define pi 3.14159
#define nombreCranParToursDeRoue 100
#define tailleTableauValeursImpulsions 10000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int nombreCoordonnees;
int periode;                //en secondes
typedef struct position
{
    int roueGaucheX;
    int roueDroiteX;
    int roueGaucheY;
    int roueDroiteY;
    int centreX;
    int centreY;
    float orientation;
} position;

typedef struct robot
{
    position position;
    float entraxe;
    float vitesseMax;
    float rayonRoue;
    int nombreCoordonnees;
    int periode;
    //distance en mm
    //vitesse en m.s-1
    //angle en radian
} robot;

typedef struct deplacement
{
    float impulsionGauche[tailleTableauValeursImpulsions];
    float impulsionDroite[tailleTableauValeursImpulsions];
} deplacement;

typedef struct deplacementEntier
{
    int impulsionGauche[tailleTableauValeursImpulsions];
    int impulsionDroite[tailleTableauValeursImpulsions];
} deplacementEntier;

void calculDeplacement(robot robot, deplacement *deplacementF, deplacementEntier* deplacementI);
void calculImpulsionsReels(deplacement *dep,deplacementEntier *depReel);
void calculPositionReel(robot *rob, deplacement *dep);
void calculPositionRecu(robot *rob, deplacementEntier *dep );
float randomFloat(float valeurMax); //Calculer un nombre random float entre 0 et valeurMax
void initRobot(robot *rob);
void calculDeplacementDefini(robot robot, deplacement* deplacementF, deplacementEntier* deplacementI, int choixRand);

#endif

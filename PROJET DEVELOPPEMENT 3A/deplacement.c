#define pi 3.14159
#define nombreCranParToursDeRoue 10 
#define dureeEchantillonnage 100 //en ms
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deplacement.h"
struct position
{
    float roueGaucheX;
    float roueDroiteX;
    float roueGaucheY;
    float roueDroiteY;
    float orientation;
};
struct robot
{
    position position;
    float entraxe;
    float vitesseMax;   
    float rayonRoue;
    //distance en mm
    //vitesse en m.s-1
    //angle en radian
};
struct deplacement
{
    int impulsionGauche;
    int impulsionDroite;
};
typedef struct robot robot;
typedef struct position position;
typedef struct deplacement deplacement;

robot initRobot(robot rob)
{
    rob.entraxe=100;
    //initialisation des positions des roues, ici en 0,0 pour al roue gauche et entraxe,0 pour roue droite
    rob.position.roueGaucheX=0;
    rob.position.roueGaucheY=0;
    rob.position.roueDroiteX=rob.entraxe+rob.position.roueGaucheX;
    rob.position.roueDroiteY=rob.position.roueGaucheY;
    rob.vitesseMax=0.5;
    rob.rayonRoue=25;
    rob.position.orientation=1/2*pi;
    return rob;
}
deplacement calculDeplacement(robot robot){
    deplacement deplacement;
    srand(time(NULL));
    float nbMaxImpulsionEnFctEchantillonnage;
    int nbMaxImpulsion = (int) nbMaxImpulsionEnFctEchantillonnage;
    for (float i=0; i<10; i=i+0.1)
    {
        nbMaxImpulsionEnFctEchantillonnage = robot.vitesseMax*dureeEchantillonnage*0.001*nombreCranParToursDeRoue;
        deplacement.impulsionDroite=rand()%nbMaxImpulsion;
        deplacement.impulsionGauche=rand()%nbMaxImpulsion;
        printf("\nimpulsionDroite: %d",deplacement.impulsionDroite);
        printf("\nimpulsionGauche: %d",deplacement.impulsionGauche);
    }
    return deplacement;
}
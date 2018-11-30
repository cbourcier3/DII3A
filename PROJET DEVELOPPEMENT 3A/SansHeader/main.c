#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.14159
#define nombreCranParToursDeRoue 10 
#define dureeEchantillonnage 0.1 //en s
typedef struct position
{
    float roueGaucheX;
    float roueDroiteX;
    float roueGaucheY;
    float roueDroiteY;
    float orientation;
}position;
typedef struct robot
{
    position position;
    float entraxe;
    float vitesseMax;   
    float rayonRoue;
    //distance en mm
    //vitesse en m.s-1
    //angle en radian
}robot;
typedef struct deplacement
{
    float impulsionGauche;
    float impulsionDroite;
}deplacement;

robot initRobot(robot rob)
{
    rob.entraxe=100;
    //initialisation des positions des roues, ici en 0,0 pour al roue gauche et entraxe,0 pour roue droite
    rob.position.roueGaucheX=0;
    rob.position.roueGaucheY=0;
    rob.position.roueDroiteX=rob.entraxe+rob.position.roueGaucheX;
    rob.position.roueDroiteY=rob.position.roueGaucheY;
    rob.vitesseMax=1;//m.s-1
    rob.rayonRoue=0.05;//en mètre
    rob.position.orientation=1/2*pi;
    return rob;
}
float randomFloat(float valeurMax)
{
    int entierPourModulo = (int)(valeurMax*1000000);
    return (float)(rand()%entierPourModulo)/1000000;
}
deplacement calculDeplacement(robot robot){
    deplacement deplacement;
    srand(time(NULL));
    float nbMaxImpulsionEnFctEchantillonnage;
    nbMaxImpulsionEnFctEchantillonnage = robot.vitesseMax/(2*pi*robot.rayonRoue)*dureeEchantillonnage*nombreCranParToursDeRoue;
    for (float i=0; i<10; i=i+0.1)
    {
        deplacement.impulsionDroite=randomFloat(nbMaxImpulsionEnFctEchantillonnage);
        deplacement.impulsionGauche=randomFloat(nbMaxImpulsionEnFctEchantillonnage);
        printf("\nimpulsionDroite: %f",deplacement.impulsionDroite);
        printf("\nimpulsionGauche: %f",deplacement.impulsionGauche);
    }
    return deplacement;
}


int main(int argv, char* argc[]){
    robot monRobot;
    deplacement dep;
    FILE* fichier = NULL;
    fichier = fopen("dataRobotAvancement.txt", "r+");
    srand(time(NULL));
    monRobot = initRobot(monRobot);
    printf("%f %f %f %f \n",monRobot.position.roueDroiteX,monRobot.position.roueDroiteY,monRobot.position.roueGaucheX,monRobot.position.roueGaucheY);
    //dep =calculDeplacement(monRobot);
    fputs("Hello",fichier);
}

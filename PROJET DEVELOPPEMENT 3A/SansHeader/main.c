#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.14159
#define nombreCranParToursDeRoue 10
#define dureeEchantillonnage 0.1 //en s
#define tailleTableauValeursImpulsions 100
typedef struct position
{
    float roueGaucheX;
    float roueDroiteX;
    float roueGaucheY;
    float roueDroiteY;
    float orientation;
} position;
typedef struct robot
{
    position position;
    float entraxe;
    float vitesseMax;
    float rayonRoue;
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

robot initRobot(robot rob)
{
    rob.entraxe = 100;
    //initialisation des positions des roues, ici en 0,0 pour al roue gauche et entraxe,0 pour roue droite
    rob.position.roueGaucheX = 0;
    rob.position.roueGaucheY = 0;
    rob.position.roueDroiteX = rob.entraxe + rob.position.roueGaucheX;
    rob.position.roueDroiteY = rob.position.roueGaucheY;
    rob.vitesseMax = 1;   //m.s-1
    rob.rayonRoue = 0.05; //en mètre
    rob.position.orientation = 1 / 2 * pi;
    return rob;
}
float randomFloat(float valeurMax)
{
    int entierPourModulo = (int)(valeurMax * 1000000);
    return ((float)(rand() % entierPourModulo) / 1000000);
}
deplacementEntier calculImpulsionsReels(deplacement dep)
{
    float swapD = 0, swapG = 0;
    deplacementEntier depReel;
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        printf("%f  , ",dep.impulsionDroite[i]);
        dep.impulsionDroite[i] = dep.impulsionDroite[i] + swapD;
        dep.impulsionGauche[i] = dep.impulsionGauche[i] + swapG;
        depReel.impulsionGauche[i] = (int)(dep.impulsionGauche[i]);
        depReel.impulsionDroite[i] = (int)(dep.impulsionDroite[i]);
        swapD = dep.impulsionDroite[i] - (float)((int)(dep.impulsionDroite[i]));
        swapG = dep.impulsionDroite[i] - (float)((int)(dep.impulsionDroite[i]));
        printf("%f => %d\n", dep.impulsionDroite[i], depReel.impulsionDroite[i]);
    }
    return depReel;
}
deplacementEntier calculDeplacement(robot robot)
{
    deplacement deplacementF;
    deplacementEntier deplacementI;
    FILE* fichier= NULL;
    fichier = fopen("dataRobotAvancement.txt", "a");
    srand(time(NULL));
    float nbMaxImpulsionEnFctEchantillonnage;
    nbMaxImpulsionEnFctEchantillonnage = robot.vitesseMax / (2 * pi * robot.rayonRoue) * dureeEchantillonnage * nombreCranParToursDeRoue;
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        deplacementF.impulsionDroite[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
        deplacementF.impulsionGauche[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
    }
    deplacementI = calculImpulsionsReels(deplacementF);
    for(int i=0;i<tailleTableauValeursImpulsions;i++)
    {
        fprintf(fichier,"%d;%f;%f;%d;%d;\n",i,deplacementF.impulsionGauche[i],deplacementF.impulsionDroite[i],deplacementI.impulsionGauche[i],deplacementI.impulsionDroite[i]);
    }
    fclose(fichier);
    return deplacementI;
}


int main(int argv, char *argc[])
{
    robot monRobot;
    deplacementEntier dep;
    FILE *fichier = NULL;
    fichier = fopen("dataRobotAvancement.txt", "w");
    fprintf(fichier,"i;impusionTheoRoueGauche;impulsionTheoRoueDroite;impulsionReelRoueGauche;impulsionReelRoueDroite;\n");
    fclose(fichier);
    srand(time(NULL));
    monRobot = initRobot(monRobot);
    printf("%f %f %f %f \n", monRobot.position.roueDroiteX, monRobot.position.roueDroiteY, monRobot.position.roueGaucheX, monRobot.position.roueGaucheY);
    dep = calculDeplacement(monRobot);
}

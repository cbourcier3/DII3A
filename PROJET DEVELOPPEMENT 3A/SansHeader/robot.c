#include "robot.h"

void initRobot(robot *rob) //initialise la position du robot
{
    rob->entraxe = 100;
    rob->position.roueGaucheX = -50;
    rob->position.roueGaucheY = 0;
    rob->position.roueDroiteX = rob->entraxe + rob->position.roueGaucheX;
    rob->position.roueDroiteY = rob->position.roueGaucheY;
    rob->position.centreX = (rob->position.roueDroiteX + rob->position.roueGaucheX) / 2;
    rob->position.centreY = rob->position.roueGaucheY;
    rob->vitesseMax = 500;   //mm.s-1
    rob->rayonRoue = 25; 
    rob->position.orientation = 1 / 2 * pi;
    //Toutes les distances sont en milimètre
}
float randomFloat(float valeurMax) //Calculer un nombre random float entre 0 et valeurMax
{
    int entierPourModulo = (int)(valeurMax * 1000000);//description sujet / analyse fonctionnel / modèle utilisé
    return ((float)(rand() % entierPourModulo) / 1000000);
}
/*void calculImpulsionsReels(deplacement *dep, deplacementEntier *depReel)
{
    float swapD = 0, swapG = 0;
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        dep->impulsionDroite[i] = dep->impulsionDroite[i] + dep->impulsionDroite[j];
        dep->impulsionGauche[i] = dep->impulsionGauche[i] + dep->impulsionGauche[j] ;
        depReel->impulsionGauche[i] = (int)(dep->impulsionGauche[i]+ swapG);
        depReel->impulsionDroite[i] = (int)(dep->impulsionDroite[i]+ swapD);
        swapD = dep->impulsionDroite[i] - ((float)(depReel->impulsionDroite[i]))+ swapD;
        swapG = dep->impulsionGauche[i] - ((float)(depReel->impulsionGauche[i])) + swapG;
    }
}*///OLD
void calculDeplacement(robot robot, deplacement *deplacementF, deplacementEntier* deplacementI)
{
FILE *fichier = NULL;
    fichier = fopen("dataRobotAvancement.txt", "w");
    fprintf(fichier, "i;impusionTheoRoueGauche;impulsionTheoRoueDroite;impulsionReelRoueGauche;impulsionReelRoueDroite;\n");
    float nbMaxImpulsionEnFctEchantillonnage;//valeurMax
    nbMaxImpulsionEnFctEchantillonnage = robot.vitesseMax / (2 * pi * robot.rayonRoue) * periode * nombreCranParToursDeRoue/10000;
    srand(time(NULL));
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        deplacementF->impulsionDroite[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
        deplacementF->impulsionGauche[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
    }
    calculImpulsionsReels(deplacementF, deplacementI);
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        fprintf(fichier, "%d;%f;%f;%d;%d;\n", i, deplacementF->impulsionGauche[i], deplacementF->impulsionDroite[i], deplacementI->impulsionGauche[i], deplacementI->impulsionDroite[i]);
    }
    fclose(fichier);
}
/*void calculDeplacementDefini(robot robot, deplacement *deplacementF, deplacementEntier* deplacementI, int choixRand)
{
    FILE *fichier = NULL;
    fichier = fopen("dataRobotAvancement.txt", "w");
    fprintf(fichier, "i;impusionTheoRoueGauche;impulsionTheoRoueDroite;impulsionReelRoueGauche;impulsionReelRoueDroite;\n");
    float nbMaxImpulsionEnFctEchantillonnage;//valeurMax
    nbMaxImpulsionEnFctEchantillonnage = robot.vitesseMax / (2 * pi * robot.rayonRoue) * periode * nombreCranParToursDeRoue;
    srand(choixRand);
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        deplacementF->impulsionDroite[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
        deplacementF->impulsionGauche[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
    }
    calculImpulsionsReels(deplacementF, deplacementI);
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        fprintf(fichier, "%d;%f;%f;%d;%d;\n", i, deplacementF->impulsionGauche[i], deplacementF->impulsionDroite[i], deplacementI->impulsionGauche[i], deplacementI->impulsionDroite[i]);
    }
    fclose(fichier);
}*///OLD

void calculPositionReel(robot *rob, deplacement *dep)
{
    //Calcul de l'angle pris par les roues
    //formule : DeltaAngle = (déplacement droite - déplacement gauche )/distanceEntreRoues
    //DeltaX = R*(sin(Orientation actuel)-sin(Orientation précédente))
    //DeltaY = R*(cos(Orientation actuel)+cos(Orientation précédente))
    //R = entraxe * ((impulsionDroite + impulsionGauche)/2)/(impulsionDroite-impulsionGauche)
    int i = 0;
    FILE *fichier = NULL;
    fichier = fopen("dataRobotPosition.csv", "w");
    fprintf(fichier, "i;centreX;centreY;roueGaucheX;roueGaucheY;roueDroiteX;roueDroiteY;orientation;\n");
    fprintf(fichier, "-1;%d;%d;%d;%d;%d;%d;%f;\n", rob->position.centreX, rob->position.centreY,rob->position.roueGaucheX,rob->position.roueGaucheY,rob->position.roueDroiteX,rob->position.roueDroiteY, rob->position.orientation);
    float orientationPrec;
    float distanceEntrePlusieursCrans =(2 * pi *  rob->rayonRoue) / nombreCranParToursDeRoue;
    for (i = 0; i < nombreCoordonnees; i++)
    {
        orientationPrec = rob->position.orientation;
        rob->position.orientation = ((dep->impulsionDroite[i] - dep->impulsionGauche[i]) / rob->entraxe) * pi + rob->position.orientation;
        rob->position.centreX = (double)((dep->impulsionDroite[i] + dep->impulsionGauche[i]) / 2)*distanceEntrePlusieursCrans * cos(orientationPrec) + rob->position.centreX;
        rob->position.centreY = (double)((dep->impulsionDroite[i] + dep->impulsionGauche[i]) / 2) *distanceEntrePlusieursCrans* sin(orientationPrec) + rob->position.centreY;
        rob->position.roueGaucheX = rob->position.centreX + (rob->entraxe/2) * cos(rob->position.orientation);
        rob->position.roueGaucheY = rob->position.centreY - (rob->entraxe/2) * sin(rob->position.orientation);
        rob->position.roueDroiteX = rob->position.centreX - (rob->entraxe/2) * cos(rob->position.orientation);
        rob->position.roueDroiteY = rob->position.centreY + (rob->entraxe/2) * sin(rob->position.orientation);
        printf(" à i=%d : x: %d y: %d orientation: %f \n", i, rob->position.centreX, rob->position.centreY, rob->position.orientation);
        fprintf(fichier, "%d;%d;%d;%d;%d;%d;%d;%f;\n", i, rob->position.centreX, rob->position.centreY,rob->position.roueGaucheX,rob->position.roueGaucheY,rob->position.roueDroiteX,rob->position.roueDroiteY, rob->position.orientation);
    }
}
void calculPositionRecu(robot *rob, deplacementEntier *dep )
{
    FILE *fichier = NULL;
    fichier = fopen("dataRobotPositionRecu.csv", "w");
    fprintf(fichier, "i;centreX;centreY;roueGaucheX;roueGaucheY;roueDroiteX;roueDroiteY;orientation;\n");       
    fprintf(fichier, "-1;%d;%d;%d;%d;%d;%d;%f;\n", rob->position.centreX, rob->position.centreY,rob->position.roueGaucheX,rob->position.roueGaucheY,rob->position.roueDroiteX,rob->position.roueDroiteY, rob->position.orientation);
    float orientationPrec;
    float distanceEntrePlusieursCrans =(2 * pi *  rob->rayonRoue) / nombreCranParToursDeRoue;
    for (int i = 0; i < nombreCoordonnees; i++)
    {
        orientationPrec = rob->position.orientation ;
        rob->position.orientation = ((dep->impulsionDroite[i] - dep->impulsionGauche[i]) / rob->entraxe) * pi + rob->position.orientation;
        rob->position.centreX = (double)((dep->impulsionDroite[i] + dep->impulsionGauche[i]) / 2) *distanceEntrePlusieursCrans* cos(orientationPrec) + rob->position.centreX;
        rob->position.centreY = (double)((dep->impulsionDroite[i] + dep->impulsionGauche[i]) / 2) *distanceEntrePlusieursCrans* sin(orientationPrec) + rob->position.centreY;
        rob->position.roueGaucheX = rob->position.centreX + (rob->entraxe/2) * cos(rob->position.orientation);
        rob->position.roueGaucheY = rob->position.centreY - (rob->entraxe/2) * sin(rob->position.orientation);
        rob->position.roueDroiteX = rob->position.centreX - (rob->entraxe/2) * cos(rob->position.orientation);
        rob->position.roueDroiteY = rob->position.centreY + (rob->entraxe/2) * sin(rob->position.orientation);
        //printf(" à i=%d : x: %d y: %d orientation: %f \n", i, rob->position.centreX, rob->position.centreY, rob->position.orientation);
        fprintf(fichier, "%d;%d;%d;%d;%d;%d;%d;%f;\n", i, rob->position.centreX, rob->position.centreY,rob->position.roueGaucheX,rob->position.roueGaucheY,rob->position.roueDroiteX,rob->position.roueDroiteY, rob->position.orientation);
    }
}

void calculImpulsionsReels(deplacement *dep, deplacementEntier *depReel)
{
    float swapD = 0, swapG = 0;
    int saut = tailleTableauValeursImpulsions/nombreCoordonnees;
    int j;
    for (int i = 0; i < nombreCoordonnees; i = i + 1)
    {
        j = i*saut + 1;
        for(j=j ; j<i*saut + saut;j++)
        {
            dep->impulsionDroite[i] = dep->impulsionDroite[i] + dep->impulsionDroite[j];
            dep->impulsionGauche[i] = dep->impulsionGauche[i] + dep->impulsionGauche[j] ;
        }
        depReel->impulsionGauche[i] = (int)(dep->impulsionGauche[i]+ swapG);
        depReel->impulsionDroite[i] = (int)(dep->impulsionDroite[i]+ swapD);
        swapD = dep->impulsionDroite[i] - ((float)(depReel->impulsionDroite[i]))+ swapD;
        swapG = dep->impulsionGauche[i] - ((float)(depReel->impulsionGauche[i])) + swapG;
    }
}
void calculDeplacementDefini(robot robot, deplacement *deplacementF, deplacementEntier* deplacementI, int choixRand)
{
    FILE *fichier = NULL;
    fichier = fopen("dataRobotAvancement.txt", "w");
    fprintf(fichier, "i;impusionTheoRoueGauche;impulsionTheoRoueDroite;impulsionReelRoueGauche;impulsionReelRoueDroite;\n");
    float nbMaxImpulsionEnFctEchantillonnage;//valeurMax
    nbMaxImpulsionEnFctEchantillonnage = robot.vitesseMax / (2 * pi * robot.rayonRoue) * periode * nombreCranParToursDeRoue/10000;
    srand(choixRand);
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        deplacementF->impulsionDroite[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
        deplacementF->impulsionGauche[i] = randomFloat(nbMaxImpulsionEnFctEchantillonnage);
    }
    calculImpulsionsReels(deplacementF, deplacementI);
    for (int i = 0; i < tailleTableauValeursImpulsions; i++)
    {
        fprintf(fichier, "%d;%f;%f;%d;%d;\n", i, deplacementF->impulsionGauche[i], deplacementF->impulsionDroite[i], deplacementI->impulsionGauche[i], deplacementI->impulsionDroite[i]);
    }
    fclose(fichier);
}
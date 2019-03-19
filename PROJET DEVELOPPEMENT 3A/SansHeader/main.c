#include "robot.h"

int main(/*int argv, char *argc[]*/)
{
   nombreCoordonnees = 1000;   //valeur par défaut du nombre de coordonnées que l'on veut récupérer
   periode = 10;              //valeur par défaut de la période 
   robot RobotReel;
   robot RobotRecu;
   deplacementEntier depEntier;
   deplacement dep;
   srand(time(NULL));
   initRobot(&RobotReel);
   initRobot(&RobotRecu);
   calculDeplacement(RobotReel, &dep, &depEntier);
   calculPositionReel(&RobotReel, &dep);
   calculPositionRecu(&RobotRecu, &depEntier);
}

#include "robot.h"

int main(/*int argv, char *argc[]*/)
{
   /*nombreCoordonnees = 1000;   //valeur par défaut du nombre de coordonnées que l'on veut récupérer
   periode = 10;              //valeur par défaut de la période 
   robot RobotReel;
   robot RobotRecu;
   deplacementEntier depEntier;
   deplacement dep;
   srand(time(NULL));
   initRobot(&RobotReel);
   initRobot(&RobotRecu);
   calculDeplacementDefini(RobotReel, &dep, &depEntier,1);
   calculPositionReel(&RobotReel, &dep);
   calculPositionRecu(&RobotRecu, &depEntier);*/
   //test
   nombreCoordonnees = 3;   //valeur par défaut du nombre de coordonnées que l'on veut récupérer
   periode = 1;              //valeur par défaut de la période 
   robot RobotReel;
   robot RobotRecu;
   deplacementEntier depEntier;
   deplacement dep;
   srand(time(NULL));
   initRobot(&RobotReel);
   initRobot(&RobotRecu);
   calculDeplacementDefini(RobotReel, &dep, &depEntier,1);
   calculPositionReel(&RobotReel, &dep);
   calculPositionRecu(&RobotRecu, &depEntier);
}

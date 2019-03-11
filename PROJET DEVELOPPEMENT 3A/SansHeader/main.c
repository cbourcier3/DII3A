#include "robot.h"

int main(/*int argv, char *argc[]*/)
{
   srand(time(NULL));
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

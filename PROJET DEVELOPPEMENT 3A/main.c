#include "deplacement.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argv, char* argc[]){
    struct robot monRobot;
    deplacement dep;
    monRobot = initRobot(monRobot);
    printf("%f %f %f %f \n",monRobot.position.roueDroiteX,monRobot.position.roueDroiteY,monRobot.position.roueGaucheX,monRobot.position.roueGaucheY);
    dep =calculDeplacement(monRobot);

}

#include <stdio.h>
#include <stdlib.h>
#include "tp2.h"

int main(int argc, char *argv[])
{
    char *test= get_first_arg(argc,argv);
    //char testA='a',testB='z',testC='A',testD='Z';
    //printf("a: %d , z: %d, A: %d, Z: %d",testA,testB,testC,testD);
    test = upper(test);
    return 0;
}
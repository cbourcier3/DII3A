#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_first_arg(int argc, char *argv[])
{
   if (argc <2)
   {
      printf("no argument\n\n");
      exit(0);
   }
   return (argv[1]);
}
int main(int argc, char *argv[])
{
    char *chaine=get_first_arg(argc,argv);
    int compteur=0;
    for (int i=0; i<strlen(chaine);i++)
    {
        if (chaine[i]==32)
        {
            if (compteur!=0){
                printf("\n");
            }
            compteur=0;
        }
        else
        {
            if (compteur==0 && chaine[i]<123 && chaine[i]>96)
                chaine[i]=chaine[i]-32;
            printf("%c",chaine[i]);
            compteur++;
        }
    }
    //char testA='a',testB='z',testC='A',testD='Z';
    //printf("a: %d , z: %d, A: %d, Z: %d",testA,testB,testC,testD);
    return 0;
}
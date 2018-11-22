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
   char *arg = get_first_arg(argc, argv);   
   int i=0;
   int longueurChaine=strlen(arg);
   printf("chaine: %s \n", arg);
   printf("longueurChaine: %d \n",longueurChaine);
   for(i=longueurChaine-1;i>=0;i--)
   {
      for(int j=0;j<longueurChaine-i;j++)
         printf(" ");
      for(int j=i+1;j>0;j--)
         printf("%c",arg[j-1]);
      for(int j=1;j<i+1;j++)
         printf("%c",arg[j]);
      printf("\n");
   }
   return 0;
}
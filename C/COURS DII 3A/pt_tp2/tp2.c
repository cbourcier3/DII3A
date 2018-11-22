#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_first_arg(int argc, char *argv[])
{
    if (argc <2)
    {
        printf("no argument\n\n");
        return 0 ;
    }
    return (argv[1]);
}

char *upper(char *s)
{
    for (int i =0; i< strlen(s);i++)
    {
        if ((s[i]<123) && (s[i]>96))
        {
            s[i]=s[i]-32;
        }
    }
    return s;
}


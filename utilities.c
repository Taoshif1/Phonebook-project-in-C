#include<string.h>
#include<ctype.h>

#include "utilities.h"

void strtolower(char *str) //This functions modifies the given string
{
    int len = strlen(str);
    int i;
    for(i=0; i<len; i++){
        str[i] = tolower (str[i]);
    }
}



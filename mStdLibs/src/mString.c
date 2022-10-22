#include <stdlib.h>
#include "mStdLibs.h"

int mStrlen(char* string)
{
    int i = 0;
    while (*(string + i) != '\0')
        i++;
    return i;
}

char* mStrcpy(char* source)
{
    char *destination;
    int i = 0;
    int length = mStrlen(source);
    destination = (char*)malloc((length + 1) * sizeof(char));
    if (destination == NULL)
        return NULL;
    for (i = 0; i < length; i++)
        destination[i] = source[i];
    destination[i] = 0;
    return destination;
}
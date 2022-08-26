#include <stdio.h>
#include "encrypt.h"

#define N 25
#define STRLEN 10

int main() 
{
    unsigned char key[N] = {25, 44, 26, 39, 45, 
                            41, 96, 127, 244, 2,
                            183, 231, 92, 58, 41,
                            82, 79, 13, 43, 213,
                            99, 252, 32, 77, 46};
                      
    char plainText[STRLEN];
    char *cypherText;
    char *decryptText;
    RC4State rc4state = InitRC4(key, N);

    scanf("%s", plainText);
    cypherText = EncryptRC4String(plainText, STRLEN, rc4state);
    printf("%s\n", cypherText);
    decryptText = EncryptRC4String(cypherText, STRLEN, rc4state);
    printf("%s\n", decryptText);

    printf("Exit");
    getchar();
    getchar();
    
    return 0;
}
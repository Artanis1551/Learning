#include <stdio.h>
#include "encrypt.h"
#include "mStdLibs.h"

#define N 25
#define STRLEN 255

int main(int argc, char **argv) 
{
    unsigned char key[N] = {25, 44, 26, 39, 45, 
                            41, 96, 127, 244, 2,
                            183, 231, 92, 58, 41,
                            82, 79, 13, 43, 213,
                            99, 252, 32, 77, 46};
                      
    int length = 0;
    char buffer[STRLEN];
    char *plainText = NULL;
    char *cypherText = NULL;
    char *decryptText = NULL;
    RC4State rc4state = InitRC4(key, N);

    printf("Starting %s...\n", argv[0]);
    printf("Plain text:\n");
    scanf("%[^\n]", buffer);
    plainText = mStrcpy(buffer);
    length = mStrlen(plainText);
    cypherText = EncryptRC4String(plainText, length, rc4state);
    printf("Encrypted text:\n%s\n\n", cypherText);
    decryptText = EncryptRC4String(cypherText, length, rc4state);
    printf("Decrypted text:\n%s\n\n", decryptText);

    printf("Exiting %s...", argv[0]);
    getchar();
    getchar();
    
    return 0;
}
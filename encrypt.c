#include <stdlib.h>
#include "encrypt.h"
#include "mStdLibs/mMath.h"

/* 
** Summary InitRC4
**
** Description: Initialize RC4State with a given key 
**
** Parameters:
**   char* key: the pointer to the string that contains the key
**   int keyLength: length of the key
**
** Output: Returns the RC4State struct initialized with the given key
*/ 
RC4State InitRC4(unsigned char* key, int keyLength)
{
    RC4State result;

    for (result.i = 0; result.i < RC4LEN; result.i++)
    {
        result.S[result.i] = result.i;
        result.K[result.i] = key[result.i % keyLength];
    }
    
    for (result.i = 0; result.i < RC4LEN; result.i++)
    {
        result.j = (result.i + result.S[result.i] + result.K[result.i]) % RC4LEN;
        Swapuc(&result.S[result.i], &result.S[result.j]);
    }
    
    result.i = 0; result.j = 0;

    return result;
}
// End of InitRC4 function definition

/* 
** Summary EncryptRC4String
**
** Description: Encrypt a variable length string using the RC4 algorithm with a given RC4State
**
** Parameters:
**   char* text: the pointer to the string that is to be encrypted
**   int length: the length of the text to be encrypted
**   RC4State rc4state: RC4State structure to use for encryption
**
** Output: Returns a pointer to where the encrypted string is stored
*/ 
char* EncryptRC4String(char* text, int length, RC4State rc4state)
{
    int iter;
    char *cypherText;
    
    cypherText = (char*)malloc(sizeof(char) * (length + 1));

    if (cypherText == NULL)
        return NULL;
    
    for (iter = 0; iter < length; iter++)
        cypherText[iter] = EncryptRC4Byte(text[iter], rc4state);
    cypherText[iter] = 0;

    return cypherText;
}
// End of EncodeRC4String function definition

/* 
** Summary EncryptRC4Byte
**
** Description: Encrypt a simple character using the RC4 algorithm with a given RC4State
**
** Parameters:
**   char text: the character that will be encrypted
**   RC4State rc4state: RC4State structure to use for encryption
**
** Output: Returns the encrypted character
*/ 
char EncryptRC4Byte(char text, RC4State rc4state)
{
    char keyStreamByte, result;

    rc4state.i = (rc4state.i + 1) % RC4LEN;
    rc4state.j = (rc4state.j + rc4state.S[rc4state.i]) % RC4LEN;
        
    Swapuc(&rc4state.S[rc4state.i], &rc4state.S[rc4state.j]);

    keyStreamByte = rc4state.S[(rc4state.S[rc4state.i] + rc4state.S[rc4state.j]) % RC4LEN];
    result = text ^ keyStreamByte;

    return result;
}
// End of EncodeRC4Byte function definition

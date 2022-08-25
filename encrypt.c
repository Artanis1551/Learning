#include <stdio.h>

#define N 25
#define STRLEN 60

#define RC4LEN 256

void EncryptRC4(char*, int, char*, unsigned char*, int);

int main() 
{
    unsigned char key[N] = {25, 44, 26, 39, 45, 
                            41, 96, 127, 244, 2,
                            183, 231, 92, 58, 41,
                            82, 79, 13, 43, 213,
                            99, 252, 32, 77, 46};
                      
    char plainText[STRLEN];
    char cypherText[STRLEN];
    char decryptText[STRLEN];
    
    scanf("%s", plainText);
    EncryptRC4(plainText, STRLEN, cypherText, key, N);
    printf("%s\n", cypherText);
    EncryptRC4(cypherText, STRLEN, decryptText, key, N);
    printf("%s\n", decryptText);
    
    return 0;
}


/* 
** Summary EncryptRC4
**
** Description: Encrypt a variable length string using the RC4 algorithm with a given key
**
** Parameters:
**   char* text: the pointer to the string that is to be encrypted
**   int length: the length of the text to be encrypted
**   char* cypherText: the pointer where the output encrypted/decrypted string will be stored
**                     allocate memory to cypherText before calling this function
**   unsigned char* key: pointer to where the key is stored
**   int keyLength: length of the key [1..256]
**
** Output: Stores the encrypted/decrypted string where cypherText points
*/
void EncryptRC4(char* text, int length, char* cypherText, unsigned char* key, int keyLength)
{
    int i, j, iter;
    char tempChar = 0;
    char keyStreamByte = 0;
    unsigned char S[RC4LEN], K[RC4LEN];
    
    for (i = 0; i < RC4LEN; i++)
    {
        S[i] = i;
        K[i] = key[i % keyLength];
    }
    
    for (i = 0; i < RC4LEN; i++)
    {
        j = (i + S[i] + K[i]) % RC4LEN;
        
        tempChar = S[i];
        S[i] = S[j];
        S[j] = tempChar;
    }
    
    i = 0; j = 0;
    
    for (iter = 0; iter < length; iter++)
    {
        i = (i + 1) % RC4LEN;
        j = (j + S[i]) % RC4LEN;
        
        tempChar = S[i];
        S[i] = S[j];
        S[j] = tempChar;
        
        keyStreamByte = S[(S[i] + S[j]) % RC4LEN];
        cypherText[iter] = text[iter] ^ keyStreamByte;
    }
    cypherText[iter] = 0;
}

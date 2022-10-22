#ifndef ENCRYPT_H

#define ENCRYPT_H 1
#define RC4LEN 256

typedef struct
{
    int i, j;
    unsigned char S[RC4LEN], K[RC4LEN];
} RC4State;

RC4State InitRC4(unsigned char* key, int keyLength);
char* EncryptRC4String(char*, int, RC4State);
char EncryptRC4Byte(char, RC4State);

#endif
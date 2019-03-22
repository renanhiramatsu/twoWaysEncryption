/* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -
 
 CIS 22B --> CypherA.h
 This decoding method uses a mapping system that mapps sequentially a letter
 from the alphabet to a letter in a cipher declared previously.

 Created by Renan Silva Hiramatsu on 2019/03/05
 
 * - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * - */


#ifndef CypherA_h
#define CypherA_h
#include "Encrypted.h"

class CypherA : public Encrypted
{
private:
    
public:
    using Encrypted::Encrypted;
    void decode() override;
};


// It decodes the message mapping one letter from alphabet to another in cipher
void CypherA::decode()
{
    unsigned int msgSize = 406;
    unsigned char alphabet[] = {"abcdefghijklmnopqrstuvwxyz"};
    unsigned char cipher[] = {"iztohndbeqrkglmacsvwfuypjx"};
    
    char encode[256], decode[256];
    for (int i = 0; i < 256; i++) encode[i] = decode[i] = (char)i;
    for (int i = 0; i < sizeof(alphabet); i++) {
        encode[(unsigned char)alphabet[i]] = cipher[i];
        decode[(unsigned char)cipher[i]] = alphabet[i];
    }
    
    for (int k = 0; k < msgSize; k++)
        msg[k] = encode[msg[k]];
}


#endif /* CypherA_h */

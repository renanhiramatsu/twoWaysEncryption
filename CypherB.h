/* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -
 
 CIS 22B --> CypherB.h
 
 Caesar Cipher: a technique in which each character in plain text is replaced by
                a character some fixed number of positions down to it.
                (For this program, it shifts 4)
 
 Created by Renan Silva Hiramatsu on 2019/03/05
 
 * - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * - */

#ifndef CypherB_h
#define CypherB_h
#include "Encrypted.h"

class CypherB : public Encrypted
{
private:
    
public:
    using Encrypted::Encrypted;
    void decode();
};


// It decodes the message using Ceasar Cipher shifting 4 units
void CypherB::decode()
{
    char ch;
    const int SHIFT = 4;
    int i;
    
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - SHIFT;
            
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - SHIFT;
            
            if(ch > 'a'){
                ch = ch + 'Z' - 'A' + 1;
            }
            
            msg[i] = ch;
        }
    }
    
};

#endif /* CypherB_h */

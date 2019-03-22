/* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -
 
 CIS 22B --> Encrypted.h
 
 Created by Renan Silva Hiramatsu on 2019/03/05
 
 * - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * - */

#ifndef Encrypted_h
#define Encrypted_h
#include <iostream>

class Encrypted
{
private:
    
protected:
    bool status;
    std::string filename;
    static const int MAX_TEXT = 1000;
    char* msg;

public:
    Encrypted(std::string filename, const int MAX_TEXT);
    ~Encrypted();
    virtual void decode() = 0;
    void getStatus();
    void print();
    bool isEmpty();
    
};


#endif /* Encrypted_h */


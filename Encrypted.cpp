/* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -
 
 CIS 22B
 
 Lab5: This program decodes message files with two systems. The first one uses a
       a mapping system that mapps sequentially a letter from the alphabet to a
       letter in a cipher declared previously.
 
       The second uses a Caesar Cipher, it's a technique in which each character
       in plain text is replaced by a character some fixed number of positions
       down to it. (For this program, it shifts 4)
 
 Created by Renan Silva Hiramatsu on 2019/02/25
 
 * - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * -* - * - */

#include "Encrypted.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


Encrypted::Encrypted(std::string filename, const int MAX_TEXT){
    msg = new char[MAX_TEXT];
    
    std::ifstream inFile(filename);
    
    if (inFile.fail())
        status = false;
    else
        status = true;
    
    getStatus();
    
    for (int k = 0; !inFile.eof(); k++)
        inFile >> std::noskipws >> msg[k];
    
    inFile.close();
    
}

Encrypted::~Encrypted() { delete[] msg; }

void Encrypted::print() { cout << msg << endl; }


// Checks if .txt file is empty
bool Encrypted::isEmpty(){
    ifstream inFile;
    if (inFile.peek() == ifstream::traits_type::eof())
        return false;
    else
        return true;
}

// Retrieves information about the file opening
void Encrypted::getStatus()
{
    if (status == true)
        cout << "File opened successfully" << endl;
    else
        cout << "The file failed to open" << endl;
}

/*
Enter file name to be decoded with algorithm A: Encrypted.txt
File opened successfully
Decoded message:
encryption is the name given to the process of applying an algorithm to a message, which scrambles the data in it-making it very difficult and time consuming, if not practically impossible, to deduce the original given only the encoded data. inputs to the algorithm typically involve additional secret data called keys, which prevents the message from being decoded-even if the algorithm is publicly known.



Enter file name to be decoded with algorithm B: EncB.txt
File opened successfully
Decoded message:
in a symmetric encryption algorithm, both the sender and the recipient use the same key (known as the secret key) to encrypt and decrypt the message. one very basic symmetric encryption algorithm is known as the rotational cipher. in this algorithm, the sender simply "adds" the key to each character of the cleartext message to form the ciphertext. for example, if the key is 2, "a" would become "c", "b" would become "d, and so on. the recipient would then decrypt the message by "subtracting" the key from each character of the ciphertext to obtain the original message.

Program ended with exit code: 0
*/

#include<iostream>
#include"TranslatorDictionary.h"

using namespace std;


#define       TYPE_1  1  // comp = dest; jmp
#define       TYPE_2  2  // dest = jmp;
#define       TYPE_3  3  // comp =dest;


class Translator{

 public:


    TranslatorDictionary symbl_tbl;
    TranslatorDictionary symbl_tbl_dest;
    static int addr_counter;
    Translator();
    bool isCommand(string cmd);
    string trimSpaces(string cmd);
    string trimAfterCommandComments(string cmd);
    void translateCommand(string cmd, string &res);
    void translateSymbols(string cmd);
    void writetoHackFile();
    int CInstructionType(string cmd);
    string covertToBinary(int num , int num_of_bits);


};



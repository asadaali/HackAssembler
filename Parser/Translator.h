#include<iostream>
#include"TranslatorDictionary.h"
using namespace std;


class Translator{

 public:

    TranslatorDictionary symbl_tbl;

    Translator();
    bool isCommand(string cmd);
    void translateCommand(string cmd);
    void translateSymbols(string cmd);
    void writetoHackFile();
    string covertToBinary(int num);





};

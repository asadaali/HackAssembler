#include<iostream>

using namespace std;

/**pair : symbol value pair*/
struct data{

    string sybmol;
    int address;

};
struct node{

  data * val;
  node * next;
};

class TranslatorDictionary{

  public:
      node * first;
      node * last;
     /**Constructor*/
     TranslatorDictionary();
     /**Adding new pair*/
     void addSybmol(data * d);
     /**looking up for a symbol*/
     int lookupForAddress(string symbol);
     /**Destructor*/
    ~TranslatorDictionary();


};

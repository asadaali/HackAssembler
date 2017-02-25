    #include<iostream>
    #include"TranslatorDictionary.h"


    using namespace std;

    TranslatorDictionary::TranslatorDictionary(){

        this->first = NULL;
        this->last  = NULL;


    }

    void TranslatorDictionary::addSybmol(data * d)
    {
       if(first == NULL)
       {
          first = new node();
          first->val = d;
          first->next = NULL;
          last = first;



       }else{

        last->next = new node();
        last->val = d;
        last = last->next;
        last->next = NULL;



       }



    }
    int TranslatorDictionary::lookupForAddress(string symbol){

    node * temp  = first;

        while(temp!=NULL)
        {

            if(!symbol.compare(temp->val->sybmol)){


                return temp->val->address;

            }

            temp = temp->next;
        }
        cout<<"error : symbol - " << symbol << "not found\n";

        return -1;
    }


    TranslatorDictionary::~TranslatorDictionary(){

        delete first;
        delete last;


    }








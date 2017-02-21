#include<iostream>
#include<sstream>
#include<stdio.h>
#include"Translator.h"

using namespace std;



    Translator::Translator(){

        // initializing sybmol table
        data *d = new data();
        d->sybmol   = "SP" ;
        d->address  = 0 ;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol   = "LCL" ;
        d->address  = 1 ;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol   = "ARG" ;
        d->address  = 2 ;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol   = "THIS" ;
        d->address  =  3 ;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol   = "THAT" ;
        d->address  = 4 ;
        this->symbl_tbl.addSybmol(d);

        for(int i = 0 ; i < 16 ; i++){
            d = new data();
            d->sybmol ="R" ;
            d->sybmol += i;
            d->address  = i ;
            this->symbl_tbl.addSybmol(d);
        }


        d = new data();
        d->sybmol   = "SCREEN" ;
        d->address  = 16384;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol   = "KBD" ;
        d->address  = 24576;
        this->symbl_tbl.addSybmol(d);

        //initializing jump table

        d = new data();
        d->sybmol="null";
        d->address = 0;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="JGT";
        d->address = 1;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="JEQ";
        d->address = 2;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="JGE";
        d->address = 3;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="JLT";
        d->address = 4;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="JNE";
        d->address = 5;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="JLE";
        d->address = 6;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="JMP";
        d->address = 7;
        this->symbl_tbl.addSybmol(d);


        //adding destination table
        d = new data();
        d->sybmol="M";
        d->address = 1;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="D";
        d->address = 2;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="MD";
        d->address = 3;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="A";
        d->address = 4;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="AM";
        d->address = 5;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="AD";
        d->address = 6;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="AMD";
        d->address = 7;
        this->symbl_tbl.addSybmol(d);

        //initializing cmp table
        /************************ a = 0**********************************************/        d = new data();
        d->sybmol="0";
        d->address = 34;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="0";
        d->address = 34;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="0";
        d->address = 34;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="1";
        d->address = 63;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="-1";
        d->address = 58;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="D";
        d->address = 12;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="A";
        d->address = 48;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="!D";
        d->address = 13;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="!A";
        d->address = 49;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="-D";
        d->address = 15;
        this->symbl_tbl.addSybmol(d);



        d = new data();
        d->sybmol="-A";
        d->address = 51;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="D+1";
        d->address = 31;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="A+1";
        d->address = 55;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="D-1";
        d->address = 14;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="A-1";
        d->address = 50;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="D+A";
        d->address = 2;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="D-A";
        d->address = 19;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="A-D";
        d->address = 7;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="D&A";
        d->address = 0;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="D|A";
        d->address = 21;
        this->symbl_tbl.addSybmol(d);

        /************************ a = 1**********************************************/

        d = new data();
        d->sybmol="M";
        d->address = 112;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="!M";
        d->address = 113;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="-M";
        d->address = 115;
        this->symbl_tbl.addSybmol(d);

         d = new data();
        d->sybmol="M+1";
        d->address = 119;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="M-1";
        d->address = 114;
        this->symbl_tbl.addSybmol(d);

        d = new data();
        d->sybmol="D+M";
        d->address = 66;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="D-M";
        d->address = 83;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="M-D";
        d->address = 71;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="D&M";
        d->address = 64;
        this->symbl_tbl.addSybmol(d);


        d = new data();
        d->sybmol="D|M";
        d->address = 85;
        this->symbl_tbl.addSybmol(d);
    }


    string Translator::covertToBinary(int n)
    {

        int bin[7];
        int count = 0;
        for(int j = 0 ; j < 7; j ++)
            bin[j]=0;

        int remainder, i = 1, step = 1;

        while (n!=0)
        {
            remainder = n%2;
            n /= 2;
            bin[count] = remainder;
            count++;

        }
        ostringstream machineCode;
        for(int i = 6 ; i >=0 ; i--)
            machineCode <<bin[i];


        return machineCode.str();
    }


  void Translator::translateSymbols(string cmd){

      /**The instruction is of A-type*/
      if(cmd[0]=='@'){

           string str;
        /**removing @ from the command to check for symbol*/
        for( int i = 1 ; cmd[i]!='\0' ; i++)
                str += cmd[i];


      }
      int ret = this->symbl_tbl.lookupForAddress(str);

      if(ret>=0)
        return ret;
      else
        //this->symbl_tbl.addSybmol()





  }

  void Translator::translateCommand(string cmd){

         /**This is an A-type instruction*/
      if(cmd[0]=='@'){
            string str;
        /**removing @ from the command to have its machine  code*/
        for( int i = 1 ; cmd[i]!='\0' ; i++)
                str += cmd[i];

        /**converting this string to integer to convert it to machine code*/
        int num = 0;
        stringstream s_str(str);
        s_str >> num;


        Translator::covertToBinary(num);

        /**C type instruction*/
      }else{




      }




  }

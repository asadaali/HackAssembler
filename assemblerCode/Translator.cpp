#include<iostream>
#include<sstream>
#include<stdio.h>
#include"Translator.h"

using namespace std;

int Translator::addr_counter = 16;

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
        this->symbl_tbl_dest.addSybmol(d);

        d = new data();
        d->sybmol="D";
        d->address = 2;
        this->symbl_tbl_dest.addSybmol(d);

        d = new data();
        d->sybmol="MD";
        d->address = 3;
        this->symbl_tbl_dest.addSybmol(d);

        d = new data();
        d->sybmol="A";
        d->address = 4;
        this->symbl_tbl_dest.addSybmol(d);


        d = new data();
        d->sybmol="AM";
        d->address = 5;
        this->symbl_tbl_dest.addSybmol(d);

        d = new data();
        d->sybmol="AD";
        d->address = 6;
        this->symbl_tbl_dest.addSybmol(d);

        d = new data();
        d->sybmol="AMD";
        d->address = 7;
        this->symbl_tbl_dest.addSybmol(d);

        d = new data();
        d->sybmol="M";
        d->address = 1;
        this->symbl_tbl_dest.addSybmol(d);

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

//        symbl_address_tracker = 16;
    }

    int Translator::CInstructionType(string cmd)
    {
        if(cmd.find("=")!=string::npos && cmd.find(";")!=string::npos){

            return  TYPE_1;
        }

        if(cmd.find(";")!=string::npos){
            return  TYPE_2;

        }
        if(cmd.find("=")!=string::npos){

            return  TYPE_3;
        }

    }
    string Translator::covertToBinary(int n, int num_of_bits)
    {

        int * bin = new int[num_of_bits];
        int count = 0;
        for(int j = 0 ; j < num_of_bits; j ++)
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
        for(int i = num_of_bits-1 ; i >=0 ; i--)
            machineCode <<bin[i];


        return machineCode.str();
    }


  void Translator::translateSymbols(string cmd){

      /**The instruction is of A-type*/
      string str;
      if(cmd[0]=='@'){


        /**removing @ from the command to check for symbol*/
        for( int i = 1 ; cmd[i]!='\0' ; i++)
                str += cmd[i];



      int ret = this->symbl_tbl.lookupForAddress(str);

      if(ret>=0)
        {
            cout<<"\nSymbol found\n";
        }else{
            data * d = new data();
            d->sybmol = str;
          d->address = Translator::addr_counter;
          Translator::addr_counter++;

        }

      }
      else{
      }
    }

  void Translator::translateCommand(string cmd, string &res){

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


        res = this->covertToBinary(num, 16);
        cout<<res<<"\n";

      }
        /**C type instruction*/
        /**Binary: 1 1 1 a c1 c2 c3 c4 c5 c6 d1 d2 d3 j1 j2 j3*/
      else{

            string comp = "";
            string dest = "";
            string jmp = "";
            res = "111";
            /**type 1 dest = comp; jmp*/
            if(this->CInstructionType(cmd) == TYPE_1){

                    int i,j= 0;
               for(i = 0 ; cmd[i]!= '=' ; i++)
                    dest+=cmd[i];

                int ret = this->symbl_tbl_dest.lookupForAddress(dest);

                if( ret >=0)
                        dest= this->covertToBinary(ret, 3);


                 for(j = i+1 ; cmd[j]!= ';' ; j++)
                    comp+=cmd[j];

                 i = j;

                ret = this->symbl_tbl.lookupForAddress(comp);
                if( ret >=0)
                        comp = this->covertToBinary(ret, 7);

                for(int k =  j + 1 ; cmd[k]!= '\0' ; k++){
                    jmp+=cmd[k];
                }

                 ret = this->symbl_tbl.lookupForAddress(jmp);
                if( ret >=0)
                       jmp= this->covertToBinary(ret, 3);

                    res += comp;
                    res += dest;
                    res += jmp;

                cout<<res<<"\n";

            }
            /**comp;jmp*/
            if(this->CInstructionType(cmd) == TYPE_2){


                string comp = "";
                string jmp = "";
                res = "111";
                int i = 0 ;
                for(i= 0 ; cmd[i]!=';'; i++)
                  comp+=cmd[i];

                int ret = symbl_tbl.lookupForAddress(comp);
                if(ret>=0)
                    comp=this->covertToBinary(ret,7);
                for(int j = i+1; cmd[j]!='\0'; j++)
                    jmp += cmd[j];

                 ret = symbl_tbl.lookupForAddress(jmp);
                if(ret>=0)
                    jmp=this->covertToBinary(ret,3);


                res +=comp;
                res+="000";
                res += jmp;
            cout<< res<<"\n";

            }

            /**dest= comp*/
            if(this->CInstructionType(cmd)==TYPE_3)
            {

                string cmp = "";
                string dest = "";
                res = "111";
                int i = 0 ;
                for(i= 0 ; cmd[i]!= '='; i++){
                  dest+=cmd[i];

                }

                int  ret =  symbl_tbl_dest.lookupForAddress(dest);

                if(ret>=0)
                    dest=this->covertToBinary(ret,3);
                for(int j = i+1; cmd[j]!='\0'; j++)
                    cmp += cmd[j];

                 ret = symbl_tbl.lookupForAddress(cmp);

                if(ret>=0)
                    cmp=this->covertToBinary(ret,7);


                res+=cmp;
                res+=dest;
                res+="000";


                cout<< res<<"\n";






            }



      }




  }

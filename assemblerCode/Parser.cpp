    /**< Parse will parse the assembly file, remove white space and generate a file for translator */
    #include<iostream>
    #include<fstream>
    #include<string>
    #include"Parser.h"
    #include"Translator.h"

    using namespace std;


    // This function will tell wether the given line of file a command or white space
    Parser::Parser()
    {
        //fileRead = NULL;
        //fname = NULL;
       // parseOut = NULL;


    }

    void Parser::removeWhitespaces()
    {

        // read file per line

        //output screen
        // looping through the whole file
       for(string line; getline(this->fileRead, line);){
        //  if the next line is  not a white space nor a comment ;
        if(!line.empty() && this->isCommand(line))
        {
            //this is the start since output string is empty
            if(this->parseOut.empty())
            {
                this->parseOut = line;
                this->parseOut += "\n";


            }
            else
            {
                this->parseOut += line;
                this->parseOut +="\n";
                // cout<<"line :"<<line<<"\n";

            }

        }

       }



    }




    bool Parser :: openFile()
    {
        this->fileRead.open(this->fname);
        if(this->fileRead.is_open())
            return true;
        else
        {

            cout<<"Unable to open file\n";
            return false;
        }

    }


    void Parser :: closeFile()
    {
      this->fileRead.close();


    }

    bool Parser::isCommand(string cmd){


            if(!cmd.find("/")){

                return false;
            }
            else{

                return true;
            }


    }
    int main(char * agrv[] , int argc)
    {


        Parser p;
        p.fname = "Add.asm";
        p.openFile();


      //  p.removeWhitespaces();

      //  cout<<p.parseOut;
        Translator t;
       // int in = t.symbl_tbl.lookupForAddress("A-D");
       // cout << in<<"\n" ;
       // cout<<t.covertToBinary(in,7)<<"\n";


       // t.translateCommand("@4");cout<<"\n";
       // t.translateCommand("M=D");
       for(string line; getline(p.fileRead, line);){
        //  if the next line is  not a white space nor a comment ;
        if(!line.empty() && p.isCommand(line))
            t.translateCommand(line);
      }




    }

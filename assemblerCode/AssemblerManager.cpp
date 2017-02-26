    /**< Parse will parse the assembly file, remove white space and generate a file for translator */
    #include<iostream>
    #include<fstream>
    #include<string>
    #include"AssemblerManager.h"
    #include"Translator.h"

    using namespace std;


    // This function will tell wether the given line of file a command or white space
    AssemblerManager::AssemblerManager()
    {
        //fileRead = NULL;
        //fname = NULL;
       // parseOut = NULL;


    }


    bool AssemblerManager :: openFile()
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


    void AssemblerManager :: closeFile()
    {
      this->fileRead.close();


    }

    bool AssemblerManager::isCommand(string cmd){


            if(!cmd.find("/")){

                return false;
            }
            else{

                return true;
            }


    }
    int main(char * agrv[] , int argc)
    {


        AssemblerManager p;
        p.fname = "PongL.asm";
        p.openFile();

        Translator t;
        string res;
        ofstream f_write;
        string new_line = "\n";
        f_write.open("out_pong_1.hack");


       for(string line; getline(p.fileRead, line);){
        //  if the next line is  not a white space nor a comment ;
        if(!line.empty() && p.isCommand(line)){
            t.translateCommand(line, res);

            f_write << res << "\n";
        }


      }





    }

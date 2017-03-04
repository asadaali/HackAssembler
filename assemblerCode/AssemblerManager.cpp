    /**< Parse will parse the assembly file, remove white space and generate a file for translator */
    #include<iostream>
    #include<fstream>
    #include<string>
    #include"AssemblerManager.h"
    #include"Translator.h"

    using namespace std;

    /**macro used for debugging*/
    #define INFO(x) cout<<"\n"<<__BASE_FILE__<<__LINE__<<"\n"<<x<<"\n";
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
        p.fname = "Rect.asm";
        p.openFile();

        Translator t;
        string res;
        ofstream f_write;
        string new_line = "\n";
        f_write.open("out_"+p.fname+".hack");



        /********************First_PASS*******************/
       for(string line; getline(p.fileRead, line);){
        //  if the next line is  not a white space nor a comment ;
        if(!line.empty() && p.isCommand(line)){


                // FINDING ALL THE LABELS
                if(line[0]=='(')
                {

                  line= line.substr(1,line.length()-2);

                  t.translateLabels(line);
                }else{
                  Translator::instr_counter++;
                }



        }




       }


       //clearing the pointer and pushing it back to the start of the file
        p.fileRead.clear();
        p.fileRead.seekg(0, ios::beg);



        /********************Second_PASS*******************/
       for(string line; getline(p.fileRead, line);){
        //  if the next line is  not a white space nor a comment ;

        if(!line.empty() && p.isCommand(line)){

            // removing extra spaces
            //INFO(line);
            line = t.trimSpaces(line);

            line = t.trimTrailingComments(line);

            t.translateSymbols(line);

            t.translateCommand(line, res);





        if(res.compare("SKIP"))
           f_write << res << "\n";
        }


      }





    }

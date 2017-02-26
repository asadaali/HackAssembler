#include<iostream>
#include<fstream>


using namespace std;


class AssemblerManager
{

public:
    fstream fileRead;
    string fname;
    string parseOut;

     /*Constructor*/
    AssemblerManager();

     /*opens the assembly file**/
    bool openFile();


     /*Closes the file*/
    void closeFile();

    /*Check if a command or comment */
   bool isCommand(string cmd);



};

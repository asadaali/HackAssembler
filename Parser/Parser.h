#include<iostream>
#include<fstream>


using namespace std;


class Parser
{

public:
    fstream fileRead;
    string fname;
    string parseOut;

     /*Constructor*/
    Parser();

     /*opens the assembly file**/
    bool openFile();

    /* heart of this class : parse the assembly file*/
    void removeWhitespaces();

     /*Closes the file*/
    void closeFile();

    /*Check if a command or comment */
   bool isCommand(string cmd);



};

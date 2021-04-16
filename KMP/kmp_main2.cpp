#include<iostream>
#include<iomanip>
#include <fstream>
#include<string>
#include<stdlib.h>
#include"String.h"
#include"String.cpp"

using namespace std;

int main()
{
ifstream infile;
infile.open("input.txt",ios::in);
if(!infile)
{
    cout<<"cannot open input file,break out";
    exit(1);
}
else
{
    int testcases=0,position=0;
    string temp;
    char trash,judge;
    infile>>testcases;
//***************************output file open****************************** 
fstream outfile;
outfile.open("output.txt",ios::out);
if(!outfile)    

    {
    cerr << "Can't open file!\n";
    exit(1);
    } 
else
{
    for (int i = 0; i < testcases; i++)
    {
        infile>>judge;
        if(judge=='s'||'S') 
        {
            infile>>trash;
            getline(infile,temp);
            char* copy=&temp[0];
            String copy_s(copy);
            
//***********************************************************

            infile>>judge;
            if(judge=='p'||'P') 
            {
            infile>>trash;
            getline(infile,temp);
            char* copy=&temp[0];
            String copy_p(copy);
            copy_p.fail();
//***************************************
            position=copy_s.fastfind(copy_p);
            int j=i+1;
            outfile<<"test cases:"<<j<<" is "<<position<<endl;

            }

            else 
            {
            cerr<<"format of input file error"<<endl;
            exit(1);
            }
        
        }
        else 
        {
            cerr<<"format of input file error"<<endl;
            exit(1);
        }
        
    }
    

infile.close();
system("PAUSE");
return 0;
}
}

}

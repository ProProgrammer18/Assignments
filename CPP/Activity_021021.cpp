#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    fstream myfile;
    myfile.open("wce.txt",ios::out);
    if(!myfile)
    {
        cout<<"File not created !!";
    }
    else
    {
        cout<<"File created successfully !";
        myfile<<"WCE 2021";
        myfile.close();
    }
return 0;
}
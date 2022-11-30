#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    fstream myfile;
    myfile.open("sample.txt",ios::in);
    if(!myfile)
    cout<<"No such file";
    else
    {
        char ch;
        while(1)
        {
            myfile>>ch;
            if(myfile.eof())
            break;
            cout<<ch;
        }
        
    }
        myfile.close();
return 0;
}
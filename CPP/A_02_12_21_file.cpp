//PRN : 2020BTEIT00041
//File Handling

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("Story.txt");
   
    char s[100];
    int c=0;
    int c2=0;
   
    while(!myfile.eof())
    {
        myfile.getline(s,100);
        if(s[0]!='A')
        {
            c++;
        }
        else if(s[0]=='A'&&s[1]==' ')
        {
            c2++;
        }
    }
   
    cout<<"Number of lines not starting with 'A' are:"<<c<<endl;
   
    myfile.close();
    return 0;
}
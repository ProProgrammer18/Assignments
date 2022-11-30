/*
    PRN: 2020BTEIT00041
    Name: Om Vivek Gharge
*/

#include<bits/stdc++.h>
using namespace std;

class Student 
{
    public:
    string name;
    int roll;
    Student()
    {
        cout<<"Enter the name of Student : "<<endl;
        cin>>name;
        cout<<"Enter the roll of Student : "<<endl;
        cin>>roll;
    }
    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Roll no. : "<<roll<<endl;
    }
};

class test : virtual public Student
{
    public:
    int marks;
    test(){};
    void getmarks()
    {
        cout<<"Enter the marks of Student : "<<endl;
        cin>>marks;
    }
    void displaytest()
    {
        cout<<"The marks obtained in the test are : "<<marks<<endl;

    }
};

class sports : virtual public Student
{
    public:
    int score;
    sports(){};
    void getscore()
    {
        cout<<"Enter the score of Student in sports : "<<endl;
        cin>>score;
    }
    void displaysports()
    {
        cout<<"The score obtained in sports is : "<<score<<endl;

    }
};

class result : public test,public sports
{
    public:
    int total;
    void displaytotal()
    {
        total = marks + score;
        cout<<"The Total of score and marks obtained by student is : "<<total<<endl;
        cout<<"The Average of score and marks obtained by student is : "<<total/2.0<<endl;
    }
    void final()
    {
        cout<<"\n\n--------------RESULT--------------"<<endl;
        display();
        displaytest();
        displaysports();
        displaytotal();
        cout<<"----------------------------------"<<endl;
        cout<<"----------------------------------"<<endl;
    }
};

int main()
{   
    result s;
    s.getmarks();
    s.getscore();
    s.final();

    return 0;   
}
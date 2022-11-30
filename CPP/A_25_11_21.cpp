/*
    PRN: 2020BTEIT00041
    Virtual Base Class:
*/

#include<bits/stdc++.h>
using namespace std;

class student                               //Base Class
{
    public:
    int roll;
    string name;
    void get_name();
    void put_name();
    void get_number();
    void put_number();

};

void student::get_name()
{
    string s;
    cout<<"Enter the name of the student: "<<endl;
    cin>>s;
    name = s;
}

void student::put_name()
{
    cout<<"Name of the student: "<<name<<endl; 
}

void student::get_number()
{
    int r;
    cout<<"Enter the roll no. of the student: "<<endl;
    cin>>r;
    roll = r;
}

void student::put_number()
{
    cout<<"Roll no. of the student: "<<roll<<endl; 
}

class test : virtual public student                     // Derieved Class
{
    public:
    int t1,t2;
    void get_marks();
    void put_marks();
    
};

void test::get_marks()
{
    int T1,T2;
    cout<<"Enter the Marks of the student: "<<endl;
    cout<<"T1: ";
    cin>>T1;
    cout<<"T2: ";
    cin>>T2;
    t1=T1;
    t2=T2;
}

void test::put_marks()
{
    cout<<"The marks of the student in T1 are : "<<t1<<endl; 
    cout<<"The marks of the student in T2 are : "<<t2<<endl; 
}

class sports : virtual public student                           // Derieved Class
{
    public:
    int score;
    void get_score();
    void put_score();
};

void sports::get_score()
{
    int s;
    cout<<"Enter the Score of the student in sports: "<<endl;
    cin>>s;
    score=s;
}

void sports::put_score()
{
    cout<<"The Score of the student in sports is : "<<score<<endl; 
}

class result : public test,public sports                        // Derieved Class
{
    public:
    int total;
    void getEverything();
    void display();

};

void result::getEverything()
{
    get_name();
    get_number();
    get_marks();
    get_score();
}

void result::display()
{
    cout<<"\n\n";
    cout<<"-----------------Result-----------------\n";
    put_name();
    put_number();
    put_marks();
    put_score();
    cout<<"The Total of marks and score : "<<(t1+t2+score)<<endl;
    cout<<"----------------------------------------\n";
    cout<<"----------------------------------------\n";

}

int main()
{
    result s1;
    s1.getEverything();
    s1.display();
   
return 0;
}
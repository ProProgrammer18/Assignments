#include<iostream>
using namespace std;

class box{

    int l,b,h;
    public:
    void data(void);
    int volume(void);

};

int box::volume()
{
    return l*b*h;
}

void box::data(void){
    cout<<"Enter the length, breadth and height of the box respectively: ";
    cin>>l>>b>>h;
}

int main()
{
    box b1;
    b1.data();
    cout<<"The volume of box b1 is "<<b1.volume();

return 0;
}
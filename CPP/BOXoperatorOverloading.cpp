#include<bits/stdc++.h>
using namespace std;

class Box
{
    public:
    int l,b,h,vol;
    Box(int x=0,int y=0,int z=0)
    {
        l=x;
        b=y;
        h=z;
        vol=x*y*z;
    }

    Box operator + (Box const &obj)
    {
        Box res;
        res.vol = vol + obj.vol;
        return res;
    }

    Box operator - (Box const &obj)
    {
        Box res;
        res.vol = abs(vol - obj.vol);
        return res;
    }
    Box operator * (Box const &obj)
    {
        Box res;
        res.vol = vol*(obj.vol) ;
        return res;
    }

};

int main()
{
    Box b1(1,2,3),b2(4,5,6),sum,sub,mult;

    sum = b1 + b2;
    sub = b1 - b2;
    mult = b1 * b2;


    cout<<"The volumes of both the cubes are "<<b1.vol<<" and "<<b2.vol<<endl
        <<"The addition of the volumes is "<<sum.vol<<endl
        <<"The substraction of the volumes is "<<sub.vol<<endl
        <<"The multiplication of the volumes is "<<mult.vol<<endl;

return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Ackermann(int y, int x)
{
    if(!y)
    {
        return (x + 1);
    }
    else if((y>0) && (!x))
    {
        return Ackermann(y-1, 1);
    }
    else if((y>0) && (x>0))
    {
        return Ackermann(y-1, Ackermann(y, x-1));
    }
}
int main()
{
    int ack, y, x;
    cin>>y>>x;
    ack = Ackermann(y, x);
    cout<<ack<<endl;
    return 0;
}
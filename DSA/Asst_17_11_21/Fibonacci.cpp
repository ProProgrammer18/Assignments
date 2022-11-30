/*
    Name: Om Vivek Gharge
    PRN : 2020BTEIT00041
    Batch: S3

    Program: Fibonacci series using recursion
*/

#include<iostream>
using namespace std;

int Fibonacci(int n)
{
    if((n == 1) || (n==0))
    {
        return (n);
    }
    else
    {
        return (Fibonacci(n-1)+Fibonacci(n-2));
    }
}

int main()
{

    int n;
    cout<<"Enter the no. of terms to be displayed: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {

    cout<<" "<<Fibonacci(i);

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

template <typename T>
void bubblesort(T *array,int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
        
    }
    
}


int main()
{
    int size;
    cin>>size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    bubblesort<int>(a,size);

     for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<endl;
    }
return 0;
}
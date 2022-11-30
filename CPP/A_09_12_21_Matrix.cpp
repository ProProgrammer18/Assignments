#include<bits/stdc++.h>
using namespace std;

const int n=3;

template <typename T>

void matrixadd(T ar1[][n],T ar2[][n],T ar3[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ar1[i][j]+ar2[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

template <typename T>

void matrixsub(T ar1[][n],T ar2[][n],T ar3[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ar1[i][j]-ar2[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

template <typename T>

void matrixmulti(T ar1[][n],T ar2[][n],T ar3[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ar3[i][j]=0;
        }
        
    }
    

    for (int i = 0; i < n; i++)
    {
    int sum=0;
        for (int j = 0; j < n; j++)
        {   
            for (int k = 0; k < n; k++)
            {
                ar3[i][j]+=ar1[i][k]*ar2[k][j];
            }
            
            // cout<<ar3[i][j]<<" ";
            printf("%5d ",ar3[i][j]);
            
        }
        cout<<endl;
    }
    
}

int main()
{
   
    int ar1[n][n],ar2[n][n],ar3[n][n];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>ar1[i][j];
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>ar2[i][j];
        }
        
    }

    cout<<"\n\n";
    cout<<"Addition: \n";
    matrixadd<int>(ar1,ar2,ar3);
    cout<<"\n\n";
    cout<<"Substraction: \n";
    matrixsub<int>(ar1,ar2,ar3);
    cout<<"\n\n";
    cout<<"Multiplication: \n";
    matrixmulti<int>(ar1,ar2,ar3);
    
return 0;
}
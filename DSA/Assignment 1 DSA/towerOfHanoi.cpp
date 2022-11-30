// Program for Tower Of Hanoi

#include <iostream>

using namespace std;
int count=0;
void TowerOfHanoi(int n, char src, char dest, char helper){
    
    if(n == 0){
        return;
    }

    TowerOfHanoi(n-1, src, helper, dest);
    cout <<(++count)<< ". move disk "<<n<<" from " << src << " to " << dest << endl;
    TowerOfHanoi(n-1, helper, dest, src);
}

int main(){

    int height;
    cin >> height;

    TowerOfHanoi(height, 'A', 'C', 'B');

    return 0;

}
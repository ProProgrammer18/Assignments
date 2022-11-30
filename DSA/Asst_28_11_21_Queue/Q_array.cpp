/*
    PRN: 2020BTEIT00041
    Name: Om Vivek Gharge
*/

/*
    Queue using Array implementation
*/

#include <iostream>

using namespace std;

#define n 100

class queue
{
public:
    int bottom;
    int *arr;
    queue()
    {
        arr = new int[n];
        bottom = 0;
    }

    void enqueue(int data)
    {
        if (bottom == n)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            arr[bottom] = data;
            bottom++;
        }
        return;
    }

    void dequeue()
    {
        if (bottom == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < bottom - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            bottom--;
        }
        return;
    }

    void displayqueue()
    {
        for (int i = 0; i < bottom; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
};

int main()
{
    queue q1;

    int a = 0;

    while (a != 4)
    {
        cout << "---------------------Menu---------------------\n";
        cout << "1. Enqueue" << endl
             << "2. Dequeue" << endl
             << "3. Display" << endl
             << "4. Exit" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            int data;
            cout << "Enter data : " << endl;
            cin >> data;
            q1.enqueue(data);
            break;

        case 2:
            q1.dequeue();
            break;

        case 3:
            q1.displayqueue();
            break;

        case 4:
            cout << "exited" << endl;
            break;

        default:
            cout << "Enter Valid choice" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <math.h>

using namespace std;
int u=0;
class Node
{
public:
    int coeff;
    int exp;
    Node *next;
};

class linkedList
{
public:
    Node *first = NULL;

    linkedList();
    ~linkedList();
    void display1();
    void display2();

    double evaluate1(int x);
    double evaluate2(int x);

};

linkedList::linkedList()
{
	u++;
	if()
	{
	cout<<"Enter the data of polynomial "<<u<<endl;
    Node *last = NULL, *t;
    int n;
    cout << "Enter the numbers of terms" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        t = new Node;

        cout << "Enter the coeff and exp" << endl;
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if (!first)
        {
            first = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
	}
};

linkedList::~linkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void linkedList::display1()
{
    Node *p = first;
    while (p)
    {
		if(p->next)
		{
        cout << p->coeff << "x^" << p->exp << " + ";
        p = p->next;
		}
		else
		{
        cout << p->coeff << "x^" << p->exp;
        p = p->next;
		}


    }
    cout << endl;
}

void linkedList::display2()
{
    Node *p = first;
    while (p)
    {
		if(p->next)
		{
        cout << p->coeff << "x^" << p->exp << " - ";
        p = p->next;
		}
		else
		{
        cout << p->coeff << "x^" << p->exp;
        p = p->next;
		}


    }
    cout << endl;
}

double linkedList ::evaluate1(int x)
{

    int sum = 0;
    Node *p = first;

    while (p)
    {
        sum += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return sum;
}

double linkedList ::evaluate2(int x)
{

    int sub = 0;
	int count =0;
    Node *p = first;

    while (p)
    {
		if(count)
		{
        sub -= p->coeff * pow(x, p->exp);
        p = p->next;
		}
		else
		{
			sub = p->coeff * pow(x, p->exp);
        	p = p->next;
			count++;
		}
    }
    return sub;
}

int main()
{

    linkedList l1,l2;

    cout << "Displaying the polynomial\n";
    l1.display1();
    l2.display1();

	// l.display2();
    cout << "\nEvaluating the polynomial by adding the value of x variable\n";
	cout<<"\nEnter the value of x: "<<endl;
	int x;
	cin>>x;
    cout << "Addition : "<<l1.evaluate1(x)<<endl;
    cout << "Substraction : "<<l1.evaluate2(x)<<endl;



    return 0;
}
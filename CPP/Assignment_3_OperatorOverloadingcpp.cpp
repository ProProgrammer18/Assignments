

#include <iostream>
#include <cmath>
using namespace std;
class Time
{
    int h, m, s;

public:
    Time()
    {
        h = 0, m = 0;
        s = 0;
    }
    void setTime();
    void show()
    {
        cout << h << ":" << m << ":" << s;
    }

    Time operator+(Time);
    Time operator-(Time);
    void operator--(int);
    void operator++(int);
};

Time Time::operator+(Time t1) // operator function
{
    Time t;
    int a, b;
    a = s + t1.s;
    t.s = a % 60;
    b = (a / 60) + m + t1.m;
    t.m = b % 60;
    t.h = (b / 60) + h + t1.h;
    t.h = t.h % 12;
    return t;
}
Time Time::operator-(Time t1) // operator function
{
    Time t;
    int a, b;
    a = abs(s - t1.s);
    t.s = a % 60;
    b = abs((a / 60) + m - t1.m);
    t.m = b % 60;
    t.h = abs((b / 60) + h - t1.h);
    t.h = t.h % 12;
    return t;
}

void Time::operator--(int x)
{
    int t = s;
    t = t - 1;
    if (t < 0)
    {
        int m_r = m;
        m_r = m_r - 1;
        if (m_r < 0)
        {
            int h_r = h - 1;
            if (h_r < 0)
            {
                s = 59;
                m = 59;
                h = 11;
                return;
            }
            m = 59;
            s = 59;
            h = h - 1;
            return;
        }
        m = m - 1;
        s = 59;
        return;
    }
    s = s - 1;
}

void Time::operator++(int x)
{
    int t = s;
    t = t + 1;
    if (t > 59)
    {
        int m_r = m;
        m_r = m_r + 1;
        if (m_r > 59)
        {
            int h_r = h - 1;
            if (h_r > 11)
            {
                s = 0;
                m = 0;
                h = 0;
                return;
            }
            m = 0;
            s = 0;
            h = h + 1;
            return;
        }
        m = m + 1;
        s = 0;
        return;
    }
    s = s + 1;
}

void Time::setTime()
{
    cout << "\n Enter the hour(0-11) ";
    cin >> h;
    cout << "\n Enter the minute(0-59) ";
    cin >> m;
    cout << "\n Enter the second(0-59) ";
    cin >> s;
}

int main()
{
    Time t1, t2, t3;

    cout << "\n Enter the first time ";
    t1.setTime();
    cout << "\n Enter the second time ";
    t2.setTime();
    t3 = t1 - t2;
    cout << "\n First time: ";
    t1.show();
    cout << "\n Second time: ";
    t2.show();
    cout << "\n Diff of times: ";
    t3.show();
    cout << "\n";
	cout << "After incrementing: \n";
    t1++;
    t1.show();
	t2--;
	cout<< "\n After decrementing: \n";
	t2.show();
    cout << endl;

    return 0;
}


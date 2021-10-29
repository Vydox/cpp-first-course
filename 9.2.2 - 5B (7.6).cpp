#include <iostream>
#include <time.h>
#include <list>

using namespace std;


void add_ALL(list<int>& top, int n);
void output(list<int>& top);
int sum(list<int>& top);


int main()
{
    srand(time(NULL));

    int n;
    cout << "Enter n: ";
    cin >> n;

    list<int> top;
    add_ALL(top, n);
    output(top);

    cout << endl;

    cout << "Sum = " << sum(top);
}


void add_ALL(list<int>& top, int n) {   //Спіс па ўзрастанні
    for (int i = 0; i < 2 * n; i++) {
        int num = rand() % 5 + 1;
        top.push_back(num);
    }
}

void output(list<int>& top)
{
    list<int>::iterator p = top.begin();
    while (p != top.end())
    {
        cout << *p << " ";
        ++p;
    }
    cout << endl;
}

int sum(list<int>& top) {
    int sum = 1;
    list<int>::iterator p_b = top.begin();
    list<int>::reverse_iterator p_e = top.rbegin();
    while (p_b != top.end() && p_e != top.rend()) {
        int a = *p_b;
        int b = *p_e;
        sum *= (a - b);
        (p_b++)++;
        (p_e++)++;
    }
    return sum;
}
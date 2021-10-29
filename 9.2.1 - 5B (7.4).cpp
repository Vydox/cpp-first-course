#include <iostream>
#include <time.h>
#include <list>

using namespace std;

void add_ALL(list<char>& top, int l);
void output(list<char>& top);
void fin_list(list<char>& top1, list<char>& top2, list<char>& top3);

int main()
{
    srand(time(NULL));
    int l1, l2;
    cout << "Enter lists' lengths" << endl;
    cin >> l1 >> l2;


    list<char> top1; //Першы спіс
    add_ALL(top1, l1);
    top1.sort();
    output(top1);

    cout << endl;

    list<char> top2; //Другі спіс
    add_ALL(top2, l2);
    top2.sort();
    output(top2);

    cout << endl;

    list<char> top3; //Выніковы спіс
    fin_list(top1, top2, top3);
    output(top3);
}

/*void add(Node*& top, char a) {   //Спіс па ўзрастанні
    Node* ppv = NULL;
    Node* nv = new Node;
    nv->data = a;
    nv->pointer = NULL;
    if (!top)
        top = nv;
    else {
        if (top->data >= a) {
            nv->pointer = top;
            top = nv;
        }
        else
        {
            find(top, ppv, a); //Пошук месца для ўстаўкі
            nv->pointer = ppv->pointer;
            ppv->pointer = nv;
        }

    }
}*/

void add_ALL(list<char>& top, int l) {   //Спіс па ўзрастанні
    for (int i = 0; i < l; i++) {
        char a = rand() % 10 + 33;
        top.push_back(a);
    }
}

/*void find(Node* top, Node*& ppv, char symb) {
    Node* pv = top;
    ppv = top;
    //Пошук элемента з ключом > key
    while (pv && pv->data <= symb)
    {
        ppv = pv; //Адрас папярэдняга элемента
        pv = pv->pointer; //Пераход да наступнага элемента
    }

}*/

void output(list<char>& top)
{
    list<char>::iterator p = top.begin();
    while (p != top.end())
    {
        cout << *p;
        ++p;
    }
    cout << endl;
}

void fin_list(list<char>& top1, list<char>& top2, list<char>& top3) {
    list<char>::iterator p1 = top1.begin();
    list<char>::iterator p2 = top2.begin();
    while (p1 != top1.end() && p2 != top2.end()) {
        char a = *p1;
        char b = *p2;

        if (a < b) {
            top3.push_back(a);
            p1++;
            while (p1 != top1.end() && *p1 == a) { // && top1
                p1++;
            }
        }
        else
        {
            top3.push_back(b);
            p2++;
            while (p2 != top2.end() && *p2 == b) {
                p2++;
            }
            if (a == b) {
                while (p1 != top1.end() && *p1 == a) {
                    p1++;
                }
            }
        }
    }
    while (p1 != top1.end()) {
        char a = *p1;
        top3.push_back(a);
        p1++;
        while (p1 != top1.end() && *p1 == a) { // && top1
            p1++;
        }
    }
    while (p2 != top2.end()) {
        char b = *p2;
        top3.push_back(b);
        p2++;
        while (p2 != top2.end() && *p2 == b) { // && top2
            p2++;
        }
    }


}
#include <iostream>
#include <time.h>

using namespace std;


struct Node
{
    int data;
    Node* next; 
    Node* prev; 
};

void find(Node* top, Node*& ppv, int key);
void add(Node*& top, Node*& end, int key);
void add_ALL(Node*& top, Node*& end, int n);
void output(Node* top);
int sum(Node* top, Node* end);


int main()
{
    srand(time(NULL));

    int n;
    cout << "Enter n: ";
    cin >> n;

    Node* top = NULL;
    Node* end = NULL;
    add_ALL(top, end, n);
    output(top);

    cout << endl;

    cout << "Sum = " << sum(top, end);
}

void find(Node* top, Node*& ppv, int key) {
    Node* pv = top;
    ppv = top;
    //Пошук элемента з ключом > key
    while (pv && pv->data <= key)
    {
        ppv = pv; //Адрас папярэдняга элемента
        pv = pv->next; //Пераход да наступнага элемента
    }

}

void add(Node*& top, Node*& end, int key) //Дадаванне элемента па ўзрастанні
{
    Node* pv = NULL, * ppv = NULL;
    Node* nv = new Node;
    nv->data = key;
    nv->next = NULL;
    nv->prev = NULL;
    if (!top)   //Першы элемент спісу
    {
        top = nv; 
        end = nv;
    }
    else
    {
        if (top->data >= key)
        {
            nv->next = top;
            top->prev = nv;
            top = nv;
        }
        else
        {
            find(top, ppv, key); //Пошук новага месца для элемента
            pv = ppv->next;
            nv->next = pv;  //Устаўка элемента на патрэбнае месца 
            nv->prev = ppv;
            if (pv)
                pv->prev = nv;
            else
                end = nv;
            ppv->next = nv;
        }
    }
}

void add_ALL(Node*& top, Node*& end, int n) {   //Спіс па ўзрастанні
    for (int i = 1; i <= 2*n; i++) {
        int num = rand() % 5 + 1;
        add(top, end, num);
    }
}

void output(Node* top)
{
    while (top) {
        cout << top->data << ' ';
        top = top->next;
    }
}

int sum(Node* top, Node* end) {
    int sum = 1;
    while (top && end) {
        int a = top->data;
        int b = end->data;
        sum *= (a + b);
        top = top->next;
        top = top->next;
        end = end->prev;
        end = end->prev;
    }
    return sum;
}
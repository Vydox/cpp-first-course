#include <iostream>
#include <time.h>

using namespace std;

struct Node {
    char data;
    Node* pointer;
};

void add(Node*& top, char a);
void add_ALL(Node*& top, int l);
void output(Node* top);
void fin_list(Node* top1, Node* top2, Node*& top3);
void find(Node* top, Node*& ppv, char symb);

int main()
{   
    srand(time(NULL));
    /*for (int i = 1; i <= 10; i++) {
        char a = rand() % 64 + 33;
        cout << a << " ";
    }
    cout << endl;*/
    int l1, l2;
    cout << "Enter lists' lengths" << endl;
    cin >> l1 >> l2;


    Node* top1 = NULL; //Першы спіс
    add_ALL(top1, l1);
    output(top1);

    cout << endl;

    Node* top2 = NULL; //Другі спіс
    add_ALL(top2, l2);
    output(top2);

    cout << endl;

    Node* top3 = NULL; //Выніковы спіс
    fin_list(top1, top2, top3);
    output(top3);
}

void add(Node*& top, char a) {   //Спіс па ўзрастанні
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
}

void add_ALL(Node*& top, int l) {   //Спіс па ўзрастанні
    for (int i = 0; i < l; i++) {
        char a = rand() % 10 + 33;
        add(top,a);
    }
}

void find(Node* top, Node*& ppv, char symb) {
    Node* pv = top;
    ppv = top;
    //Пошук элемента з ключом > key
    while (pv && pv->data <= symb)
    {
        ppv = pv; //Адрас папярэдняга элемента
        pv = pv->pointer; //Пераход да наступнага элемента
    }

}

void output(Node* top)
{
    while (top) {
        cout << top->data << ' ';
        top = top->pointer;
    }
}

void fin_list(Node* top1, Node* top2, Node*& top3) {
    while (top1 && top2) {
        char a = top1->data;
        char b = top2->data;

        if (a < b) {
                add(top3, a);
                top1 = top1->pointer;
                while (top1 && top1->data == a) { // && top1
                    top1 = top1->pointer;
                }
        }
        else
        {
            add(top3, b);
            top2 = top2->pointer;
            while (top2 && top2->data == b) {
                top2 = top2->pointer;
            }
            if (a == b) {
                while (top1 && top1->data == a) {
                    top1 = top1->pointer;
                }
            }
        }
    }
    while (top1) {
        char a = top1->data;
        add(top3, a);
        top1 = top1->pointer;
        while (top1 && top1->data == a) { // && top1
            top1 = top1->pointer;
        }
    }
    while (top2) {
        char b = top2->data;
        add(top3, b);
        top2 = top2->pointer;
        while (top2 && top2->data == b) { // && top2
            top2 = top2->pointer;
        }
    }


}
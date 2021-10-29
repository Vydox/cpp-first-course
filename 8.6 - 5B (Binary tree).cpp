#include <iostream>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
};

class BTree {
private:
    Tree* top;
public:
    BTree() {
        top = NULL;
    }
    /*BTree(int n) {
        Tree* pnew = new Tree;
        pnew->data = n;
        pnew->left = NULL;
        pnew->right = NULL;
        top = pnew;
    }*/
    BTree(int num) {
        for (int i = 1; i <= num; i++) {
            int n = rand() % 10;
            add(n);
        }
    }

    void add(int n) {
        Tree* pnew = new Tree;
        pnew->data = n;
        pnew->left = NULL;
        pnew->right = NULL;
        if (!top)
            top = pnew;
        else
        {
            Tree* pv = top;
            Tree* ppv = top;
            while (pv)
            {
                ppv = pv;
                if (n < pv->data)
                    pv = pv->left;
                else
                    pv = pv->right;
            }
            if (n < ppv->data)
                ppv->left = pnew; //Дадаем у левую галiну
            else
                ppv->right = pnew;  //У правую
        }
    }
};

int main()
{
 
}

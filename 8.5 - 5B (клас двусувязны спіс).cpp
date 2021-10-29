#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class List {
private:
    Node* top;
    Node* end;
public:
    List() {
        top = NULL;
        end = NULL;
    }
    List(int n) {
        Node* nv = new Node;
        nv->data = n;
        nv->next = NULL;
        nv->prev = NULL;
        top = nv;
        end = nv;
    }
    List(int num, char s[13]) {
        for (int i = 1; i <= 2 * num; i++) {
            int n = rand() % 10 + 1;
            add(n);
        }
        cout << s << endl;
    }
    List(List& top1) {
        Node* pv = top1.top;
        while (pv) {
            add(pv->data);
            pv = pv->next;
        }
    }
    ~List() {
        del_total();
        cout << "Deleting completed" << endl;
    }

    void add(int n) {   //Спіс па ўзрастанні
        Node* pv = NULL, * ppv = NULL;
        Node* nv = new Node;
        nv->data = n;
        nv->next = NULL;
        nv->prev = NULL;
        if (!top)   //Першы элемент спісу
        {
            top = nv;
            end = nv;
        }
        else
        {
            if (top->data >= n)
            {
                nv->next = top;
                top->prev = nv;
                top = nv;
            }
            else
            {
                pv = top;
                ppv = top;
                //Пошук элемента з ключом > n
                while (pv && pv->data <= n)
                {
                    ppv = pv; //Адрас папярэдняга элемента
                    pv = pv->next; //Пераход да наступнага элемента
                }
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
    void output()
    {
        Node* pv = top;
        while (pv) {
            cout << pv->data << ' ';
            pv = pv->next;
        }
        cout << endl;
    }
    void find_user(int n) {
        Node* pv = top;
        bool found = false;
        while (pv) {
            if (pv->data = n) {
                cout << "Found" << endl;
                found = true;
                break;
            }
            pv = pv->next;
        }
        if (found == false) {
            cout << "Not found" << endl;
        }
    }
    int result() {
        int res = 1;
        while (top && end) {
            int a = top->data;
            int b = end->data;
            res *= (a - b);
            top = top->next;
            top = top->next;
            end = end->prev;
            end = end->prev;
        }
        return res;
    }
    void del(int n)
    {
        Node* ps = top;
        Node* pps = end;
        while (ps) {
            Node* pv, * ppv;
            if (top->data == n) // удаляем первый элемент
            {
                pv = ps;
                ps = ps->next;
                if (ps)
                    ps->prev = NULL;
                else
                    pps = NULL;
                delete pv; // освобождение памяти
                return;
            }
            ppv = find(n);
            pv = ppv->next;
            if (!pv) // если не нашли
                return; // то нечего тут больше делать
                // нашли - удаляем элемент из середины или конца списка
            ppv->next = pv->next;
            if (pv->next)
                pv->next->prev = ppv;
            else
                pps = ppv; // если последний элемент
            delete pv; // освобождение памяти
        }
    }
    void del_total() {
        Node* ppv = top;
        while (top) {
            ppv = top;
            top = top->next;
            delete ppv;
        }
    }
    Node*& find(int n) {		//Пошук элемента з патрэбным значэннем
        Node* pv = top;
        Node* ppv = top;
        while (pv && pv->data != n)
        {
            ppv = pv;
            pv = pv->next;
        }
        return ppv;
    }
};

int main()
{
    char s[] = "List created";
    int num;
    cout << "Enter number: ";
    cin >> num;
    List top(num, s);
    top.output();
    cout << endl;
    cout << "Result: " << top.result() << endl;
    
    return 0;
}

#include <iostream>
#include <time.h>

using namespace std;

struct Node {
	char data;
	Node* pointer;
};

class List {
private: 
	Node* top;
public:
	List() {
		top = NULL;
	}
	List(char a) {
		Node* nv = new Node;
		nv->data = a;
		nv->pointer = NULL;
		top = nv;
	}
	List(int n) {
		for (int i = 0; i < n; i++) {
			char a = rand() % 10 + 33;
			add(a);
		}
	}
	List(List& top1) {
		Node* pv = top1.top;
		while (pv) {
			add(pv->data);
			pv = pv->pointer;
		}
	}
	~List() {
		Node* ppv = top;
		while (top) {
			ppv = top;
			top = top->pointer;
			delete ppv;
		}
		cout << "Termination completed" << endl;
	}

	void add(char a) {   //Спіс па ўзрастанні
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
				Node* pv = top;
				ppv = top;
				//Пошук элемента з ключом > key
				while (pv && pv->data <= a)
				{
					ppv = pv; //Адрас папярэдняга элемента
					pv = pv->pointer; //Пераход да наступнага элемента
				}
				nv->pointer = ppv->pointer;
				ppv->pointer = nv;
			}

		}
	}
	bool find_user(char a) {
		Node* pv = top;
		while (pv) {
			if (pv->data = a) {
				return true;
				break;
			}
			pv = pv->pointer;
		}
		return false;
	}
	Node*& find(char a) {		//Пошук элемента з патрэбным значэннем
		Node* pv = top;
		Node* ppv = top;
		while (pv && pv->data != a)
		{
			ppv = pv;
			pv = pv->pointer;
		}
		return ppv;
	}
	void del(char a) {		//Выдаленне неабходнага элемента
		Node* ps = top;
		while (ps) {
			if (!ps)
				return;
			Node* ppv = find(a);
			if (ppv == ps && ps->data == a)
			{
				ps = ps->pointer;
				delete ppv;
				return;
			}
			Node* pv = ppv->pointer;
			if (!pv)
				return;
			ppv->pointer = pv->pointer;
		}
	}
	void output()
	{
		Node* pv = top;
		while (pv) {
			cout << pv->data << ' ';
			pv = pv->pointer;
		}
	}
	void fin(List& top1, List& top2) {
		while (top1.top && top2.top) {
			char a = top1.top->data;
			char b = top2.top->data;

			if (a < b) {
				add(a);
				top1.top = top1.top->pointer;
				while (top1.top && top1.top->data == a) {
					top1.top = top1.top->pointer;
				}
			}
			else
			{
				add(b);
				top2.top = top2.top->pointer;
				while (top2.top && top2.top->data == b) {
					top2.top = top2.top->pointer;
				}
				if (a == b) {
					while (top1.top && top1.top->data == a) {
						top1.top = top1.top->pointer;
					}
				}
			}
		}
		while (top1.top) {
			char a = top1.top->data;
			add(a);
			top1.top = top1.top->pointer;
			while (top1.top && top1.top->data == a) {
				top1.top = top1.top->pointer;
			}
		}
		while (top2.top) {
			char b = top2.top->data;
			add(b);
			top2.top = top2.top->pointer;
			while (top2.top && top2.top->data == b) {
				top2.top = top2.top->pointer;
			}
		}
	}
};

int main()
{
	/*char a = 'a';
	list top1('b');
	top1.output();
	top1.add('d');
	top1.add('c');
	top1.output();*/
	
	int l1, l2;
	cout << "Enter length" << endl;
	cin >> l1 >> l2;

	List top1(l1);
	top1.output();

	cout << endl;

	List top2(l2);
	top2.output();

	cout << endl;

	top1.del('(');
	top2.del(')');
	top1.output();
	cout << endl;
	top2.output();
	cout << endl;

	/*List top3;
	top3.fin(top1, top2);
	top3.output();
	cout << endl;*/
	return 0;
}

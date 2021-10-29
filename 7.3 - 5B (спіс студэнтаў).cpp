#include <iostream>
#include <string>

using namespace std;

struct students {
    char name[20];
    int age;
    int course;
    double grades;
};

struct Node {
    students data;
    Node* pointer;
};



students struct_fill();
void struct_out(students student);
void add(Node*& top, students student);
void find_place(Node* top, Node*& ppv, students student);
void find_course(Node* top, int n, Node*& ppv);
void output(Node* top);
void del(Node*& top, int n);
void fin_list(Node* top, Node*& top_fin, int n);

int main()
{
    Node* top = NULL;

    int num;
    cout << "Enter number of students: ";
    cin >> num;
    
    for (int i = 1; i <= num; i++) {
        students student = struct_fill();   //Запаўняем структуру дадзенымі
        add(top, student);      //Ствараем агульны спіс студэнтаў
    }
    output(top);

    /////////////////////////////////////////////////////

    int n;      //Неабходны курс
    cout << "Enter required course: ";
    cin >> n;
    cout << endl << endl;

    
    Node* top_fin = NULL;
    fin_list(top, top_fin, n);      //Ствараем спіс студэнтаў неабходнага курса
    cout << "Required list" << endl << endl;
    output(top_fin);

    cout << endl << endl << endl;
    
    del(top, n);        //Выдаляем неабходных студэнтаў са старога спіса
    cout << "Changed list" << endl << endl;
    output(top);
    
    return 0;
}

students struct_fill() {
    students student;
    cin.get();
    cout << "Enter name: ";
    cin.getline(student.name, 20);
    cout << "Enter age: ";
    cin >> student.age;
    cout << "Enter course: ";
    cin >> student.course;
    cout << "Enter grades: ";
    cin >> student.grades;
    cout << endl;
    return student;
}

void struct_out(students student) {
    cout << student.name << endl << student.age << endl << student.course << endl << student.grades << endl;
}

void add(Node*& top, students student) {   //Спіс па ўзрастанні прозвішчаў
    Node* ppv = NULL;
    Node* nv = new Node;
    nv->data = student;
    nv->pointer = NULL;
    if (!top)
        top = nv;
    else {
        if (top->data.name[0] >= student.name[0]) {
            nv->pointer = top;
            top = nv;
        }
        else
        {
            find_place(top, ppv, student); //Пошук месца для ўстаўкі
            nv->pointer = ppv->pointer;
            ppv->pointer = nv;
        }

    }
}

void find_place(Node* top, Node*& ppv, students student) {
    Node* pv = top;
    ppv = top;
    while (pv && pv->data.name[0] <= student.name[0])
    {
        ppv = pv; //Адрас папярэдняга элемента
        pv = pv->pointer; //Пераход да наступнага элемента
    }

}

void find_course(Node* top, int n, Node*& ppv)
{
    Node* pv = top;
    ppv = top;
    //поиск элемента c ключом = key
    while (pv && pv->data.course != n)
    {
        ppv = pv; // запоминаем адрес предыдущего элемента
        pv = pv->pointer;
    }
}

void del(Node*& top, int n)
{
    Node* ps = top;
    while (ps) {
        Node* ppv;
        find_course(top, n, ppv);
        if (ppv == ps && ps->data.course == n)
        {
            top = top->pointer;
            delete ppv;
            return;
        }
        Node* pv = ppv->pointer;
        if (!pv)
            return;
        ppv->pointer = pv->pointer;
        delete pv;
    }

}

void fin_list(Node* top, Node*& top_fin, int n) {
    Node* pv = top;
    while (pv) {
        students st = pv->data;
        if (st.course == n) {
            add(top_fin, st);
        }
        pv = pv->pointer;
    }
}

void output(Node* top)
{
    while (top) {
        cout
            << "Name: " << top->data.name 
            << endl 
            << "Age: " << top->data.age
            << endl 
            << "Course: " << top->data.course
            << endl 
            << "Grades: " << top->data.grades
            << endl;
        top = top->pointer;
        cout << endl << endl;
    }
}


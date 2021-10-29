#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void create_file(ofstream& tofile, int n, int r);

class Vector 
{
private:
    int* arr;
    int num;
public:
    //Канструктары
    Vector() {
        arr = NULL;
        num = NULL;
    };
    Vector(int n) {
        arr = new int[n];
        num = n;
    };
    Vector(Vector& v) {
        num = v.num;
        arr = new int[num] ;
        for (int i = 0; i < num; i++)
            arr[i] = v.arr[i];
    };
    //Метады
    void get_num() {
        cout << "Enter num: ";
        cin >> num;
        arr = new int[num];
    }
    void get_num(int n) {
        num = n;
        arr = new int[num];
    }
    int set_num() {
        return num;
    }
    void create_arr_empty() {
        for (int i = 0; i < num; i++)
            arr[i] = 0;
    }
    void count_arr(ifstream& fromfile) {
        int n;
        while (!fromfile.eof()) {
            fromfile >> n;
            for (int i = 0; i < num; i++) {
                if (i == n)
                    arr[i]++;
            }
        }
    }
    int count_extra() {
        int n = 0;
        for (int i = 0; i < num; i++)
            if (arr[i] == 1)
                n++;
        return n;
    }
    void arr_fin(Vector& v) {
        int k = 0;
        for (int i = 0; i < v.num; i++)
            if (v.arr[i] != 1)
                arr[k++] = i;
    }
    void output_arr() {
        for (int i = 0; i < num; i++)
            cout << arr[i] << " ";
    }
    //Перагрузкі аператараў
    int& operator [] (const int i) {
        if (i < 0)
            return arr[0];
        if (i >= num)
            return arr[num - 1];
        return arr[i];
    }
    friend istream& operator >> (istream& in, Vector& v)
    {
        for (int i = 0; i < v.num; i++) {
            in >> v.arr[i];
        }
        return in;
    }
    friend ostream& operator << (ostream& out, Vector& v)
    {
        for (int i = 0; i < v.num; i++) {
            out << v.arr[i] << " ";
        }
        return out;
    }

};



int main()
{
    srand(time(NULL));
    
    int n = 20; //Колькасць лічбаў у файле

    cout << "Enter range: ";
    int r;      //Дыяпазон
    cin >> r;
    
    ofstream tofile("f.txt");
    if (!tofile)
    {
        cout << "error1" << endl;
        return 1;
    }

    create_file(tofile, n, r); //Стварэнне файла
    tofile.close();

    Vector vect1(r); //Стварэнне аб'екта Vector з параметрам r+1 (масіў памеру r+1)
    vect1.create_arr_empty(); 
    
    ifstream fromfile("f.txt");
    vect1.count_arr(fromfile); //Падлік колькасці паўтораў кожнай лічбы ў дыапазоне

    //vect1.output_arr();
    cout << vect1 << endl;

    cout << endl << endl;

    Vector vect2(r - vect1.count_extra()); //Стварэнне масіва неабходнага памеру
    vect2.arr_fin(vect1);

    cout << vect2 << endl;
    //vect2.output_arr();

    cout << vect2[0] << endl;

    cout << endl << endl << endl;
   
    

    return 0;
}

void create_file(ofstream& tofile, int n, int r) {
    for (int i = 0; i < n; i++)
        tofile << rand() % r << endl;
}
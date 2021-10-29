#include <iostream>
#include <time.h>

using namespace std;

const int N = 50;
struct Stack {
	char symb[N];
	int size;
};

void add(Stack& s, char a);
void add_All(Stack& s, int n);
void output(Stack s);
void fin_list(Stack s1, Stack s2, Stack& s3);

int main()
{
	srand(time(NULL));
	
	int NUM1 = 10;
	Stack S1;
	S1.size = 0;
	add_All(S1, NUM1);
	output(S1);

	int NUM2 = 12;
	Stack S2;
	S2.size = 0;
	add_All(S2, NUM2);
	output(S2);

	Stack S3;
	S3.size = 0;
	fin_list(S1, S2, S3);
	output(S3);
}


void add(Stack& s, char a) {
	s.symb[s.size] = a;
	s.size++;
}

void add_All(Stack& s, int n) {
	for (int i = 0; i < n; i++) {
		char a = rand() % 12 + 45;
		add(s, a);
	}
}


void output(Stack s) {
	int n = s.size - 1;
	while (n >= 0) {
		cout << s.symb[n] << " ";
		n--;
	}
	cout << endl;
}

void fin_list(Stack s1, Stack s2, Stack& s3) {
	while (s1.size != 0 && s2.size != 0) {
		char a = s1.symb[s1.size];
		s1.size--;
		char b = s2.symb[s2.size];
		s2.size--;
		if (a < b) {
			add(s3, a);
			while (s1.size != 0 && s1.symb[s1.size] == a)
				s1.size--;
		}
		else {
			add(s3, b);
			while (s2.size != 0 && s2.symb[s2.size] == b)
				s2.size--;
			if (a == b) {
				while (s1.size != 0 && s1.symb[s1.size] == a)
					s1.size--;
			}
		}
	}
	while (s1.size != 0) {
		char a = s1.symb[s1.size];
		s1.size--;
		add(s3, a);
		while (s1.size != 0 && s1.symb[s1.size] == a)
			s1.size--;
	}
	while (s2.size != 0) {
		char b = s2.symb[s2.size];
		s2.size--;
		add(s3, b);
		while (s2.size != 0 && s2.symb[s2.size] == b)
			s2.size--;
	}
}
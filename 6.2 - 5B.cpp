#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>

using namespace std;


void create(ofstream& outfile, int n);
void read(ifstream& infile);
void create_pol_text(ofstream& file_pol, ifstream& infile);
void create_otr_text(ofstream& file_otr, ifstream& infile);
void create_new(ofstream& g, ifstream& file_pol, ifstream& file_otr);

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "Enter " << endl;
	cin >> n;
	if (n % 2 != 0) {
		cout << "Wrong input";
		return 0;
	}


	ofstream outfile("f.txt");
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}

	create(outfile, n); //Стварэнне файла з выпадковымі лічбамі
	outfile.close();


	ifstream infile("f.txt");
	read(infile); //Вывад файла на экран
	infile.close();

	infile.open("f.txt");
	ofstream file_pol_in("textfile_pol.txt");
	create_pol_text(file_pol_in, infile); //Стварэнне файла толькі з дадатнымі лікамі
	file_pol_in.close();
	infile.close();


	infile.open("f.txt");
	ofstream file_otr_in("textfile_otr.txt");
	create_otr_text(file_otr_in, infile); //Стварэнне файла толькі з адмоўнымі лікамі
	file_otr_in.close();
	infile.close();
	
	ofstream goutfile("g.txt");
	ifstream file_pol_out("textfile_pol.txt");
	ifstream file_otr_out("textfile_otr.txt");
	create_new(goutfile, file_pol_out, file_otr_out); //Стварэнне патрэбнага файлу
	file_pol_out.close();
	file_otr_out.close();
	goutfile.close();
	return 0;
}


void create(ofstream& outfile, int n)
{
	int lim = n / 2;
	int	pol = 0, otr = 0;
	while (pol < lim && otr < lim) {
		int v = rand() % 20 - 10;

		if (v >= 0) {
			outfile << v << endl;
			pol++;
		}
		

		if (v < 0) {
			outfile << v << endl;
			otr++;
		}
		
	}

	while (pol < lim) {
		int v = rand() % 10;
		outfile << v << endl;
		pol++;
	}
	while (otr < lim) {
		int v = -(rand() % 10);
		outfile << v << endl;
		otr++;
	}
		
}

void read(ifstream& infile)
{
	int v;
	infile >> v;
	while (!infile.fail())
	{
		cout << v << " ";
		infile >> v;
	}
	cout << endl;
}

void create_pol_text(ofstream& file_pol, ifstream& infile)
{
	int ch;
	infile >> ch;
	while (!infile.eof())
	{
		if (ch > 0)
			file_pol << ch << endl;
		infile >> ch;
	}
}

void create_otr_text(ofstream& file_otr, ifstream& infile)
{
	int ch;
	infile >> ch;
	while (!infile.eof())
	{
		if (ch < 0)
			file_otr << ch << endl;
		infile >> ch;
	}
}

void create_new(ofstream& goutfile, ifstream& file_pol_out, ifstream& file_otr_out) {
	int ch1, ch2;
	file_pol_out >> ch1;
	file_otr_out >> ch2;
	while (!file_otr_out.eof() && !file_pol_out.eof()) {
		goutfile << ch1 << ' ';
		goutfile << ch2 << ' ';
		
		file_pol_out >> ch1;
		file_otr_out >> ch2;
	}

	/*while (!file_pol_out.eof() || !file_otr_out.eof()) {
		if (k == 1) {
			file_pol_out >> ch;
			goutfile << ch << ' ';
			k = -1;
			continue;
		}
		if (k == -1) {
			file_otr_out >> ch;
			goutfile << ch << ' ';
			k = 1;
			continue;
		}
	}*/
}

/*void create_new(ofstream& goutfile, ifstream& file_pol_out, ifstream& file_otr_out, int n) {
	int k = 1;
	int ch;
	for (int i = 0; i < n; i++) {
		if (k == 1) {
			file_pol_out >> ch;
			goutfile << ch << ' ';
			k = -1;
		}
		else if (k == -1) {
			file_otr_out >> ch;
			goutfile << ch << ' ';
			k = 1;
		}
	}
}*/
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


	ofstream outfile("f.bin", ios::binary);
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}

	create(outfile, n); //Стварэнне файла з выпадковымі лічбамі
	outfile.close();


	ifstream infile("f.bin", ios::binary);
	read(infile); //Вывад файла на экран
	infile.close();

	infile.open("f.bin");
	ofstream file_pol_in("textfile_pol.bin", ios::binary);
	create_pol_text(file_pol_in, infile); //Стварэнне файла толькі з дадатнымі лікамі
	file_pol_in.close();
	infile.close();


	infile.open("f.bin");
	ofstream file_otr_in("textfile_otr.bin", ios::binary);
	create_otr_text(file_otr_in, infile); //Стварэнне файла толькі з адмоўнымі лікамі
	file_otr_in.close();
	infile.close();

	ofstream goutfile("g.bin");
	ifstream file_pol_out("textfile_pol.bin", ios::binary);
	ifstream file_otr_out("textfile_otr.bin", ios::binary);
	create_new(goutfile, file_pol_out, file_otr_out); //Стварэнне патрэбнага файлу
	file_pol_out.close();
	file_otr_out.close();
	goutfile.close();

	ifstream ginfile("g.bin", ios::binary);
	read(ginfile); //Вывад файла на экран
	ginfile.close();

	return 0;
}


void create(ofstream& outfile, int n)
{
	int lim = n / 2;
	int	pol = 0, otr = 0;
	while (pol < lim && otr < lim) {
		int v = rand() % 20 - 10;

		if (v >= 0) {
			outfile.write(reinterpret_cast <char*>(&v), sizeof(int));
			pol++;
		}


		if (v < 0) {
			outfile.write(reinterpret_cast <char*>(&v), sizeof(int));
			otr++;
		}

	}

	while (pol < lim) {
		int v = rand() % 10;
		outfile.write(reinterpret_cast <char*>(&v), sizeof(int));
		pol++;
	}
	while (otr < lim) {
		int v = -(rand() % 10);
		outfile.write(reinterpret_cast <char*>(&v), sizeof(int));
		otr++;
	}

}

void read(ifstream& infile)
{
	int v;
	infile.read(reinterpret_cast <char*>(&v), sizeof(int));
	while (!infile.fail())
	{
		cout << v << " ";
		infile.read(reinterpret_cast <char*>(&v), sizeof(int));
	}
	cout << endl;
}

void create_pol_text(ofstream& file_pol, ifstream& infile)
{
	int ch;
	infile.read(reinterpret_cast <char*>(&ch), sizeof(int));
	while (!infile.eof())
	{
		if (ch >= 0)
			file_pol.write(reinterpret_cast <char*>(&ch), sizeof(int));
		infile.read(reinterpret_cast <char*>(&ch), sizeof(int));
	}
}

void create_otr_text(ofstream& file_otr, ifstream& infile)
{
	int ch;
	infile.read(reinterpret_cast <char*>(&ch), sizeof(int));
	while (!infile.eof())
	{
		if (ch < 0)
			file_otr.write(reinterpret_cast <char*>(&ch), sizeof(int));
		infile.read(reinterpret_cast <char*>(&ch), sizeof(int));
	}
}

void create_new(ofstream& goutfile, ifstream& file_pol_out, ifstream& file_otr_out) {
	int ch1, ch2;
	file_pol_out.read(reinterpret_cast <char*>(&ch1), sizeof(int));
	file_otr_out.read(reinterpret_cast <char*>(&ch2), sizeof(int));
	while (!file_otr_out.eof() && !file_pol_out.eof()) {
		goutfile.write(reinterpret_cast <char*>(&ch1), sizeof(int));
		goutfile.write(reinterpret_cast <char*>(&ch2), sizeof(int));

		file_pol_out.read(reinterpret_cast <char*>(&ch1), sizeof(int));
		file_otr_out.read(reinterpret_cast <char*>(&ch2), sizeof(int));
	}
}

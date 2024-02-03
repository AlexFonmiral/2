#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<Windows.h>
#include<fstream>
using namespace std;
vector<vector<string>> v(503, vector<string>(4));

void Sort(int l, int r) {
	int i = l, j = r;
	int g = int(v[(l + r) / 2][0]);
	while (i <= j) {
		while (int(v[i][0]) < g) i++;
		while (int(v[j][0]) > g) j--;
		if (i <= j) {
			swap(v[i][0], v[j][0]);
			swap(v[i][1], v[j][1]);
			swap(v[i][2], v[j][2]);
			swap(v[i][3], v[j][3]);
			i++; j--;
		}
		if (l < j) Sort(v, l, j);
		if (i < r) Sort(v, i, r);


	}

}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	//ScientistName#preparation#date#components
	string ScientistName, preparation, date, components;
	ifstream f("scientist.txt");

	int i = 0;
	while (f.good()) {
		getline(f, ScientistName, '#');
		getline(f, preparation, '#');
		getline(f, date, '#');
		getline(f, components, '\n');
		v[i][2] = ScientistName;
		v[i][1] = preparation;
		v[i][0] = date;
		v[i][3] = components;
		i++;
		//cout << v[i][0] << endl;
	}
	Sort(1, 500);

	cout << v[1][2] << ": " << v[1][1] << endl;
	cout << v[2][2] << ": " << v[2][1] << endl;
	cout << v[3][2] << ": " << v[3][1] << endl;
	cout << v[4][2] << ": " << v[4][1] << endl;
	cout << v[5][2] << ": " << v[5][1] << endl;
}
#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <set>


using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set <string> Set;
	string name;
	vector <string> vctr;
	bool boo = true;
	cout << "Введите имя: "; cin >> name;
	ifstream x(name);

	while (x) // тележка
	{
		string point;
		x >> point;
		vctr.push_back(point);
	}
	for (int i = 0; i < vctr.size(); i++)
	{
		for (int j = 0; j < vctr.size(); j++)
		{
			if ((vctr[i] == vctr[j]) && (i != j)) // не сравнивают с самим собой (2-е)
			{
				boo = false;
			}
		}
	}
	cout << "\n\n\n";
	if (boo == false)
	{
		for (int i = 0; i < vctr.size(); i++)
		{
			cout << vctr[i] << " ";
		}
		cout << endl;
		cout << "Данные перемещены в вектор, т.к. найдены повторяющиеся элементы";

	}
	else if (boo == true)
	{
		for (int i = 0; i < vctr.size(); i++)
		{
			Set.insert(vctr[i]);
		}
		ostream_iterator<string> out_it(cout, " ");
		copy(Set.begin(), Set.end(), out_it);
		{cout << "Данные перемещенны во множество, т.к. элементы не повторяются\n"; }
	}
	system("pause");
	return 0;
}
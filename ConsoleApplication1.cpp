// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int readArrLength(std::ifstream& in)
{
	int str;
	if (in >> str)
		return str;
	else return 0;
}

int* readArr(std::ifstream& in, const int &length)
{ 
	//const int MyLength = length;
	int* arr = new int[length]();
	for (int i = 0; i < length; ++i)
	{
		in >> arr[i];
	}
	return arr;
}

int* shiftNum(int* arr1, int size, bool right)
{
	int* arr = new int[size]();
	int i, j;
	if (right)
	{
		i = 1;
		j = 0;
		arr[0] = arr1[size - 1];
	}
	else
	{
		i = 0;
		j = 1;
		arr[size - 1] = arr1[0];
	}

	for (i, j; (i < size)&&(j < size); ++i,++j)
	{
		arr[i] = arr1[j];
	}

	return arr;
}

void fOut(int* arr, int length, std::ofstream &out)
{
	out << length << endl;
	for (int i = 0; i < length; ++i)
	{
		out << arr[i] << " ";
	}
	out << endl;
}

void delArr(int* &arr)
{
	delete[] arr;
	arr = nullptr;
}

int main()
{

	std::ifstream in("in.txt");
	int Length1 = readArrLength(in);
	int* FirstArr = readArr(in, Length1);
	int Length2 = readArrLength(in);
	int* SecondArr = readArr(in, Length2);
	in.close();
	int* FirstOut = shiftNum(SecondArr, Length2, true);
	int* SecondOut = shiftNum(FirstArr, Length1, false);
	std::ofstream out("out.txt");
	fOut(FirstOut, Length2, out);
	fOut(SecondOut, Length1, out);
	out.close();
	delArr(FirstArr);
	delArr(SecondArr);
	delArr(FirstOut);
	delArr(SecondOut);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

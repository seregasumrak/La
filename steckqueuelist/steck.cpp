#include <iostream>
#include <conio.h>
using namespace std;

void push(int *steck, int i)//Добавить в стек
{
	steck[i]=rand()%199;
}

void pop(int *steck, int razmer, int k)//Удалить элемент
{
	int *temp;
	temp = new int[razmer-1];
	for (int i=0; i<k; i++)
	{
		temp[i]=steck[i];//Сохраняем все до выбранного элемента
	}
	for(int i=k; i<razmer-1; i++)
	{
		temp[i]=steck[i+1];//Дописываем что осталось без выбранного элемента, те удаляем его
	}
	delete steck;
	
	steck = new int [razmer-1];
	for (int i=0; i<razmer-1; i++)
	{
		steck[i]=temp[i];
	}
	delete temp;
}

void getznach(int *steck, int k, int razmer)//Получить значение
{
	for(int i=razmer; i>=k; i--)
	{
		if(i==k)//Ищем выбранный элемент и  выводим
			cout << "Znachenye vybrannogo elementa: " << steck[i];
		else
			continue;
	}
}

int main()
{
	int* steck, razmer, n;
	cout << "Vvedyte razmer stecka: ";
	cin >> razmer;
	steck = new int[razmer];
	for(int i=0; i<razmer; i++)
	{
		push(steck,i);//Добавляем элемент в стек
	}
	cout << "Vvedyte nomer elementa, kotory nuzhno vyvesti ";
	cin >> n;
	getznach(steck,n,razmer);//Выводим
	cout << "\nVvedyte kakoy element udalit: ";
	cin >> n;
	pop(steck,razmer,n);//Удаляем
	getch();
}
#include <iostream>
#include <conio.h>
using namespace std;

void push(int *steck, int i)//�������� � ����
{
	steck[i]=rand()%199;
}

void pop(int *steck, int razmer, int k)//������� �������
{
	int *temp;
	temp = new int[razmer-1];
	for (int i=0; i<k; i++)
	{
		temp[i]=steck[i];//��������� ��� �� ���������� ��������
	}
	for(int i=k; i<razmer-1; i++)
	{
		temp[i]=steck[i+1];//���������� ��� �������� ��� ���������� ��������, �� ������� ���
	}
	delete steck;
	
	steck = new int [razmer-1];
	for (int i=0; i<razmer-1; i++)
	{
		steck[i]=temp[i];
	}
	delete temp;
}

void getznach(int *steck, int k, int razmer)//�������� ��������
{
	for(int i=razmer; i>=k; i--)
	{
		if(i==k)//���� ��������� ������� �  �������
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
		push(steck,i);//��������� ������� � ����
	}
	cout << "Vvedyte nomer elementa, kotory nuzhno vyvesti ";
	cin >> n;
	getznach(steck,n,razmer);//�������
	cout << "\nVvedyte kakoy element udalit: ";
	cin >> n;
	pop(steck,razmer,n);//�������
	getch();
}
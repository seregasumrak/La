#include <iostream>
#include <conio.h>
using namespace std;

void add(int *queue, int n)
{
	queue[n]=rand()%200+9;//��������� � ������� ����� �������
}

void delet(int *queue, int k, int razm)
{
	int *tmp;
	tmp = new int[razm-1];
	for (int i=0; i<k; i++)
	{
		tmp[i]=queue[i];//�� ���������� �������� ��������� ��� ��������
	}
	
	for(int i=k; i<razm-1; i++)
	{
		tmp[i]=queue[i+1];//���������� ��������� ������� � ���������� ���������, ����� ������� ������ ��������� �������
	}
	delete queue;//������� ������ ������� � ��������� ��� ������
	queue = new int [razm-1];
	for (int i=0; i<razm-1; i++)
	{
		queue[i]=tmp[i];
	}
	delete tmp;
}

void getznach(int *queue, int k)
{
	cout << "Znachenye: " << queue[k];//������� �������� ���������� �������� �������
}

int main()
{
	int *queue, razmer, n;
	cout << "Razmer iskhodnoy ocheredy: ";//��������� ������ ������� � ������� ��
	cin >> razmer;
	queue = new int[razmer];
	for(int i=0; i<razmer; i++)
		add(queue,i);//��������� ������� ����������
	cout << "Vyberyte element dlya vyvoda";//������� ��������� �������
	cin >> n;
	getznach(queue,n);
	cout << "\nVyberyte nomer elementa, kotory nuzhno udalit ";
	cin >> n;
	delet(queue,n,razmer);
	getch();
}
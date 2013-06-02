#include <iostream>
#include <conio.h>
using namespace std;

void add(int *queue, int n)
{
	queue[n]=rand()%200+9;//Добавляем в очередь новый элемент
}

void delet(int *queue, int k, int razm)
{
	int *tmp;
	tmp = new int[razm-1];
	for (int i=0; i<k; i++)
	{
		tmp[i]=queue[i];//До выбранного элемента сохраняем все элементы
	}
	
	for(int i=k; i<razm-1; i++)
	{
		tmp[i]=queue[i+1];//Пропускаем выбранный элемент и записываем следующие, таким образом удаляя выбранный элемент
	}
	delete queue;//Удаляем объект очередь и заполняем его заного
	queue = new int [razm-1];
	for (int i=0; i<razm-1; i++)
	{
		queue[i]=tmp[i];
	}
	delete tmp;
}

void getznach(int *queue, int k)
{
	cout << "Znachenye: " << queue[k];//Выводим значение выбранного элемента очереди
}

int main()
{
	int *queue, razmer, n;
	cout << "Razmer iskhodnoy ocheredy: ";//Считываем размер очереди и создаем ее
	cin >> razmer;
	queue = new int[razmer];
	for(int i=0; i<razmer; i++)
		add(queue,i);//Заполняем очередь элементами
	cout << "Vyberyte element dlya vyvoda";//Выводим выбранный элемент
	cin >> n;
	getznach(queue,n);
	cout << "\nVyberyte nomer elementa, kotory nuzhno udalit ";
	cin >> n;
	delet(queue,n,razmer);
	getch();
}
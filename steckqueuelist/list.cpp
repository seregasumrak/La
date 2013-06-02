#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

struct list
{
	int znach;
	list *lnext;
	void getznach(int k, list *tmp, list *first)
	{
		for(int i=0;i<k;i++)
		{
			tmp=first;
			first= first->lnext;
		}
		cout << "Znachenye vybrannogo elementa:: " << tmp->znach;
	}
	void addelem(int zn, int k, list *tmp, list *first)
	{
		for(int i=0; i<k; i++)
		{
			tmp=first;
			first=first->lnext;
		}
		tmp->znach = zn;
	}
	
	void del(int k, list *tmp, list *first)
	{
		for(int i=0; i<k; i++)
		{
			tmp=first;
			first= first->lnext;
		}
		delete tmp;
	}
};

int main()
{	
	
	int razm, n;
	list *first = 0;
	list *lis;
	
	cout << "Vvedyte razmer spiska: ";
	cin >> razm;
	lis = new list;

	for (int i=0; i<razm; i++)
	{
		lis = new list;
		lis->znach=0;
		lis->lnext=first;
		first=lis;
	}
	
	for(int i=0; i<razm; i++)
	{		
			srand(time(0));
			lis->addelem(rand()%165-i,i,lis,first);
	}
	cout << "Znachenye kakogo elementa vyvesti?:  ";
	cin >> n;
	lis->getznach(n,lis,first);
	cout << "\nVvedyte nomer elementa, kotory nuzhno udalit: ";
	cin >> n;
	lis->del(n,lis,first);
	getch();

}
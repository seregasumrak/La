#include<iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int m[50];
int temp[50];
int i=0,num;
int flag=0;
struct node /** Класс Бора */
{
  int kluch;
  int Count;
  node *Left;
  node *Right;
};

class TREE /** Класс дерево */
{
  private:
    node *root; //! Корень дерева
  public:
    TREE() { root = NULL; }
    node **GetDuk() { return &root; }
    node *Tree (int, node **); 
    void Vyvod (node **, int);
};

node *TREE::Tree (int n,node **p)//! Tree creation with n nodes
{
  node *now;
  int x,nl,nr;
  now = *p;
  if  (n==0) *p = NULL;
  else
  {
	nl = n/2; nr = n - nl - 1;
	if(!flag)
	{
	x=rand()%22+1;
	m[i]=x;
	i++;
	}
	else if(flag==1)
	{
		if(i<num-1)
		{
		x=m[i];
		temp[i]=x;
		i++;
		}
		else
		{
			x=rand()%22+1;
			temp[i]=x;
			i=0;
		}
	}
	else 
	{
		if(i<num)
		{
			x=temp[i];
			i++;
		}
	}
	
    now = new(node);
    (*now).kluch = x;
    Tree (nl,&((*now).Left));
    Tree (nr,&((*now).Right));
    *p = now;
  }
  return 0;
}

void TREE::Vyvod (node **w,int l)//! Вывод дерева
{
  if  (*w!=NULL)
  {
    Vyvod (&((**w).Right),l+1);
    for  (int i=1; i<=l; i++) cout<<"   ";
    cout<<(**w).kluch<<endl;
    Vyvod (&((**w).Left),l+1);
  }
}

void main ()
{
  TREE tr;
  int n;
  int del_num;
  cout<<"Vvedyte kolichestvo elementov: ";
  cin>>n;
  cout<<"Derevo:\n"; 
  tr.Tree (n,tr.GetDuk());
  tr.Vyvod (tr.GetDuk(),0);
  cout<<"Vstavka novogo elementa:\n"; 
  num=++n;
  flag=1;
  i=0;
  tr.Tree (n,tr.GetDuk());
  tr.Vyvod (tr.GetDuk(),0);
  cout<<"\nVvedyte kolichestvo elementov dlya udalenya: ";
  cin>>del_num;
  cout<<"Derevo:\n";
  num-=del_num;
  n=num;
  flag=2;
  tr.Tree (n,tr.GetDuk());
  tr.Vyvod (tr.GetDuk(),0);
  getch();
}
   

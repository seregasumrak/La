#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;


/**
* This method will be used to sort chosen array.
* @author Antonyuk Vyacheslav
* @param mas	Array which need to be sort
* @param number		Number of elements in this array
* @date 4/1/2013
*/

int* sort(int* mas, int number)
{
	/**
	Create a buffer array, in which we will add sorted array
	*/
	int* arr = mas;
	/**
	Variable, in which we would place the value of a relocatable variable
	*/
	int buf;
	/**
	Swap two adjacent elements that do not go in ascending order
	*/
	for(int i = 0; i < number; i++)
	{ 
		/**
		Skip if this first element
		*/
		if( (i != 0) && (arr[i]<arr[i-1]))
		{
			buf = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = buf;
			/**
			Move counter to the transferred item (number is less than)
			*/
			i-=2;
		}
	}
	return arr;
}

void main()
{
	/**
	Russian Language in console
	*/
	setlocale(LC_ALL,"Russian");
	int* arrays;
	int n;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	/**
	Create dynamic int array with n elements
	*/
	arrays=new int[n];
	srand(time(NULL));
	for( int i = 0; i < n; i++)
	{
		/**
		Generate array elements
		*/
		arrays[i] = rand()%101;
		/**
		Print generated element
		*/
		cout<<endl<<"Array["<<i+1<<"]="<<arrays[i];
	}
	cout<<endl<<endl<<"Sort in progress............................."<<endl;
	/**
	Sort array
	*/
	arrays=sort(arrays,n);
	cout<<"Sort completed!"<<endl<<endl<<"Result:"<<endl<<endl;
	/**
	Print sorted array
	*/
	for( int i = 0; i < n; i++)
	{
		cout<<"Array["<<i+1<<"]="<<arrays[i]<<endl;
	}
}
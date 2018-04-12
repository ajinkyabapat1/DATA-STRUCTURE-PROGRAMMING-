#include<iostream>
using namespace std;

class Heap_Sort
{
	int *array,size;
	public:
	Heap_Sort()
	{
		array=NULL;
		size=0;
	}
		void getSize(int);
		void getElement();
		void Heap();
		void Build_heap(int,int);
		void Display();	
};

void Heap_Sort::getSize(int n)
{
	array=new int[n];
	size=n;	
}

void Heap_Sort::getElement()
{
	cout<<endl<<"Enter the element";
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
}

void Heap_Sort::Display()
{
	cout<<endl<<"Display data";
	for(int i=0;i<size;i++)
	{
		cout<<"\t"<<array[i];
	}	
}

void Heap_Sort::Heap()
{
	int i,j;
	for(i=((size/2)-1);i>=0;i--)
		Build_heap(i,size);
	for(j=0;j<size-1;j++)
	{
		swap(array[0],array[size-1-j]);
		Build_heap(0,size-1-j);
	}
}

void Heap_Sort::Build_heap(int i,int n)
{
	int temp=array[i];
int c;
	for( ;2*i+1<n;i=c)
	{
		c=2*i+1;
		if(c+1<n && array[c+1]>array[c])
		{
			c++;
		}
		if(temp<array[c])
			array[i]=array[c];
		else
			break;
	}
	array[i]=temp;
}

int main()
{
	int n;
	Heap_Sort h1;
	cout<<endl<<"Enter the size of an array";
	cin>>n;
	h1.getSize(n);
	h1.getElement();
	h1.Heap();
	h1.Display();
	return 0;
}

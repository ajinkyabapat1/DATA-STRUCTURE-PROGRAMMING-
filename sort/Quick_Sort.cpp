#include<iostream>
using namespace std;

class Quick_Sort
{
	int *array,size,low,high,i,j;
	public:
	void getSize(int);
	void getElement();
	void Display();
	int Gunwant(int,int);
};

void Quick_Sort::getSize(int n)
{
	array=new int[n];	
	size=n;
}

void Quick_Sort::getElement()
{
	cout<<endl<<"Enter the element";
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	
	low=array[0];
	high=array[size-1];

	Gunwant(low,high);	
}

int Quick_Sort::Gunwant(int low,int high)
{
	int pivot;
	pivot=array[low];
	i=low++;
	j=high;
	
	if(low<high)
	{
		cout<<endl<<"###EEEEEEEEE";
		while(1)
		{
			cout<<"!!!!!!!!!!!";
			while(i<=high && array[i]<pivot)
				i++;
			while(array[j]>pivot)
				j--;
			if(i<j)
			{
				int temp;
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
			else
			{
				break;
			}
		}
		int temp2;
		temp2=array[low];
		array[low]=array[j];
		array[j]=temp2;

		cout<<array[low]<<"\t"<<temp2;
		Gunwant(low,j-1);
		Gunwant(j+1,high);
	}
	else
	{
		cout<<endl<<"Element is not found";		
	}
}
void Quick_Sort::Display()
{
	cout<<endl<<"Sorted elements are..."<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<"\t";
	}
}
int main()
{
	int n;
	Quick_Sort q1;
	cout<<endl<<"Enter size of array";
	cin>>n;
	q1.getSize(n);
	q1.getElement();

	q1.Display();
	return 0;
}

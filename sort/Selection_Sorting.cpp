#include<iostream>
using namespace std;
	
class Selection_Sort
{
	public:
	int *array;
	int size,i,j;
	
	Selection_Sort()
	{
		array=NULL;
		size=0;
	}
	void getSize(int);
	void getElements();	
	void Sorted_Data();
	void Selection_Sorting();

};
void Selection_Sort::getSize(int n)
{
	array=new int;
	size=n;
}
	
void Selection_Sort::getElements()
{
	cout<<"enter the elements of array to sort"<<endl;
	for(i=0;i<=(size-1);i++)
	{
		cin>>array[i];		
	}
}	

void Selection_Sort::Selection_Sorting()
{
		int temp,loc,start=0;
	for(i=0;i<(size-1);i++)
	{
		loc=i;
		start=array[i];
		for(j=i+1;j<size;j++)
		{
				
				if(array[j]<start)
				{
					start=array[j];
					loc=j;
				}	
		}

		if(i==loc)
		{
			temp=array[i];	
			array[i]=array[loc];
			array[loc]=temp;
		}
		
	}
}

void Selection_Sort::Sorted_Data()
{
	cout<<"Sorted Data"<<endl;
	for(i=0;i<=(size-1);i++)
	{
		cout<<array[i];
		cout<<"\t";
	}
}


int main()
{	
int n;
	cout<<endl<<"Enter size of elements";
	cin>>n;
	Selection_Sort s1;
	s1.getSize(n);
	s1.getElements();
	s1.Selection_Sorting();
	s1.Sorted_Data();
return 0;
}

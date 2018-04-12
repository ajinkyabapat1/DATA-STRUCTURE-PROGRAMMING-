#include<iostream>
using namespace std;

class Merge_Sort
{
	int *array,size,i;
	int low,high,mid;
	public:
	Merge_Sort();
	~Merge_Sort();
	void getSize(int);
	void getElement();
	void M_Sort(int *,int,int);
	void merge(int*,int,int,int);
	void Display();	
};

Merge_Sort::Merge_Sort()
{
	array=NULL;
	size=0;
}

Merge_Sort::~Merge_Sort()
{
	//delete array;
}

void Merge_Sort::getSize(int n)
{
	array=new int[n];
	size=n;
}

void Merge_Sort::getElement()
{	
	int l,h;
	cout<<endl<<"Enter the element";
	for(i=0;i<size;i++)
	{
		cin>>array[i];
	}
	/*low=array[0];
	high=array[size-1];
	M_Sort(low,high);*/
     M_Sort(array,0,size-1);
}

void Merge_Sort::M_Sort(int *a,int low,int high)
{
		if(low<high)
		{
			int mid=((low+high)/2);
			M_Sort(a,low,mid);
			M_Sort(a,mid+1,high);
			merge(a,low,mid,high);
		}
}

void Merge_Sort::merge(int *a, int low,int mid,int high )
{
	/*int l2s=l1e+1;
	int s=l2e-l1s+1;
	int *l3,i,j,k=0;
	l3=new int[s];
	i=l1s;
	j=l2s;*/
int i=low;
int j=mid+1;
int k=0;
int temp[high-low+1];
	
	/*while(i<=l1e && j<=l2e)
	{
		if(array[i]<array[j])
			l3[k++]=array[i++];
		else
			l3[k++]=array[j++];
	}
	
	while(i<=l1e)
	{
		l3[k++]=array[i++];
	}
	
	while(j<=l2e)
	{
		l3[k++]=array[j++];
	}

	while(k>=0)
	{
		array[l2e--]=l3[--k];
		delete l3;
	}
	*/
	while(i<=mid && j<=high)
   {
       if(a[i]<a[j])
		{
                temp[k]=a[i];
                k++;i++;
 

        }
else
   {
              temp[k]=a[j];
              k++;
              j++;

   }
   }

while(i<=mid)
{
                temp[k]=a[i];
                k++;i++;
 

        }
while(j<=high)
{
 temp[k]=a[j];
              k++;
              j++;
}
for(i=low;i<=high;i++)
{
    a[i]=temp[i-low];
}
}

void Merge_Sort::Display()
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
	Merge_Sort m1;
	cout<<endl<<"Enter the size of the array";
	cin>>n;
	m1.getSize(n);
	m1.getElement();
	m1.Display();
	return 0;
}

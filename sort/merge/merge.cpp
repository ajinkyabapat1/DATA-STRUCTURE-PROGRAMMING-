#include<iostream>
using namespace std;
void merge(int *,int ,int ,int );
void mergesort(int *,int ,int );
 int main()
	{
		int n,i;
		cout<<"How many numbers are there in an array"<<endl;
	        cin>>n;
	        int a[n];
	       cout<<"enter alements"<<endl;
			for ( i=0;i<n;i++)
				{
					cin>>a[i];
				}
	cout<<"array elemnts are"<<endl;
			for (i=0;i<n;i++)
			 {
			   cout<<a[i];
			 }
			 
	mergesort(a,0,n-1);
	cout<<"after sorting"<<endl;
	for(i=0;i<n;i++)
	{
	cout<<a[i];
	}
	return 0;		 

}

	void mergesort(int *a,int low,int high)
	{
		int mid;
		while (low<high)
		{
			mid=(low+high)/2;
			mergesort(a,low,mid);
			mergesort(a,mid+1,high);
			merge(a,low,high,mid);
		}  

	}

void merge(int *a,int low,int high,int mid)
{
int k;
int i=low;
int j=mid+1;
int temp[high-low+1];
k=0;
while(i<mid && j<high)
  {
   if(a[i]<a[j])
   {
      temp[k]=a[i];
      i++;
      k++;
      
   }
   else 
   {
      temp[k]=a[j];
      k++;
      j++;
      
   }
  }
  while (i<mid)
  {
     temp[k]=a[i];
     k++;
     i++;
  }
  
  while(j<high)
  {
    temp[k]=a[j];
    k++;
    j++;
  
  }
  
  for(i=low;i<high;i++)
  {
    a[i]=temp[i-low];
    
  }
}

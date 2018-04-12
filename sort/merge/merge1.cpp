#include<iostream>
using namespace std;
void mergesort(int a[],int ,int );
//void merge(int *,int ,int ,int );
//void merge(int *a,int low,int high,int mid);
void merge(int a[],int ,int ,int );
int main()
{
int n;
cout<<"Enter size of an array"<<endl;
cin>>n;
int a[n];
cout<<"enter numbers"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"array is "<<endl;
for(int i=0;i<n;i++)
{
  cout<<" "<<a[i];
}

mergesort(a,0,n-1);
cout<<"\n";
 cout<<"result is"<<endl;
  for(int i=0;i<n;i++)
  cout<<" "<<a[i];
  
return 0;
}
void mergesort(int a[],int low,int high)
{
int mid;
if(low<high)
{
  mid=(low+high)/2;
  mergesort(a,low,mid);
  mergesort(a,mid+1,high);
  merge(a,low,high,mid);
 
}

}
void merge(int *a,int low,int high,int mid)
{
   int i=low;
   int j=mid+1;
   int k=0;
   int temp[high-low+1];
 while(i<=mid && j<=high)
 {
     if(a[i]<a[j])
   {
      temp[k]=a[i];
      k++;
      i++;
      
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
k++;
i++;
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


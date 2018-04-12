#include<iostream>
using namespace std;

int main()
{
int n;
cout<<"Enter No. of Data to be sorted";
cin>>n;
int a[n];
cout<<"Enter Elements"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"display Elements"<<endl;
for(int i=0;i<n;i++)
{
cout<<"\t"<<a[i];
}
quick_sort(a,low,pivot-1);
quick_sort(a,pivot+1,high);
}
int quick_sort(int a[],int low,int high)
{
int pivot=a[low];
i=low+1;
j=high;
if(low<high)
{
while(1)
{
while(i<=high && a[i]<pivot)
i++;
while(a[j]>pivot)
j--;
if(i<j)
{
swap(a[i],a[j]);
else
break;
}
swap(a[low],a[j]);
quick_sort(low,j-1);
quick_sort(j+1,high);
}
}
}

int random(int  a[],int low,int high)
{
int v,i,j,temp;
v=a[low];


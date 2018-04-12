#include<iostream>
using namespace std;
int main()
{
int i,n,s,mid;
cout<<"how many numbers in array"<<endl;
cin>>n;
int a[n];
int lb=0,ub=(n-1);
cout<<"enter elements"<<endl;
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"enter search element"<<endl;
cin>>s;
for(i=0;i<n;i++)
{
cout<<"\t"<<a[i]<<"\t";
}
mid=(lb+ub)/2;
for(i=0;i<n;i++)
{
if (a[mid]>s)
{
lb=lb;
ub=mid-1;
mid=(lb+ub)/2;
}
else if(a[mid]<s)
{
lb=mid+1;
ub=ub;
mid=(lb+ub)/2;
}
}
 if(a[mid]==s)
cout<<"successful"<<"at "<<mid+1<<"location"<<endl;

else 

cout<<"unsuccessful"<<endl;

}

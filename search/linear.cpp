#include<iostream>
using namespace std;
int main()
{
int i,n,s;
cout<<"how many numbers in array"<<endl;
cin>>n;
int a[n];
cout<<"enter elements"<<endl;
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(i=0;i<n;i++)
{

cout<<"\t"<<a[i]<<"\t";
}
cout<<"\n";
cout<<"Which no. do you want to search"<<endl;
cin>>s;
for(i=0;i<n;i++)
{
if(a[i]==s)
{
cout<<"search successful"<<a[i]<<"is found at"<<i<<"location"<<endl;
}

}
if(a[i]!=s)
cout<<"unsuccesful"<<endl;


}



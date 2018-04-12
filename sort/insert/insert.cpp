#include<iostream>
using namespace std;
   int main()
   {
        int i,n;
        cout<<"how many numbers are there in an array"<<endl;
        cin>>n;
        int a[n];
        cout<<"enter array elements"<<endl;
     for (i=0;i<n;i++)
        {
           cin>>a[i];
  
        }
       cout<<"array before sorting is "<<endl;
    for (i=0;i<n;i++)
     {
       cout<<"\t " <<a[i]<<" ";
     }
     
     for(i=1;i<n;i++)
     {
        int temp=a[i];
       int j =i-1;
        while((temp<a[j]) && (j>=0))
        {
        a[j+1]=a[i];
        j=j-1;
        }
        a[j+1]=temp;
       } 
     cout<<"\n array in after sorting in descending form : "<<endl;
      for (i=0;i<n;i++)
      {
        cout<<"\t "<<a[i]<< " " ;  
      }

cout<<"\n";
return 0;
}

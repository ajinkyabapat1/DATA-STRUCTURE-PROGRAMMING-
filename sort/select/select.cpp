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
     
     //>>>>>>>>>>>>>>>>>>>>ascending sorting<<<<<<<<<<<<<<<<
    for (i=0;i<n;i++)
     {
        for(int j=i+1;j<n;j++)
          {
             int temp;
             if(a[i]>a[j])
              {
                temp= a[i];
                a[i]=a[j];
                a[j]=temp;
              }  
          }
    }
 
 cout<<"\narray in after sorting in ascending form : "<<endl;
    for (i=0;i<n;i++)
   {
     cout<<"\t "<<a[i]<< " " ;
    
   }
      
    cout<<"\n";
    //>>>>>>>>>>>>>>>>>>>>descending sorting<<<<<<<<<<<<<<<<
   
   for (i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
         {
           int temp;
           if(a[i]< a[j])
            {
               temp= a[i];
               a[i]=a[j];
               a[j]=temp;
            }  
        }
   }
 
 cout<<"\narray in after sorting in descending form : "<<endl;
      for (i=0;i<n;i++)
      {
        cout<<"\t "<<a[i]<< " " ;  
      }

cout<<"\n";
return 0;
}

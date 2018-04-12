#include<iostream>
using namespace std;

 int main()
  {
    int n;

    cout<<"\n how many numbers do you wnt to insert";
    cin>>n;
    int a[n];
     for (int i=0;i<n;i++)
       {
          cin>>a[i];
       }
    cout<<"\n before  swapping"<<endl;
     for (int i=0;i<n;i++)
       {
         cout<<"\t"<<a[i];
       }

   for (int i=0;i<n-1;i++)
    {
       int flag=0;
       for(int j=0;j<n-1-i;j++)
         {
            if(a[j]>a[j+1])
             {
		  int temp;
		  temp=a[j+1];
		  a[j+1]=a[j];
		  a[j]=temp;
		  
            }
             
	   flag=1;
       }
    
    
    if(flag ==0)
    break;
  }

   cout<<" \n after swapping "<<endl;
     for(int i=0;i<n;i++)
      {
        cout<< " "<<a[i]<<"\t";
      }
}

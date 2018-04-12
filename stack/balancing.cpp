#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class stack1
{
  int *s;
  int size;
  int tos;
  
  public:
  stack1();
  void push(int);
  int pop();
  int peek();
  bool IsFull();
  bool IsEmpty();
  void display();
  void getsize(int );
  void balance();
  //~stack1();
  
};
       void stack1 :: balance()
       {
       char ostr[30],istr[30];
       char ch,str,pch;
       int flag=0;
       int n=strlen(istr);
       for (int i=0;i<=n-1;i++)
       {
       ch = istr[i];
       
       switch(ch)
       {
       case '(':
       case '[':
       case '{':
       push(ch);
       break;
       
       case ')':
       case ']':
       case '}':
       
       if (!IsEmpty())
       {
       pch=peek();
       if((pch =='('&& ch==')')||(pch =='['&& ch==']')||(pch=='{' && pch=='}'))
       pch=pop();
       else
       flag =1;
       }
       else
       flag=1;
       break;
       default:
       exit (0) ;
       }
       if(flag==1)
       break;
       }
if(IsEmpty() )
cout<<"Balanced";
else
cout<<"UnBalanced";
}
       
       
       
       
	stack1 :: stack1()
	{
	s=NULL;
	size=0;
	tos= -1;
	}
	void stack1 :: getsize(int n)
	{
	s=new int[n];
	size=n;
	}
	bool stack1 :: IsFull()
	{
	return  (tos == size-1);
	}
	bool stack1 ::IsEmpty()
	{
	return (tos == -1);
	} 
	void stack1 :: push(int ele)
	{
	if(!IsFull())
	s[++tos]=ele;
	else 
	cout<<"\nstack is full"<<endl;
	}
	void stack1 :: display()
	{
	for (int i=tos ;i>=0;i--)
	cout<<"stack item is :"<<s[i]<<endl;
	}
	
	int stack1 :: pop()
	{
	int x=-999;
	if(!IsEmpty()==(size-1))
	x=s[tos--];
	else
	cout<<"\tStack is empty"<<endl;
	}
	/*stack1 :: ~stack1()
	{
	delete s;
	size= 0;
	tos=-1;
	}*/
	int stack1 :: peek()
	{
	int x=-999;
	if(!IsEmpty()==(size-1))
	x=s[tos];
	else
	cout<<"\tStack is empty"<<endl;
	}
	
int main()
{
stack1 s,k;
k.balance();
int ch,a,c,ch1,cha;

cout<<"\nEnter size of stack"<<endl;
cin>>c;
/*s.getsize(c);
cout<<"\nwhich number do you want to insert"<<endl;
cin>>ch1;
s.push(ch1);
while(1)
{


cout<<"\nwhich operation do you want to perform"<<endl;
cout<<"1.PUSH \t 2.Delete 3.Display 4.peek"<<endl;
cin>>ch;

switch (ch)

{
case 1:
        
        cout<<"\nwhich number do you want to insert"<<endl;
        cin>>a;
        
        s.push(a);
        
        break;
case 2:
        s.pop();
        break;  
case 3:
        s.display();
        break;  
case 4:
         s.peek();
         break;
                         
}
}*/
}



#include<iostream>
using namespace std;
class queue1
{
int *q;
int size;
int f,r;
public:

queue1();
void getsize(int);
void Enqueue (int);
int  Dequeue();
bool underflow();
bool  overflow();
void display();
//~queue();
};
queue1::queue1()
{
q=NULL;
size=0;
f=r=-1;
}
void queue1::getsize(int n)
{
q=new int[n];
size=n;
}
bool queue1::underflow()
{
return ((f==-1 )&&(r==-1));
}
bool queue1::overflow()
{
return(r==size-1);
}

int queue1::Dequeue()
{
int x=-999;
if(!underflow())
{
x=q[f];
if(f==r)
f=r=-1;
else 
f++;
}
else 
cout<<"underflow"<<endl;
return x;
}

void queue1::Enqueue (int ele)
{
if(!overflow())
{
if(r==-1 &&f == -1)
f++;
q[++r]=ele;
}
else
cout<<"overflow";
}
void queue1::display()
{
if(!underflow ())
{
for (int i=f;i<=r;i++)
cout<<"\n"<<q[i];
}
}
int main()
{
queue1 s;
int a,b,ch;
cout<<"enter size of queue"<<endl;
cin>>a;
s.getsize(a);
while(1)
{


cout<<"\nwhich operation do you want to perform"<<endl;
cout<<"1.PUSH \t 2.Delete 3.Display 4.peek"<<endl;
cin>>ch;

switch (ch)

{
case 1:
        
        cout<<"\nwhich number do you want to insert"<<endl;
        cin>>b;
        
        s.Enqueue(b);
        
        break;
case 2:
        s.Dequeue();
        break;  
case 3:
        s.display();
        break;  
default:
       cout<<"invalid entry";
                         
}
}

}




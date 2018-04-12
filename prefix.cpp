#include<iostream>
#include<string.h>
using namespace std;
class stackpost
{
char *str;

int size;
int Tos;
public:

	stackpost()
{
	str=NULL;
	size=0;
	Tos=-1;
}
	void get_size(int n)
{
	str=new char[n];
	size=n;
}
	bool IsFull()
{
	return(Tos==(size-1));
}
	bool IsEmpty()
{
	return(Tos==-1);
}
	void push(char ele)
{
	if(!IsFull())
	str[++Tos]=ele;
	else
	cout<<"stack is full"<<endl;
}
	char  pop()
{
	char x='x';
	if(!IsEmpty())
	x=str[Tos--];
	else
	cout<<"stack is empty"<<endl;
	return x;
}
	char  peek()
{
	char x='x';
	if(!IsEmpty())
	x=str[Tos];
	else
	cout<<"stack is empty"<<endl;
	return x;
}
	~stackpost()
{
	delete[]str;
	size=0;
	Tos==-1;
}
};
int main()
{
char istr[]="a+b*(c/d-e)+f";

int i,n;
stackpost p;

n=strlen(istr);
int j=n-1;
char ostr[n];
p.get_size(n);

int prec(char);
for(i=n;i>=0;i--)
{

char ch=istr[i];
char pch;
     switch(ch)
      {
        case ')':
        case '}':
        case ']':
                 p.push(ch);
                 break;
        case '+':
        case '-':
        case '*':
        case '/':
                 while( !p.IsEmpty() && (  prec(p.peek()) > prec(ch)) ) 
                {
                 ostr[--j]=p.pop();
                }
                 p.push(ch);
                 break;

        case '(':
        case '{':
        case '[':
                 while(1)
                {
                 pch=p.pop();
                 if(!(pch==')' || pch==']' || pch=='}'))
                 ostr[--j]=pch;
                 else
                 break;
                }
               break;
       default:ostr[--j]=ch;

       }
}
        while(!p.IsEmpty())
        {
           ostr[--j]=p.pop();
        }



cout<<"prefix"<<ostr<<endl;



return 0;
}
int prec(char c)
{
int x;
switch(c)
{
case '*':
case '/':
         x=2;
         break;
case '+':
case '-':
         x=1;
         break;
case ')':
case '}':
case ']':
         x=0;
         break;
default:x=-1;
}
return x;
}                

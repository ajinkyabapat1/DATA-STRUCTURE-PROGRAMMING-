#include<iostream>
#include<string.h>
using namespace std;


class stack1
{	
	int *s;
	int top;
	static int size;
public:
	stack1();
	void push(int);
	int pop();
	bool Isfull();
	bool Isempty();
	int peek();
	void display();	
	void getSize(int);
	void checkbalance();
	~stack1();
};
int stack1::size;

stack1::stack1()
	{
	s=NULL;
	size=0;
	top=-1;
	}

void stack1::getSize(int n)
	{
	s=new int[n];
	size=n;	
	}
bool stack1::Isfull()
	{
		return(top==size-1);
	}
bool stack1::Isempty()
	{
		return(top==-1);
	}
void stack1::push(int ele)
	{
		if(!Isfull())
			{
			 s[++top]=ele;
			}
		else
		{
			cout<<"stack is full"<<endl;
		}
	}

int stack1::pop()
	{	
		int x=-999;
		if(!Isempty())
			{
			 x=s[top--];
			}
		else
		{
			cout<<"stack is empty"<<endl;
		}
		return x;
	}

int stack1::peek()
	{
		int x=s[top];
		return x;
	}

void stack1::display()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<"stack elements:"<<s[i]<<endl;
		}
	}

void stack1::checkbalance()
	{
	char ch;
	int flag=0;
	int i,n;
	char pch;	
	char str[30];
	cout<<"enter string:"<<endl;
	cin>>str;
	n=strlen(str);
	for( i=1;i<=n;i++)
		{
			ch=str[i];
			switch(ch)
				{
					case '{':
					case '(':
					case '[':
						push(ch);
						break;
					
					case '}':
					case ')':
					case ']':
						if(!Isempty())
						{
							pch=peek();
							if((pch=='('&&ch==')')||(pch=='{'&&ch=='}')||(pch=='['&&ch==']'))
								pch=pop();
							else
								flag=1;
						}
						else
							flag=1;
							break;
					default:
						{
						}
							
			}//switch
			if(flag==1)
				break;
		}//for
	if(Isempty())
		{
			cout<<"balanced"<<endl;
		}
	else
		{
			cout<<"unbalanced"<<endl;		
		}
	}
stack1::~stack1()
	{
		delete s;
		size=0;
		top=-1;
	}

int main()
{	stack1 s1;
	int n;
	cout<<"enter size of stack:"<<endl;
	cin>>n;
	
	s1.getSize(n);
	/*for(int j=0;j<=n;j++)
		{
		cout<<"enter elements to be push"<<endl;
		cin>>ele;
			s1.push(ele);
		}
	s1.display();
	cout<<"\n Elements after Pop"<<endl;
	s1.pop();
	s1.display();*/
	s1.checkbalance();
	
	
return 0;
}

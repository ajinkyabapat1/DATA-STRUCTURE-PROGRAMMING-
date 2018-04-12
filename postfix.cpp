#include<iostream>
#include<string.h>
using namespace std;


class stack1
{	
	int *s;
	int top;
	int size;
public:
	stack1();
	void push(int);
	int pop();
	bool Isfull();
	bool Isempty();
	int peek();
	void display();	
	void getSize(int);
	void postfix();
	int prec(char);
	~stack1();
};

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

int stack1::prec(char c)
{
	int x;
	switch (c)
	{
		case '*':
		case '/':
			x=2;
			break;

		case '+':
		case '-':
			x=1;
			break;

		case '(':
		case '{':
		case '[':
			x=0;
			break;

		default:
			x=-1;
	}
return x;
}

void stack1::postfix()
	{
		char ostr[30];
		char istr[30];
		char ch;
		int i,j=-1,n;
		char pch;
		cout<<"enter string:"<<endl;
		cin>>istr;
		n=strlen(istr);
		for(i=0;i<n;i++)
		{
			ch=istr[i];
			switch(ch)
			{
				case '{':
				case '(':
				case '[':
					push(ch);
					break;
				
				case '+':
				case '-':
				case '*':
				case '/':
					while(!Isempty() && (prec(peek())>=prec(ch)))
						ostr[++j]=pop();
					push(ch);
					break;
	
				case '}':
				case ')':
				case ']':
					while(1)
					{
						pch=pop();
						if(!(pch=='(') || (pch=='{') || (pch==']'))
							ostr[++j]=pch;
						else
							break;
					}
					break;
				default:
					ostr[++j]=ch;

			}//switch
		}//for
		while(!Isempty())
			ostr[++j]=pop();
		cout<<ostr<<endl;
}

stack1::~stack1()
	{
		delete s;
		size=0;
		top=-1;
	}


int main()
{
	int n;
	cout<<"Enter size of Stack: "<<endl;
	cin>>n;

	stack1 s3;
	s3.getSize(n);
	s3.postfix();


return 0;
}

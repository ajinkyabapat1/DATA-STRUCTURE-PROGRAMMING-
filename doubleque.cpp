//Double ended queue
#include<iostream>
using namespace std;
class __DQueue__
{
	int *q;
	int size;
	int f,r;
public:
	__DQueue__();

	void getSize(int);

	void Insert_front(int);
	void Insert_rear(int);

	int Delete_front();
	int Delete_rear();

	bool Overflow();
	bool Underflow();
	void Display();

	//~__DQueue__();
};

__DQueue__::__DQueue__()
{
	q=NULL;
	size=0;
	f=r=-1;
}

void __DQueue__::getSize(int n)
{
	q=new int[n];
	size=n;
}

bool __DQueue__::Underflow()
{
	return ((r==(f+1)%size) || ( (f==-1)&&(r==-1) ) );
}

bool __DQueue__::Overflow()
{
	return (f==(r+1)%size);
}

void __DQueue__::Display()
{
	int i=0;
	
	if(!Underflow())
	{
		/*if(r<f)
		{
			for(i=0;i<=r;i++)
			cout<<q[i];
			for(i=r+1;i<f;i++)
			cout<<" ";
			for(i=f;i<size;i++)
			cout<<q[i];
		}
		else
		{
			for(i=f;i<=r;i++)
			cout<<q[i];
		}*/

		for(i=f;i!=r;i=(i+1)%size)
			cout<<q[i];
			
		cout<<q[i];
		
		
		cout<<endl;
	}
}


/*__DQueue__::~__DQueue__()
{
	delete q;
	size =0;
	f=r=-1;
}
*/


void __DQueue__::Insert_front(int ele)
{
	if(f==-1 && r==-1)
	{
	cout<<"enter  if "<<ele<<endl;
		f= f++;
		r++;
		q[f]=ele;
	}


	else if(!Overflow())
	{
	cout<<"enter else if "<<ele<<endl;
		if(f==0 && r==0)
		{
			cout<<"enter else if if1 "<<ele<<endl;

			f=f++;
			cout<<"enter else if if1----- "<<f<<endl;
			q[f]=ele;
		}
		if(f==0 && r>0)	
		{	
			cout<<"enter else if if 2"<<ele<<endl;

			f=size-1;
			q[f]=ele;		
		}	
		else
		{	
			f=  f--;
		
		       q[f]=ele;
		}
	}
	
	else
		cout<<"Queue Overflow"<<endl;
Display();
}


void __DQueue__::Insert_rear(int ele)
{
	if(!Overflow())
	{
		if(r==-1&&f==-1)
			f++;

		r=(r+1)%size;
		q[r]=ele;
	}
	else
		cout<<"Queue Overflow"<<endl;
}

int __DQueue__::Delete_front()
{
	int x=-999;
	if(!Underflow())
	{
		
		if(f==r)
			f=r=-1;
		else
		{
		//	delete [f]q;
			f=(f+1)%size;
		}
		x=q[f];
	}
	else
		cout<<"Queue underflow"<<endl;
	return x;
}

int __DQueue__::Delete_rear()
{
	int x=-999;
	if(!Underflow())
	{
		
		if(r==0)
			r=size-1;
		else
		{
		//	delete [f]q;
			r--;
		}
	}
	else
		cout<<"Queue underflow"<<endl;
	x=q[r];
	return x;
}

int main()
{
	__DQueue__ q1;
	q1.getSize(4);
cout<<"**********************Insert_rear*****************************"<<endl;		
	
cout<<"**********************Insert_front*****************************"<<endl;	
	//q1.Insert_rear(5);
	q1.Insert_front(3);
	q1.Insert_front(7);
	q1.Insert_front(6);
	q1.Display();
	q1.Insert_front(8);
/*cout<<"**********************Insert_rear*****************************"<<endl;	
	//q1.Insert_rear(5);
cout<<"**********************Display*****************************"<<endl;
	q1.Display();
cout<<"**********************Insert_front*****************************"<<endl;	
	q1.Insert_front(6);
	q1.Insert_front(8);
cout<<"**********************Display*****************************"<<endl;
	q1.Display();
cout<<"**********************Insert_rear*****************************"<<endl;	
	/*q1.Insert_rear(9);
	q1.Insert_rear(9);
	q1.Insert_rear(9);
	q1.Insert_rear(9);
	
cout<<"**********************Delete_rear*****************************"<<endl;	
	//q1.Delete_rear(); 
cout<<"**********************Display*****************************"<<endl;
	q1.Display();
cout<<"**********************Delete_ front*****************************"<<endl;
	//q1.Delete_front();
cout<<"**********************Display*****************************"<<endl;
	q1.Display();
cout<<"**********************Delete_front*****************************"<<endl;
	q1.Delete_front();
	q1.Delete_front();
	q1.Delete_front();
	q1.Delete_front();
*/
cout<<"**********************Display*****************************"<<endl;
	q1.Display();

	return 0;
}

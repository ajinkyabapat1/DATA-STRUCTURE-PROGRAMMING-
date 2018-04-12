#include<iostream>

using namespace std;
template<class T >
class stack1
{
  
  public:
  T *s;                           //int *s;
 int size;
 int tos;
  stack1();
  void push(T);                   //  void push(int);
  T pop();                        //  int pop();
  T peek();                       //  int peek();
  bool IsFull();
  bool IsEmpty();
  T display();
  void getsize(int );
  ~stack1();
  
};
        template<class T >
	stack1<T> :: stack1()          //stack1 :: stack1()
	{
	s=NULL;
	size=0;
	tos= -1;
	}
	template<class T >
	void stack1<T> :: getsize(int n)     //void stack1 :: getsize(int n)
	{
	s=new T[n];
	size=n;
	}
	
	template<class T >
	
	bool stack1<T> :: IsFull()
	{
	return  (tos == size-1);
	}
	
	template<class T >
	
	bool stack1<T> ::IsEmpty()
	{
	return (tos == -1);
	} 
	
	template<class T >
	void stack1 <T> :: push(T ele)
	{
	if(!IsFull())
	s[++tos]=ele;
	else 
	cout<<"\nstack is full"<<endl;
	}
	template <class T >
	T stack1 <T> ::display()
	{
	for (int i=0;i<=tos;i++)
	cout<<"stack item is :"<< s[i] <<endl;
	}
	
	template<class T >
	 T stack1 <T> :: pop()
	{
	T x=-999;
	if(!IsEmpty())
	
	{
	T x=s[tos--];
	cout<<"deleted no is "<<x<<endl;
	}
	else
	cout<<"\tStack is empty"<<endl;
	}
	template<class T >
	
	stack1<T> :: ~stack1()
	{
	delete s;
	size= 0;
	tos=-1;
	}
	template<class T >
	T stack1<T> :: peek()
	{
	T x=-999;
	if(!IsEmpty())
	{T x=s[tos];
	cout<<"peeked value is"<<x<<endl;
	}
	else
	cout<<"\tStack is empty"<<endl;
	}
	
 int main()
  {
   stack1<int> z;
   stack1<float> l;
   stack1<char>m;
  int ch,a,c;
  float b;
  char y[100];
  
    
  cout<<"\nEnter size of stack"<<endl;
  cin>>c;
   //m.getsize(c); 
  z.getsize(c);
  l.getsize(c);

/*for(int i=0;i<=c;i++)
  {
  cout<<"enter character";
  cin>>y[i];
  m.push(y[i]);
  
  }
  m.display();
  
  */
 /* for(int i=0;i<c;i++)
  {
    cout<<"\nwhich operation do you want to perform "<<endl;
    cout<<"1.PUSH \t 2.Delete 3.Display 4.peek"<<endl;
    cin>>ch;

  switch (ch)

    {
       case 1:
        
        cout<<"\nwhich number do you want to insert"<<endl;
       
        cin>>y[i];
        
        m.push(y[i]);
        break;
        
        case 2:
    
        m.pop();
        break;  
     
        case 3:
     
        m.display();
        break;  

        case 4:
        
       m.peek();
        break;
        
        default:
            break;
                     
                         
   }
   }*/

for(int i=0;i<c;i++)
  {
    cout<<"\nwhich operation do you want to perform"<<endl;
    cout<<"1.PUSH \t 2.Delete 3.Display 4.peek"<<endl;
    cin>>ch;

  switch (ch)

    {
       case 1:
        
        cout<<"\nwhich number do you want to insert"<<endl;
       
        cin>>b;
        
        l.push(b);
        break;
        
        case 2:
    
        l.pop();
        break;  
     
        case 3:
     
        l.display();
        break;  

        case 4:
        
        l.peek();
        break;
        
        default:
            break;
                     
                         
   }

 }
 cout<<"-------------------------float......................"<<endl;

  for(int i=0;i<c;i++)
    {


      cout<<"\nwhich operation do you want to perform"<<endl;
      cout<<"1.PUSH \t 2.Delete 3.Display 4.peek"<<endl;
      cin>>ch;

     switch (ch)

         {
            case 1:
        
                  cout<<"\nwhich number do you want to insert"<<endl;
                  cin>>a;
                  z.push(a);
                  break;
             
            case 2:
                  z.pop();
                  break;  
            case 3:
                  z.display();
                  break;  
           case 4:
                  z.peek();
                  break;
            default:
           break;
                         
         } 

    }
    
   return 0; 
 }
  
  



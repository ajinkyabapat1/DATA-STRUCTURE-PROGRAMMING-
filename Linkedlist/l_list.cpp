#include<iostream>
using namespace std;
    struct node
     {
	int data;
	struct node *next;
     };

   class l_list
    {
	
    public:
        friend void print (struct node  *);
        struct node *l;
	void Insert_Beg(int);
	void Insert_End(int);	
	void Insert_After(int,int);
	void Insert_Before(int,int);
	int Delete_First();
	int Delete_Last();
	void Delete_specific(int);
	void Traverse_Forword();
	void Traverse_Backword();
	void Reverse();
	
	l_list()
	{
		l= NULL;
	}
	~l_list();
   };

// >>>>>>>>>>>>>>>>>>> INSERTION AT THE BEGINNING<<<<<<<<<<<<<<<<<<<<<<<<
    void l_list::Insert_Beg(int ele)
      {
	struct node *temp;
	temp=new node;
	temp->data=ele;
	temp->next=l;
	l=temp;	
      }
      
 // >>>>>>>>>>>>>>>>>>> INSERTION AT THE END <<<<<<<<<<<<<<<<<<<<<<<<   
 
     void l_list::Insert_End(int ele)
      {
	struct node *temp;
	struct node *curr;
	temp=new node;
	
	temp->data=ele;
	temp->next=NULL;
	    if(l==NULL)
	       l=temp;
	         else
	        {
		
		   curr=l;
		       while(curr ->next !=NULL)
			curr=curr->next;
			
		   curr->next=temp;		
	        }

      }
      // >>>>>>>>>>>>>>>>>>> INSERTION AFTER A PERTICULAR ELEMENT  <<<<<<<<<<<<<<<<<<<<<<<<  
       void l_list::Insert_After(int ele, int sele)
          {
	        if(l!=NULL)
	         {
		    struct node *curr,*temp;
		    temp=new node;
		    curr=l;
		        while(curr !=NULL&&curr->data!=sele)
			
			curr=curr->next;
			
		    if(curr!= NULL)
		      {
		        
			temp->data=ele;
			temp->next=curr->next;
			curr->next=temp;
		      }
		    else
			cout<<"Element not found.\n";
	         }
	           else
		      cout<<"List Empty.\n";
        }

// >>>>>>>>>>>>>>>>>>> INSERTION BEFORE A PERTICULAR ELEMENT  <<<<<<<<<<<<<<<<<<<<<<<<  

    void l_list:: Insert_Before(int ele , int sele)
        {
           if (l!=NULL)
            {
                if (l->data == sele)
                 {
                  struct node *temp;
                  temp = new node;
                  temp ->data=ele;
                  temp->next=l;
                  l=temp;
                  
                 } 
             else
              {
             	struct node *curr;
                curr=l;
                     while(curr->next !=NULL && curr ->next -> data != sele)
                     curr = curr->next; 
                    if( curr ->next != NULL)
                      {
                        struct node *temp;
                        temp = new node;
                        temp ->data=ele;
                        temp->next=curr ->next;
                        curr->next =temp;  
              
                      }
                   else
                         cout<<"element not found"<<endl;
             }
             }
               else 
                cout<<"empty list"<<endl;               
       }
       
      // >>>>>>>>>>>>>>>>>>> Traverse_Forword  <<<<<<<<<<<<<<<<<<<<<<<<  
      
    void l_list ::Traverse_Forword()
     {
 
         if (l!= NULL)
          {
           struct node *curr ;
           curr =l;
            while (curr !=NULL)
             {
               cout<<" > "<<curr ->data;
                curr=curr->next;
             }
         }
     
         else 
           cout<<"empty list"<<endl; 
                 
    }
// >>>>>>>>>>>>>>>>>>> DELETE FIRST ELEMENT  <<<<<<<<<<<<<<<<<<<<<<<<
  
    int l_list :: Delete_First()
     {
       int x =-999;
        if(l!=NULL)
         {
          struct node *temp;
          temp=l;
          x=temp->data;
          l=temp->next; 
          delete temp;
         }
     else 
      cout<<"list is empty"<<endl;
      return x;   
}
// >>>>>>>>>>>>>>>>>>> DELETE LAST ELEMENT  <<<<<<<<<<<<<<<<<<<<<<<<

  int l_list :: Delete_Last()
     {
	int x = -999;
	if(l!=NULL)
	{
		
		struct node *temp;
		if (l->next== NULL)
		{

			
			temp=l;
			x=temp->data;
			l=NULL;
			delete  temp;

			

		}    
		else
		{
			
			struct node *curr;
			curr=l;
			
			while(curr->next->next != NULL)
			{	
							
				curr=curr->next;
			}
			temp=curr->next;
		
			x=temp->data;
		
			curr->next=NULL;
			delete temp;

		}	
	}
	else 
	cout<<"empty list"<<endl;

	return x;

}   
// >>>>>>>>>>>>>>>>>>> DELETE SPECIFIC ELEMENT  <<<<<<<<<<<<<<<<<<<<<<<<

   void l_list :: Delete_specific(int ele)
    {
      if(l!=NULL)
       {
         if(l->data ==ele)
            {
              struct node *temp;
              temp=l;
              l=temp->next;
              delete temp;
           }
        else 
         {
             struct node *curr;
             curr=l;
             while(curr->next!=NULL && curr ->next->data != ele )
             curr =curr ->next;
            if(curr ->next != NULL)
             {
                struct node *temp;
                temp=curr->next;
                curr->next =temp ->next;
                delete temp;
            }
          else 
            cout <<"Element not found"<<endl;
            
        }
   }
   else 
     cout <<"list is empty"<<endl;
 }
 // >>>>>>>>>>>>>>>>>>> PRINT BACKWORD  <<<<<<<<<<<<<<<<<<<<<<<<
  void print (struct node *curr)
   {
   
     if (curr ->next !=NULL)
     {
       print(curr ->next);
        cout<<">"<<curr->data;
     }
       
   }
   // >>>>>>>>>>>>>>>>>>> TRAVERSE BACKWORD  <<<<<<<<<<<<<<<<<<<<<<<<
 void l_list :: Traverse_Backword()
  {
    if (l!=NULL)
    {
     print(l);
    }
  }
  // >>>>>>>>>>>>>>>>>>> REVERSE   <<<<<<<<<<<<<<<<<<<<<<<<
  void l_list :: Reverse()
   {
    struct node *temp,*R;
    R=NULL;
    while(l!=NULL)
     {
      temp=l;
      l=temp->next;
      temp->next=R;
      R=temp;
     }
         l=R;
  }
// >>>>>>>>>>>>>>>>>>> DESTRUCTOR   <<<<<<<<<<<<<<<<<<<<<<<<
	l_list ::~l_list()
          {

		struct node *temp;
		while(l!=NULL)
		{
		temp=l;
		l=temp->next;
		delete temp;
		}

	}
	// >>>>>>>>>>>>>>>>>>> main  <<<<<<<<<<<<<<<<<<<<<<<<
	int main()
	{
		l_list p;
		p.Insert_Beg(2);
		p.Insert_Beg(10);
		p.Insert_Beg(20);
		p.Insert_Beg(100);
		p.Insert_After(5,2);
		p.Insert_End(6);
		p.Insert_Before(7,6);
		p.Delete_First();
		p.Delete_Last();
		p.Delete_specific(100);
		cout<<"link list is as shown below"<<endl;
		p.Traverse_Forword();
		p.Reverse();
		cout<<"reverse link list is as shown below"<<endl;
		p.Traverse_Forword();
		cout<<"link list backword travewrsing  is as shown below"<<endl;
		p.Traverse_Backword();


	}



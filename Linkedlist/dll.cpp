#include<iostream>
using namespace std;
struct node
     {
	int data;
	struct node *next,*prev;
     };
class dl_list
 {
   public:
   struct node *dl;
   void insert_beg(int);
   void insert_end(int);
   void  insert_after(int ,int);
  // insert_before();
   int delete_first();
   int delete_last();
   int delete_spec(int);
  void  travel_forward();
   void travel_backward();
   dl_list()
   {
   dl=NULL;
   }
  
  ~dl_list();
 
 };
 
 void dl_list ::insert_beg(int ele) 
    {
	 struct node *temp;
	 temp=new node;
	 temp->data=ele;
	 temp->prev = NULL;
	 temp->next =dl;
	 if(dl!=NULL)
	 dl ->prev = temp;
	 dl=temp;
 
   }
   
 void  dl_list :: insert_after(int ele,int sele)

          {
	        if(dl!=NULL)
	         {
		    struct node *curr;
		    curr=dl;
		        while(curr !=NULL&&curr->data!=sele)
			
			curr=curr->next;
			
		    if(curr!= NULL)
		      {
		        struct node *temp;
		        temp = new node;
			temp->data=ele;
			temp->next=curr->next;
			temp->prev=curr;
			if(curr ->next !=NULL)
			   curr->next->prev=temp;
			curr->next=temp;
			
		      }
		    else
			cout<<"Element not found.\n";
	         }
	           else
		      cout<<"List Empty.\n";
        }
   
 void dl_list :: insert_end(int ele)
 {
     struct node *temp;
     temp=new node;
     temp->data =ele;
     temp ->next=NULL;
     if(dl == NULL)
       {
           temp->prev =NULL;
           dl=temp;
       }
        
        else
          {
		struct node *curr;
		curr=dl;
		while(curr ->next !=NULL)
		curr =curr->next;
		temp->prev=curr;
		curr->next=temp;
          }
    
 }
 
 void dl_list::travel_forward()
     {
 
         if (dl!= NULL)
          {
           struct node *curr ;
           curr =dl;
            while (curr !=NULL)
             {
               cout<<" > "<<curr ->data<<endl;
                curr=curr->next;
             }
         }
     
         else 
           cout<<"empty list"<<endl; 
                 
    }
    
   int dl_list:: delete_first()
    {
        int x=-999;
        if(dl!=NULL)
        {
          struct node *temp;
          temp=dl;
          x=temp->data;
          dl=temp->next;
          if(temp->next != NULL)
          temp->next ->prev=NULL;
          delete temp;
          
        }
        else 
        cout<<"list is empty"<<endl;
        return x;
        
     }    
   
   int dl_list:: delete_last()
   {
        int x=-999;
        if(dl!=NULL)
         {
            struct node *curr;
            curr=dl;
              while(curr->next !=NULL)
                curr= curr ->next;
              x=curr->data;
                if(curr ->prev==NULL)
                  dl=NULL;
               else
               curr->prev->next=NULL;
               delete curr;
          }
          else 
            cout<<"list is empty "<<endl;
            return x;
   }
	 
    int dl_list :: delete_spec(int ele)
    {
     if(dl!=NULL);
      {
        struct node *curr;
        curr=dl;
          while(curr!=NULL && curr ->data!=ele)
            curr=curr->next;
         if (curr !=NULL)
          {
            if (curr ->prev!=NULL)
               curr->prev ->next =curr->next;
             else
                 dl=curr->next;
                 if (curr->next !=NULL)
                    curr->next ->prev= curr->prev;
               delete curr;
         }
            else
              cout<<"element not found"<<endl;
           }
        /*else 
            cout<<"list is empty"<<endl;*/
        
        }
        void dl_list :: travel_backward()
        {
             struct node *curr;
             curr =dl;
             while(curr ->next !=NULL)
             	curr=curr->next;
             while(curr!=NULL)
              {
                cout<<curr->data<<"<";
                curr=curr->prev;             
              }
        }
      dl_list ::~dl_list()
          {

		struct node *temp;
		while(dl!=NULL)
		{
		temp=dl;
		dl=temp->next;
		delete temp;
		}

	  }
	 int main()
 		{
        		dl_list p;
        		p.insert_beg(10);
        		p.insert_beg(20);
        		p.insert_beg(30);
        		p.insert_beg(40);
        		p.insert_beg(50);
        		p.insert_beg(60);
        		p.insert_end(70);
        		p.insert_after(80,10);
        		p.insert_after(90,80);
        		//p.delete_first();
        		//p.delete_last();
        		//p.delete_spec(10);
        		cout<<"linked list in forward direction ";
                        p.travel_forward();
                        cout<<"linked list in backward direction ";
                        p.travel_backward();
 		}
 

#include<iostream>
using namespace std;
struct node
{
int data;
struct node *left,*right;
};
void printI(node*);
void printPre(node*);
void printPost(node*);
int  nln(node*);
int nnln(node*);
void delete_tree(node*);
struct node* delete_ele(int,node*);
class BST
{
struct node *bst;
public:
BST();
~BST();
void insert(int);
void inorder();
void preorder();
void postorder();
int findmax(node*);
int findmin(node*);
int leafnodes();
int nonleaf();
int height(node*);
void delete_spec(int);
void mirror(node*);
struct node * delete_ele(int,node *);
friend void printI(node*);
friend void printPre(node*);
friend void printPost(node*);
friend int  nln(node*);
friend int nnln(node*);
friend void delete_tree(node*);

};
BST::BST()
{
bst=NULL;
}
void BST::inorder()
{
if(bst!=NULL)
printI(bst);
}
void printI(struct node *curr)
{
if(curr!=NULL)
{
printI(curr->left);
cout<<curr->data<<endl;
printI(curr->right);
}
}


void BST::preorder()
{
if(bst!=NULL)
printPre(bst);
}
void printPre(struct node *curr)
{
if(curr!=NULL)
{
cout<<curr->data<<endl;
printI(curr->left);
printI(curr->right);
}
}
void BST::postorder()
{
if(bst!=NULL)
printPost(bst);
}
void printPost(struct node *curr)
{
if(curr!=NULL)
{
printI(curr->left);
printI(curr->right);
cout<<curr->data<<endl;
}
}
int BST::findmax(struct node* curr)
{
int x=-999;
if(curr!=NULL)
{
while(curr->right!=NULL)
curr=curr->right;
x=curr->data;
}
return x;
}
int BST::findmin(struct node *curr)
{
int x=-999;
if(curr!=NULL)
{
while(curr->left!=NULL)
curr=curr->left;
x=curr->data;
}
return x;
}
int BST::height(struct node *curr)
{
if(curr==NULL)
return -1;
if(curr->left==NULL && curr->right==NULL)
return 0;
return(max(height(curr->right),height(curr->right))+1);
}
int BST::leafnodes()
{
if(bst!=NULL)
return(nln(bst));
else
return 0;
}
int nln(struct node *curr)
{
if(curr==NULL)
return 0;
if(curr->left==NULL && curr->right==NULL)
return 1;
return(nln(curr->left)+nln(curr->right));
}
int BST::nonleaf()
{
if(bst!=NULL)
return(nnln(bst));
else
return 0;
}
int nnln(struct node *curr)
{
if(curr==NULL)
return 0;
if(curr->left==NULL && curr->right==NULL)
return 1;
return(nnln(curr->left)+nln(curr->right)+1);
}
void BST::insert(int ele)
{
struct node *temp;
temp=new node;
temp->data=ele;
temp->left=temp->right=NULL;
if(bst==NULL)
bst=temp;
else
{
struct node *curr;
curr=bst;
while(1)
{
if(ele<curr->data)
{
if(curr->left==NULL)
{
curr->left=temp;
break;
}
else
curr=curr->left;
}
else
{
if(curr->right==NULL)
{
curr->right=temp;
break;
}
else
curr=curr->right;
}
}
}
}
void BST::delete_spec(int ele)
{
if(bst!=NULL)
bst=delete_ele(ele,bst);
else
cout<<"tree empty";
}
struct node * BST ::delete_ele(int ele,struct node *curr)
{
		if(curr!=NULL)
		{
			if(ele>curr->data)
				curr->right=delete_ele(ele,curr->right);
			else
      {
				if(ele<curr->data)
					curr->left=delete_ele(ele,curr->left);
				else
				{
								if(curr->left!=NULL && curr->right!=NULL)
								{
									curr->data=findmax(curr->left);
									//curr->data=findmin(curr->right);
									curr->left=delete_ele(curr->data,curr->left);
								}
								else
								{
									struct node *temp;
									temp=curr;
									if(curr->left!=NULL)
										curr=curr->left;
									else
										curr=curr->right;
									delete temp;
								}
				}
     }
   }
else
cout<<"element not found";
return curr;
}
/*void BST::mirror(struct node *curr)
{
if(curr==NULL || (curr->left==NULL && curr->right==NULL)
         ;
else
{
struct node *temp;
temp=curr->left;
curr->left=curr->right;
curr->right=temp;
mirror(curr->left);
mirror(curr->right);
}
}*/

BST::~BST()
{
if(bst!=NULL)
delete_tree(bst);
}
void delete_tree(struct node *curr)
{
if(curr!=NULL)
{
delete_tree(curr->left);
delete_tree(curr->right);
delete curr;
}
}

int main()
{
BST b;

b.insert(36);
b.insert(4);
b.insert(50);
b.insert(65);
b.insert(17);
b.insert(38);
b.insert(14);
b.insert(11);
b.insert(25);
b.insert(7);
b.insert(18);


int nln;
nln=b.leafnodes();
cout<<"no.of leaf nodes:"<<nln<<endl;
int nnln;
nnln=b.nonleaf();
cout<<"no. of non leaf nodes:"<<nnln<<endl;
cout<<"inorder\n";
b.inorder();
cout<<"postorder\n";
b.postorder();
b.delete_spec(36);
cout<<"preorder\n";
b.preorder();

}







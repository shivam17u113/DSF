#include<iostream>
using namespace std;

class node
{
	node *left;
	node *right;
	int data,lth,rth;
	public:
	friend class BST;	
	
};

class BST
{
	node *top, *dummy;
	
	public:
		
		BST()
		{
			top=NULL;
			dummy=NULL;
		}
		
		void insert(node *top,node *newnode)
		{
			if(newnode->data<top->data)
			{
				if(top->lth==0)
				{
					newnode->left=top->left;
					top->left=newnode;
						newnode->right=top;
					top->lth=1;
				
				}
				else
				insert(top->left,newnode);
			}
			else if(newnode->data>top->data)
			{
				if(top->rth==0)
				{
				newnode->right=top->right;
				top->right=newnode;
				newnode->left=top;
				top->rth=1;	
					
				}
				else
				insert(top->right,newnode);
				
			}
	
		else
		cout<<"duplicate data insertded  ";	
				
			}
	
		
		
	void create()
	{
		node *newnode= new node;
			newnode->left=NULL;
			newnode->right=NULL;
			cout<<" enter the data  ";
			cin>>newnode->data;
			newnode->lth=0;
			newnode->rth=0;

		if(top==NULL)
		{
			top=newnode;
			dummy= new node;
			dummy->data=-999;
			dummy->lth=dummy->rth=0;
			dummy->left=NULL;
			dummy->right=NULL;
			top->left=top->right=dummy;
		}
		else
		{
           
	insert(top,newnode);
	}
}
	
	
	node *returntop()
	{
		return top;
	}
// 1FOR CHILRD  0 FOR LINK
	void display(node *top)
	{
		while(top!=dummy)
		{
			while(top->lth==1)
			{
				top=top->left;
			}
			cout<<top->data<<"\t";
			while(top->rth==0)
			{
				top=top->right;
			if(top==dummy)
			return;
			cout<<top->data<<"\t";
			
			}
			top=top->right;
				
		}
		
	}
	
	
};

int main()
{
	int h,c;
	node *top;
	top=NULL;
	BST b1;
	for(int i=0;i<5;i++)
	{
		b1.create();
	}
	
	node *temp=b1.returntop();
	b1.display(temp);
	return 0;
}

//  2     7       10      15      20       no of nodes   5 height of the tree   3









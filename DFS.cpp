#include<iostream>
using namespace std;

class node
{
	node *left;
	node *right;
	int data;
	public:
	friend class BST;	
	
};

class BST
{
	node *top;
	
	public:
		
		BST()
		{
			top=NULL;
			
		}
		
		void insert(int value)
		{
			node *newnode= new node;
			newnode->left=NULL;
			newnode->right=NULL;
			newnode->data=value;
			
			if(top==NULL)
			{
				top=newnode;
					
			}
			else
			{
				node *temp,*move;
				temp=top;
			while(temp!=NULL)
			{
				move=temp;
				if(newnode->data<temp->data)
				temp=temp->right;
				
				else
				temp=temp->left;
				}	
				if(newnode->data>move->data)
				move->left=newnode;
				else
				move->right=newnode;
				
				
			}
	
		}
		
	void inorder( node *top)
	{
		if(top!=NULL)
		{
		inorder(top->left);
		cout<<top->data<<"\t";
		inorder(top->right);	
			
			
		}	
	}
	
	node *returntop()
	{
		return top;
	}

	void print(node *top)
	{
		cout<<top->data;
		cout<<top->left->data;
		cout<<top->right->data;
	
	}
	


	
void swaptree(node *root )
{
     node *temp=root,*swaplr;
    if(root)
    {
    swaptree(temp->left);
    swaptree(temp->right);
    swaplr=temp->left;
    temp->left=temp->right;
    temp->right=swaplr;
return ;


    }

}
	
	
};

int main()
{
	int h,c,val,ch,v;
	node *top;
	top=NULL;
	BST b1;
cout<<"\n\n";
cout<<" \n\n please note if you want to stop then please enter 0  \n\n";
do
{
cout<<"\n enter the next value    ";
cin>>ch;

if(ch==0)
break;
b1.insert(ch);
}while(ch!=0);




top=b1.returntop();
	//b1.print(top);
	cout<<"\n\n  ";
	b1.inorder(top);
	
	b1.swaptree(top);

	cout<<"after swapping";
	b1.inorder(top);
	




	return 0;
}










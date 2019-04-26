//============================================================================
// Name        : EXPRE.cpp
// Author      : shivam parve
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
using namespace std;

class treenode
{
private:
	char exp;
	treenode *left;
	treenode *right;

public:
	friend class stack1;
	treenode()
{
		exp='0';
		left= right= NULL;

}

	treenode* assign( char ch, treenode * l, treenode *r)
	{
		treenode *item= new treenode;
		item->exp=ch;
		item->left=l;
		item->right=r;

		return item;
	}




};

class node
{
public:
	friend class stack1;
private:
	treenode *data;
	node*next;
};

class stack1
{
private:
	node* top;

public:
	stack1()
	{
			top=NULL;
	}
void push(treenode *temp)
   {
			node *newnode = new node;
			newnode->data=temp;
			newnode->next=NULL;

if(top==NULL)
		{
		top=newnode;

		}

else
		{
		newnode->next=top;
		top=newnode;

		}
   }

treenode *pop()
{
	node *temp;
	temp=top;
	top=temp->next;

	treenode *tn;
	tn=NULL;
	tn= temp->data;

	delete temp;

	return tn;
}

void inorder(treenode *root)
{
	stack<treenode *>s;
	while(root || s.empty()==false)
	{
	while(root)
	{
		s.push(root);
		root=root->left;
		}		

	root=s.top();
	s.pop();
	cout<<root->exp;
	root=root->right;
   }	
}
void preorder( treenode *root)
{
	stack<treenode *>s;
	
	while(root || s.empty()==false)
	{
	while(root)
	{
		s.push(root);
		cout<<root->exp;
		root=root->left;
		}
		root=s.top();
		s.pop();		
root=root->right;


   }
		
}

treenode *returntop()
{
	
	return top->data;
	cout<<" top returnend  " <<top->data;
}



};


int main()
{

int i=0;
	char ch;
int ch1;
	stack1 s1;
	treenode *tn,*r,*l,t;
	
	string str;
	cout<<"\n enter the expression   ";
	cin>>str;

	while(str[i]!='\0')
	{
		ch=str[i];

		if(ch != '+' && ch != '-' && ch != '/' && ch != '*') 
		{
			tn= t.assign(ch,NULL,NULL);
			s1.push(tn);
   
		}
		else 
		{
			r=s1.pop();
			l=s1.pop();
			tn= t.assign(ch,l,r);
			s1.push(tn);
       
		}
i++;
}
		

	

treenode *move;
move=s1.returntop();
cout<<"     "<<endl;


do
{
	cout<<"\n 1. inorder \n 2. preorder \n 0.exit   ";
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			cout<<"\n inorder expression    ";
			s1.inorder(move);
			break;
		case 2:
			cout<<"\n preorder expression   ";
			s1.preorder(move);
				break;
	
	}
	
}while(ch1!=0);


	return 0;
}



// output
/*
enter the expression   ab+c*d-


 1. inorder
 2. preorder
 3. postorder
 0.exit   1

 inorder expression    a+b*c-d
 1. inorder
 2. preorder
 3. postorder
 0.exit   2

 preorder expression   -*+abcd
 1. inorder
 2. preorder
 3. postorder
 0.exit   3

 pst order expression    ab+c*d-
 1. inorder
 2. preorder
 3. postorder
 0.exit   0

--------------------------------
Process exited after 25.37 seconds with return value 0
Press any key to continue . . .


*/

































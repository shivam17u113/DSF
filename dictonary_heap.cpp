
#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
 
node *left;
node*right;
string word;
string meaning;	

}node;

class avl
{
	public:
		
	int diff(node*temp);
  node* balance(node *temp);
	node*LL(node *parent);
	node*LR(node *parent);
	node*RR(node *parent);
	node*RL(node *parent);
	node*insert(node*root, string value, string mean);
	int height(node *temp);
	void display(node *root);
	void display_rot(node *root);
	void update(node*root, string key);
	int search(node*root, string key);
	
};

 node* avl::insert(node *root, string value, string mean)
{
	if(root==NULL)
	{
		root= new node;
		root->word=value;
		root->meaning=mean;
		root->left=root->right=NULL;
		return root;
		
	}
	
	else if((value.compare(root->word))<0)
	     {
	     	root->left=insert(root->left,value,mean);
	     	root=balance(root);
	     	
		 }
	
	if((value.compare(root->word))>0)
	     {
	     	root->right=insert(root->right,value,mean);
	     	root=balance(root);
	     	
		 }
		 
		 
		 return root;
		
}
node*  avl::balance(node*temp)
{
	int bal_f;
    bal_f=diff(temp);
    
    if(bal_f>1)
    {
    	if(diff(temp->left)>0)
    	   temp=LL(temp);
    	   else
    	   temp=LR(temp);
    	
    	
    	
	}
	else if(bal_f<-1)
	{
		if(diff(temp->right)>0)
		   temp=RL(temp);
		   
		else
		temp=RR(temp);
		
	}
	
	return temp;
	
}

int avl::diff(node *temp)
{
	int max;
	int l= height(temp->left);
	int r= height(temp->right);
	
	max=l-r;
	return max;
	
	
}

int avl::height(node *temp)
{
 int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
	
}

node* avl::LL(node *parent)
{
	node* temp;
	temp=parent->left;
	parent->left=temp->right;
	temp->right=parent;
	
	return temp;
		
		
	
}

node* avl:: LR(node *parent)
{
	node *temp;
	temp=parent->left;
	
	parent->left=RR(temp);
	return LL(parent);
	
	
}


node* avl::RR(node *parent)
{
	node *temp=parent->right;
	parent->right=temp->left;
	temp->left=parent;
	
	return temp;
	
	
	
}
node* avl::RL(node* parent)
{
	node*temp=parent->right;
	parent->right=LL(temp);
	
	return RR(parent);
	
	
}

void  avl::display(node *root)
{

	if(root)
	{
	
		display(root->left);
		cout<<"the word  "<<root->word<<"means   "<<root->meaning<<endl;
		display(root->right);
		
		
	}
	
}


void  avl::display_reverse(node *root)
{

	if(root)
	{
	display(root->right);

		cout<<"the word  "<<root->word<<"means   "<<root->meaning<<endl;
				display(root->left);
		
		
	}
	
}


void avl::display_rot(node *root)
{
	node *l,*r;
	l=root->left;
	r=root->right;
	
	cout<<" the left of root is"<<endl; 
	cout<<"the word  "<<l->word<<"means   "<<l->meaning<<endl;
	
/*	cout<<" the right of root is"<<endl; 
	cout<<"the word  "<<r->word<<"means   "<<r->meaning<<endl;*/
	
}
void avl::update(node *root, string key)
{
	int k= search(root,key);
	if(k==1)
	{
		cout<<"updated susseccfully";
		
	}
	if(k==0)
	{
		cout<<"word not exist";
	}
	
	
	
}

int avl::search(node *root ,string key)
{
	string s;
	if(root==NULL)
	   return 0;
	   
	   if(key.compare(root->word)==0)
	   {
	   	cout<<"enter the new meaning";
	   	cin>>s;
	   	root->meaning=s;
	   	return 1;
	   	
	   }
	   else if((key.compare(root->word))<0)
	        search(root->left,key);
	        
	        else if((key.compare(root->word))>0)
	               search(root->right,key);
	
	
	
}


int main()
{
	int ch;
	avl a;
	string v,m,s;
	
	node*rt=NULL;
	
	do{
		cout<<"1.insert \n 2.display \n 3.update\n 4. display reverse \n0.exit";
		cin>>ch;
		
		switch(ch)
		{
				case 1:
		cout<<"enter the string and meaning";
		cin>>v;
		cin>>m;
	  rt=a.insert(rt,v,m);
	 
		break;
		case 3:
			
			cout<<"entet the key whose meaning to change";
			cin>>s;
		a.update(rt,s);
		break;
		case 2:
		
				a.display(rt);
			break;
			case 4:
				a.display_reverse(rt);
		
		}
	
		
		
	}while(ch!=0);
	
	return 0;
	
}



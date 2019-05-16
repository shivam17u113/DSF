#include<iostream>
#include<string.h>

using namespace std;

typedef struct node
{
string word;
string meaning;
node *left,*right;

	
}node;

class avl
{ 

	public:
	
		node* balance(node *root);
		node*RR(node *parent);
		node*LR(node *parent);
		node*LL(node *parent);
		node*RL(node *parent);
      void display(node *root);
      	void display_rot(node *root);
      	

	node* read(node*root, string m ,string w)
	{
		if(root==NULL)
		{
			root = new node;
			root->word=w;
			root->meaning=m;
			root->left=NULL;
			root->right=NULL;
			
			return root;
		}
		else if(root!=NULL)
		{
			if((w.compare(root->word))>0)
			  {
			  	root->right= read(root->right,m,w);
			  	  root=balance(root);
			  }
          else if((w.compare(root->word))<0)
			  {
			  	root->left= read(root->left,m,w);
			  	  root=balance(root);
			  }   			
				
		}
		return root;
		
	}
	
	int diff(node *root)
	{
		int l_h;
		int r_h;
	
		l_h=Height(root->left);
		r_h=Height(root->right);
		
		return l_h-r_h;
		
		}	
	
	
	int Height(node *root)
	{
		
		if(root==NULL)
		return 0;
		
		else
		{
			int l_h= Height(root->left)+1;
			int r_h=Height(root->right)+1;
			
			if(l_h>r_h)
			return l_h;
			else
			return r_h;	
		}	
	}
	
	void update1(node *root, string key)
	{
		 string m;
		if(root==NULL)
		{
		return ;
		}
		
		if((key.compare(root->word))==0)
		{
			cout<<"enter the new  meaning";
			cin>>m;
			root->meaning=m;
			return ;
			
		}
		else
		{
			if((key.compare(root->word))>0)
                update1(root->right,key);
				
			if((key.compare(root->word))<0)	
			    update1(root->right,key);			
			
		}
		
		cout<<"key not fount";
		
	}
	
	node *delete1(node *root, string v)
	{
		if(root==NULL)
		   return NULL;
		   
		 
		    else if((v.compare(root->word))>0)
		  	{
		  		root->right=delete1(root->right,v);
		  		    root= balance(root);
		  		
			  }
		 else if((v.compare(root->word))<0)
		{
				root->left=delete1(root->left,v);
		  		    root= balance(root);
			
		}
	
	else
	{
		
		
		
	if(root->right!=NULL)
	{
		
		node *p=NULL;
		p=root->right;
		
		while(p->left!=NULL)
		   p=p->left;
		
		root->word=p->word;
		root->meaning=p->meaning;
		
		root->right=delete1(root->right,p->word);
		
		root=balance(root);
		
		}	
		else
		   return(root->left);
		
		
		
		}
		
	
		return root;	
		
	}
		
};

void  avl::display(node *root)
{

	if(root)
	{
	
		display(root->left);
		cout<<"the word  "<<root->word<<"means   "<<root->meaning<<endl;
		display(root->right);
		
		
	}
	
}
node* avl::balance(node *root)
{
	int bal;
	bal= diff(root);
	
	if(bal>1)
	{
		if(diff(root->left)>0)
           	root=LL(root);
        else
           	root=LR(root);
         
	}
	
	if(bal<-1)
	{
		if(diff(root)>0)
         root=   RL(root);
			else
		root=	RR(root);		
		
	}
	
	return root;
	
	}


node* avl::LR(node *parent)
	{
		node*temp=parent->left;
		parent->right=RR(temp);
		
		return LL(parent);
		
	}
node * avl::RL(node *parent)
	{
		node*temp=parent->right;
		parent->right=LL(temp);
		
		return RR(parent);
		
	}	
	
node*avl::RR(node *parent)
	{
		node *temp;
		temp=parent->right;
		parent->right=temp->left;
		temp->left=parent;
		
		return temp;
	}
		node* avl::LL(node *parent)
	{
		node *temp;
		temp=parent->left;
		parent->left=temp->right;
		temp->right=parent;
		
		return temp;
	}
	
	void avl::display_rot(node *root)
{
	display_rot(root->right);
	cout<<"the word  "<<root->word<<"means   "<<root->meaning<<endl;
	display_rot(root->right);
	
}

  
int main()
{
	avl l;
	node *root=NULL;
	string w,m,key;
	int ch;
	do
	{
		cout<<"\n 1.insert \n 2.display \n3.update \n 4. delete \n0.exit ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"enter the word"; cin>>w;
				cout<<"enter its meaning "; cin>>m;
				root=l.read(root,m,w);
			    
			    
			     break;
		
		   case 2:
		   	l.display(root);
		   	break;
		   	case 3:
		   		cout<<"enter the  word whose meaning to be updated ";
		   		cin>>key;
		   		l.update1(root,key);
		   		break;
		   		
		   		case 4:
		   			cout<<"enter the key to be deletd   ";
		   			cin>>key;
		   			root=l.delete1(root,key);
		   				cout<<"after return ning the root data is "<<root->word<<"   "<<root->meaning<<endl<<endl;
		   			break;
		}
		
		
	}while(ch!=0);
	
	
	
	return 0;
}

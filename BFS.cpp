#include<iostream>
#include<queue>
using namespace std;

class list
{
	list*next;
	public:
			int data;
		friend class Alist;
};

class Alist
{

int visited[20];
	
int n_e,n_v;	
int start_v,end_v;

public:
	Alist()
	{
	
	}
	list *G[20];
	void create()
	{
		
		
		cout<<"enter the number of vertices :"; cin>>n_v;
		for(int i=0; i<n_v;i++)
		     G[i]=NULL;
		
	cout<<"enter the number of edges :"; cin>>n_e;
	for(int i=0; i<n_e;i++)
 {
		cout<<"\n enter the edge (stating vertex, ending vertex)"<<endl;
		cin>>start_v;cout<<" ";cin>>end_v;
	

			
	list*newnode,*move;
	newnode= new list;
	newnode->data=end_v;
	newnode->next=NULL;
	
	if(G[start_v]==NULL)
	{
		list*temp = new list;
		temp->data=start_v;
		temp->next=NULL;
		 G[start_v]=temp;
	}
	   
	if(G[start_v]!=NULL)
	{
	    move=G[start_v];
					while(move->next!=NULL)
					{
						move=move->next;	
					}
	    
		
	move->next=newnode;	
		
	}	
				
 }
		
}

void dsf(int i)
{
	
	
	list*p;
	cout<<i<<endl;
	visited[i]=1;
	p=G[i];
	
	while(p!=NULL)
	{
	 i=p->data;
		if(!visited[i])
           dsf(i);
		   p=p->next;		
	}
	
	
}
void print()
{
	list *move;
	move=NULL;
	
	for(int i=0; i<n_v;i++)
	{
		move=G[i];
		
		while(move!=NULL)
		{
			cout<<move->data<<"  ";
			move=move->next;
		}
		cout<<"\n\n";
		
		
		
	}
	
	
	
}

  void BFS(int v)
{
		for(int l=0; l<n_v;l++)
	{
		visited[l]=0;// V
		
	}
	
//	cout<<g[3]->next->next->data<<endl;
int value;
queue<int>q;

list*p;

q.push(v);
cout<<"\n visit"<<v<<endl;
visited[v]=1;

	while(q.empty()==false)// V
	{
		v=q.front();
		//cout<<"the value of v "<<v<<endl;
		
		q.pop();
		
		for(p=G[v];p!=NULL;p=p->next) // 2E
		{
		//	cout<<"in for loop"<<endl;
			value=p->data;
			if(visited[value]==0)
			{
				q.push(value);
				visited[value]=1;
			//	cout<<visited[4]<<" the value of visted 4"<<endl;
				cout<<"\n visit"<<value<<endl;
			}
			
		}
	//	cout<<endl<<q.front()<<"afrer for loop"<<endl;
		
		
	}
	
	
	
	
	
	
}



};

 int main()
 {
 	Alist a;
 	list b;
 	a.create();
 	list *temp;
 	temp= a.G[0];
 	cout<<"***"<<endl;
 	a.BFS(temp->data);
 	cout<<endl;
 		cout<<"***"<<endl;
 a.print();
 	return 0;
 	
 	
 }






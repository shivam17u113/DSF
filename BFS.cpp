#include<iostream>
using namespace std;
class node_queue
{
int data;
node_queue * next;
public:
node_queue()
{
data=-1;
next=NULL;
}
friend class queue_non;
};
class queue_non
{
node_queue *front;
node_queue *rear;
public:
queue_non()
{
front=NULL;
rear=NULL;
}
void push(int value)
{
node_queue * newnode= new node_queue ;
newnode->data=value;
newnode->next=NULL;
	if(front==NULL)
	rear=front=newnode;
		else
		{
		rear->next= newnode;
		rear=newnode;
		}
}
bool empty()
{
if(front ==NULL)
  return true;
else
return false;

}

int pop()
{
int d;
node_queue *move= front;

d= move->data;
front=move->next;
delete move;
return d;
}
};




class node
{

public:
int data;
node *next;
 node()
	{
	data=-1;
	next=NULL;
	}
friend class bfs;
 };

class bfs
{
int n_v,n_e,u,v;

int visited[20];


public:
node *G[20];
bfs()
{
cout<<"enter the totoal no of vertices  ";
cin>>n_v;
cout<<" enter no of edges ";
cin>>n_e;
		for(int i=0;i<n_v;i++)
		{
		G[i]=NULL;
		visited[i]=0;
		}
  }
node *assign(int v)
{
node *newnode= new node;
newnode->data=v;
newnode->next=NULL;
return newnode;

}

void accept()
{
for(int i=0;i<n_e;i++)
{

cout<<"enter the stating vertex  ";
cin>>u;
cout<<"enter the ending vertex  ";
cin>>v;

node * newnode1=new node;
node * newnode2=new node;
newnode1->data=u;
newnode2->data=v;
newnode1->next=newnode2->next=NULL;
if(G[u]==NULL)
	{
	G[u]=newnode1;
        // cout<<"top created with"<<G[u]->data<<endl;
	}
	if(G[u]!=NULL)
	{
	node *temp;
	temp=G[u];
while(temp->next!=NULL)
     temp=temp->next;
	
temp->next=newnode2;
//cout<<"data    "<<newnode2->data<<" inserted at    "<<G[u]->data<<endl;

	}

     }
}
void display()
{
cout<<"in display";
for(int i=0;i<n_v;i++)
{
node *move=G[i];
while(move!=NULL)
     {
           cout<<move->data<<"   ";
            move=move->next;
      }
  cout<<"\n";  
   }
}

void non(int v)
{
for(int i=0;i<n_v;i++)
   visited[i]=0;


queue_non q;
q.push(v);
visited[v]=1;
cout<<"visit"<<v<<endl;
while(!q.empty())
{
//cout<<"inside while"<<endl;
v=q.pop();

//cout<<"the poped elelemt is"<<v<<endl;
for(node *move=G[v]; move!=NULL;move=move->next)
    {
int value= move->data;
//cout<<"inside for loop "<<endl;
		if(visited[value]==0)
		{
		cout<<"visit  "<<value<<endl;
		visited[value]=1;
		q.push(value);
		}
         }
    }
}
};

int main()
{
int ch;
bfs b;
b.accept();

b.display();
node *p=b.G[0];
int d=p->data;
cout<<"by user  "<<endl;
b.non(d);

}


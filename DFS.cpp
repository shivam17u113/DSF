#include<iostream>

using namespace std;

class node_stack 
{
int data;
node_stack *next;

public:
node_stack()
{
data=0;
next=NULL;
}
friend class stack_non ;
};
class stack_non
{
node_stack *top;

public:
stack_non()
{
top=NULL;
}

void push(int value)
   {
node_stack *newnode= new node_stack;
newnode->data=value;
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
bool empty()
{
if (top==NULL)
  return true;
else 
  return false;


}

int pop()
{

if(top==NULL)
return -1;
node_stack *move=top;
int d= move->data;
top=move->next;
delete move;
return d;
}


};




class node
{
int visited[100];
int arr[100][100];
int n,u,v,e;
public:
node()
{
cout<<"enter the no of nodes  ";
cin>>n;
cout<<"enter the no of  edges  ";
cin>>e;

for(int i=0;i<n;i++)
     {
             visited[i]=0;
		for(int j=0;j<n;j++){
		       arr[i][j]=0;
		}
       }
}

void accept()
{
for(int i=0;i<e;i++)
	{
	
	cout<<"enter the starting and ending vertex  ";
	cin>>u;
	cin>>v;
	arr[u][v]=arr[v][u]=1;

	}
}

void dfs(int v)
 {
cout<<"visit "<<v;
visited[v]=1;
	for(int i=0;i<n;i++)
	{
	if(visited[i]==0 && arr[v][i]==1)
	    dfs(i);
	}
 }

void non_dfs(int v)
{
stack_non s;
s.push(v);

while(!s.empty())
{
v=s.pop();


if(visited[v]==0)
 {
cout<<"visit  "<< v<<endl;
visited[v]=1;
	for(int i=0;i<n;i++)
	{
	if(visited[i]==0 && arr[v][i]!=0)
	    s.push(i);
	}
  }


}




}


};

int main()
{
node b;
b.accept();
b.non_dfs(0);

return 0;
}


